
#include	<cassert>
#include	<sstream>
#include	"RoomException.h"
#include	"PackMan.h"
#include	"CSRequest.h"

Connect::Connect(std::string const& usr, std::string const& passwd) :
  ec(Success)
{
	PackMan::Memcpy(parameters.username, usr.data(), usr.size());
	PackMan::Memcpy(parameters.passwd, passwd.data(), passwd.size());
}

Connect::Connect(std::string &data)
{
  PackMan::Memcpy(&(this->parameters), data.data(), data.size());
  ec = Success;
}

Connect::~Connect() {}

bool		Connect::isValid()
{
  RoomManager&	RM = Resources::RM;
  std::string	username(parameters.username);

  if (RM.getPlayerFromName(username) == 0)
    return true;
  return false;
}

void		Connect::doOp()
{

}

void		Connect::doOp(IService* S)
{
  RoomManager&	RM = Resources::RM;
  std::string	username(parameters.username);
  std::string	password(parameters.passwd);

  RM.addPlayerToHall(username, password, S);
}

void		Connect::finalize(IService *S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		Connect::manageRequest(IService *S) 
{
  if (this->isValid())
    this->doOp(S);
  else
    this->ec = S_access_refused;
  this->finalize(S);
  return true;
}

std::string	Connect::toString()
{
  return (std::string(this->parameters.username) + ":" + std::string(this->parameters.passwd));
}

eRequestType	Connect::getType()
{
  return CONNECT;
}

Connect::parameter&  Connect::getParam()
{
  return this->parameters;
}

CreateRoom::CreateRoom() :
  ec(Success)
{
}
CreateRoom::CreateRoom(std::string &)
{
  ec = Success;
}

CreateRoom::~CreateRoom() {}

bool		CreateRoom::isValid()
{
  return true;
}

void		CreateRoom::doOp()
{
}

void		CreateRoom::doOp(IService* S)
{
  RoomManager&	RM = Resources::RM;
  int		idRoom;

  if((idRoom = RM.createRoom()) == -1)
    this->ec = S_cmd_refused;
  else
    {
      IRequest*	req = new AnswerCreateRoom(idRoom);
      S->push(req);
    }
}
void		CreateRoom::finalize(IService* S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		CreateRoom::manageRequest(IService *S)
{
  if (this->isValid())
    this->doOp(S);
  else
    this->ec = G_invalid_request;
  this->finalize(S);
  return (true);
}

std::string	CreateRoom::toString()
{
  return (std::string("CreateRoom", 10));
}

eRequestType	CreateRoom::getType()
{
  return CREATE_ROOM;
}

LeaveRoom::LeaveRoom(int roomId) :
  ec(Success), P(0)
{
  parameters.roomId = roomId;
}

LeaveRoom::LeaveRoom(std::string &data)
	: P(0)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  static_cast<size_t>(data.length()));
  ec = Success;
}

LeaveRoom::~LeaveRoom() {}

bool		LeaveRoom::isValid()
{
  return true;
}

void		LeaveRoom::doOp()
{

}

void		LeaveRoom::doOp(IService * S)
{
  RoomManager&	RM = Resources::RM;

  RM.removePlayerFromRoom(this->P->getId(), parameters.roomId);
  RM.addPlayerToHall(this->P->getName(), this->P->getHash(), S);
}

void		LeaveRoom::finalize(IService* S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		LeaveRoom::manageRequest(IService *S)
{
  RoomManager&	RM = Resources::RM;

  this->P = RM.getPlayerFromRoom(S, parameters.roomId);

  if (this->isValid())
    this->doOp(S);
  else
    this->ec = G_invalid_request;
  this->finalize(S);
  return (true);
}

std::string	LeaveRoom::toString()
{
  std::stringstream ss;

  ss << this->parameters.roomId;
  return (ss.str());
}

eRequestType	LeaveRoom::getType()
{
  return LEAVE_ROOM;
}

LeaveRoom::parameter&  LeaveRoom::getParam()
{
	return this->parameters;
}

JoinRoom::JoinRoom(int roomId) :
  ec(Success), P(0)
{
  parameters.roomId = roomId;
}

JoinRoom::JoinRoom(std::string &data)
	: P(0)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  data.size());
  ec = Success;
}

JoinRoom::~JoinRoom() {}

bool		JoinRoom::isValid()
{
  RoomManager&	RM = Resources::RM;

  if (RM.getRoomById(parameters.roomId) == NULL)
    return false;
  return true;
}

void		JoinRoom::doOp()
{
  RoomManager&	RM = Resources::RM;

  RM.clonePlayerFromHallToRoom(parameters.roomId, this->P->getId());
}

void		JoinRoom::finalize(IService* S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		JoinRoom::manageRequest(IService *S)
{
  RoomManager&	RM = Resources::RM;
  
  this->P = RM.getPlayerFromHall(S);

  if (this->isValid())
    this->doOp();
  else
    this->ec = G_invalid_request;
  this->finalize(S);
  return (true);
}

std::string	JoinRoom::toString()
{
  std::stringstream ss;

  ss << this->parameters.roomId;
  return (ss.str());
}

eRequestType	JoinRoom::getType()
{
  return JOIN_ROOM;
}

JoinRoom::parameter&  JoinRoom::getParam()
{
	return this->parameters;
}

InvitePlayer::InvitePlayer(char* u) :
  ec(Success), P(0)
{
  std::string usr(u);
  PackMan::Memcpy(this->parameters.username, usr.data(), usr.size());
}

InvitePlayer::InvitePlayer(std::string &data)
	: P(0)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  data.size());
  ec = Success;
}

InvitePlayer::~InvitePlayer() {}

bool		InvitePlayer::isValid()
{
  RoomManager&	RM = Resources::RM;
  std::string	username(parameters.username);

  if ((this->P = RM.getPlayerFromName(username)) == NULL)
    return false;
  return true;
}

void		InvitePlayer::doOp()
{
  
}

void		InvitePlayer::doOp(IService* S)
{
  RoomManager&	RM = Resources::RM;
  IPlayer*	P = RM.getPlayerFromService(S);
  int		id = RM.getRoomIdFromPlayer(P);
  IRequest	*req = new ClientInvited(P->getName(), id);

  S->push(req);
}

void		InvitePlayer::finalize(IService* S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		InvitePlayer::manageRequest(IService *S)
{
  if (this->isValid())
    this->doOp(S);
  else
    this->ec = S_cmd_refused;
  this->finalize(S);
  return (true);
}

std::string	InvitePlayer::toString()
{
  return std::string(this->parameters.username);
}
eRequestType	InvitePlayer::getType()
{
  return INVITE_PLAYER;
}

InvitePlayer::parameter&  InvitePlayer::getParam()
{
	return this->parameters;
}

SetGameParam::SetGameParam(std::string &param) :
  ec(Success)
{
  PackMan::Memcpy(this->parameters.param, param.data(),  param.size());
}

SetGameParam::~SetGameParam() {}

bool		SetGameParam::isValid()
{
  //
  // a definir
  //
  return true;
}

void		SetGameParam::doOp()
{
  //
  // a definir
  // 
}

void		SetGameParam::finalize(IService* S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		SetGameParam::manageRequest(IService *S)
{
  if (this->isValid())
    this->doOp();
  else
    this->ec = G_invalid_request;
  this->finalize(S);
  return (true);
}

std::string	SetGameParam::toString()
{
  return (std::string(this->parameters.param));
}

eRequestType	SetGameParam::getType()
{
  return SET_GAME_PARAM;
}

SetGameParam::parameter&  SetGameParam::getParam()
{
	return this->parameters;
}

LaunchGame::LaunchGame(int roomId) : 
  ec(Success)
{
  parameters.roomId = roomId;
}

LaunchGame::LaunchGame(std::string &data)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  data.size());
  ec = Success;
}

LaunchGame::~LaunchGame() {}

bool		LaunchGame::isValid()
{
  return true;
}

void		LaunchGame::doOp()
{
  RoomManager&	RM = Resources::RM;
  try
  {
	std::deque<IPlayer*> players = RM.getPlayersFromRoom(this->parameters.roomId);

	RM.setRoomStatus(this->parameters.roomId, true);
	RM.linkRoomToThreadPool(this->parameters.roomId);
  }
  catch (RoomNotFound&)
  {
	  this->ec = S_process_fail;
  }

  //
  // notifier les autres clients que le jeu est lancé
  //
}

void		LaunchGame::finalize(IService* S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		LaunchGame::manageRequest(IService *S)
{
  if (this->isValid())
    this->doOp();
  else
    this->ec = S_process_fail;
  this->finalize(S);
  return (true);
}

std::string	LaunchGame::toString()
{
  return ("");
}

eRequestType	LaunchGame::getType()
{
  return LAUNCH_GAME;
}

LaunchGame::parameter&  LaunchGame::getParam()
{
	return this->parameters;
}

Ping::Ping() :
  ec(Success), P(0)
{

}

Ping::Ping(std::string &)
	: P(0)
{
  ec = Success;
}

Ping::~Ping() {}

bool		Ping::isValid()
{
  return true;
}

void		Ping::doOp()
{
  //
  //	a Definir
  //

  // this->P->isAlive();
}

void		Ping::finalize(IService* S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		Ping::manageRequest(IService *S)
{
  RoomManager&	RM = Resources::RM;

  this->P = RM.getPlayerFromHall(S);

  if (this->isValid())
    this->doOp();
  else
    this->ec = S_process_fail;
  this->finalize(S);
  return (true);
}

std::string	Ping::toString()
{
  return ("");
}

eRequestType	Ping::getType()
{
  return PING;
}

Ready::Ready(char *ep) :
  ec(Success), P(0)
{
  std::string	epp(ep);
  PackMan::Memcpy(this->parameters.endpoint, epp.data(), epp.size());
}

Ready::Ready(std::string &data)
	: P(0)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  data.size());
  ec = Success;
}

Ready::~Ready() {}

bool		Ready::isValid()
{
  return true;
}

void		Ready::doOp()
{
  this->P->setStatus(true);
  this->P->setEp(std::string(this->parameters.endpoint));

  //
  // are players ready for game ?
  //
}

void		Ready::finalize(IService* S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		Ready::manageRequest(IService *S)
{
  RoomManager&	RM = Resources::RM;

  this->P = RM.getPlayerFromHall(S);

  if (this->isValid())
    this->doOp();
  else
    this->ec = S_process_fail;
  this->finalize(S);
  return (true);
}
std::string	Ready::toString()
{
  return std::string(this->parameters.endpoint);
}
eRequestType	Ready::getType()
{
  return READY;
}

Ready::parameter&  Ready::getParam()
{
	return this->parameters;
}
