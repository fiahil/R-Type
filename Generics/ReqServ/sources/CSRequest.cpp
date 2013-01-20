
#include	<cassert>
#include	<sstream>
#include	"RoomException.h"
#include	"PackMan.h"
#include	"CSRequest.h"

Connect::Connect(std::string const& usr, std::string const& passwd) :
  ec(Success)
{
  PackMan::Memcpy(data.username, usr.data(), usr.size());
  PackMan::Memcpy(data.passwd, passwd.data(), passwd.size());
}

Connect::Connect(std::string &data)
{
  PackMan::Memcpy(&(this->data), data.data(), data.size());
  ec = Success;
}

Connect::~Connect() {}

bool		Connect::isValid()
{
  RoomManager&	RM = Resources::RM;
  std::string	username(data.username);

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
  std::string	username(data.username);
  std::string	password(data.passwd);

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
  return (std::string(this->data.username) + std::string(this->data.passwd));
}

eRequestType	Connect::getType()
{
  return CONNECT;
}

Connect::parameter&  Connect::getParam()
{
  return this->data;
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
  data.roomId = roomId;
}

LeaveRoom::LeaveRoom(std::string &data)
	: P(0)
{
  PackMan::Memcpy(&(this->data), data.data(),  static_cast<size_t>(data.length()));
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

void		LeaveRoom::doOp(IService *)
{
  RoomManager&	RM = Resources::RM;

  if (this->P == 0)
  {
	  this->ec = S_process_fail;
	  return;
  }
  RM.removePlayerFromRoom(this->P->getId(), data.roomId);
}

void		LeaveRoom::finalize(IService* S)
{
  IRequest	*req = new ACK(this->ec);
  S->push(req);
}

bool		LeaveRoom::manageRequest(IService *S)
{
  RoomManager&	RM = Resources::RM;

  this->P = RM.getPlayerFromRoom(S, data.roomId);

  if (this->isValid())
    this->doOp(S);
  else
    this->ec = G_invalid_request;
  this->finalize(S);
  return (true);
}

std::string	LeaveRoom::toString()
{
  return std::string(reinterpret_cast<char const *>(&this->data), sizeof(this->data));
}

eRequestType	LeaveRoom::getType()
{
  return LEAVE_ROOM;
}

LeaveRoom::parameter&  LeaveRoom::getParam()
{
	return this->data;
}

JoinRoom::JoinRoom(int roomId) :
  ec(Success), P(0)
{
  data.roomId = roomId;
}

JoinRoom::JoinRoom(std::string &data)
: P(0)
{
  PackMan::Memcpy(&(this->data), data.data(),  data.size());
  ec = Success;
}

JoinRoom::~JoinRoom() {}

bool		JoinRoom::isValid()
{
  RoomManager&	RM = Resources::RM;

  if (RM.getRoomById(data.roomId) == NULL)
    return false;
  return true;
}

void		JoinRoom::doOp()
{
  RoomManager&	RM = Resources::RM;

  if (this->P == 0)
  {
	  this->ec = S_process_fail;
	  return;
  }
  RM.clonePlayerFromHallToRoom(data.roomId, this->P->getId());
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
	assert(0);
	return ("");
}

eRequestType	JoinRoom::getType()
{
  return JOIN_ROOM;
}

JoinRoom::parameter&  JoinRoom::getParam()
{
	return this->data;
}

InvitePlayer::InvitePlayer(char* u) :
  ec(Success), P(0)
{
  std::string usr(u);
  PackMan::Memcpy(this->data.username, usr.data(), usr.size());
}

InvitePlayer::InvitePlayer(std::string &data)
	: P(0)
{
  PackMan::Memcpy(&(this->data), data.data(),  data.size());
  ec = Success;
}

InvitePlayer::~InvitePlayer() {}

bool		InvitePlayer::isValid()
{
  RoomManager&	RM = Resources::RM;
  std::string	username(data.username);

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
  if (P == 0)
  {
	  this->ec = S_process_fail;
	  return;
  }
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
  return std::string(this->data.username);
}
eRequestType	InvitePlayer::getType()
{
  return INVITE_PLAYER;
}

InvitePlayer::parameter&  InvitePlayer::getParam()
{
	return this->data;
}

SetGameParam::SetGameParam(std::string &param) :
  ec(Success)
{
  PackMan::Memcpy(this->data.param, param.data(),  param.size());
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
  return (std::string(this->data.param));
}

eRequestType	SetGameParam::getType()
{
  return SET_GAME_PARAM;
}

SetGameParam::parameter&  SetGameParam::getParam()
{
	return this->data;
}

LaunchGame::LaunchGame(int roomId) : 
  ec(Success)
{
  data.roomId = roomId;
}

LaunchGame::LaunchGame(std::string &data)
{
  PackMan::Memcpy(&(this->data), data.data(),  data.size());
  ec = Success;
}

LaunchGame::~LaunchGame() {}

bool		LaunchGame::isValid()
{
  return true;
}

#include "Cmd.h"
#include "Command.h"
#include "ICommand.h"
#include "IClientService.h"
#include "Windows.h"

void		LaunchGame::doOp()
{
  RoomManager&	RM = Resources::RM;
  try
  {
	std::deque<IPlayer*> players = RM.getPlayersFromRoom(this->data.roomId);

	for (std::deque<IPlayer*>::const_iterator it = players.begin();
		it != players.end();
		++it)
	{
		IRequest* ir = new GameLaunched(666, 5555.5555);

		(*it)->getService()->push(ir);
	}
  }
  catch (RoomNotFound&)
  {
	  this->ec = S_process_fail;
  }
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
	return this->data;
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

Ready::Ready(char *ep, int) :
  ec(Success), P(0)
{
  std::string	epp(ep);
  PackMan::Memcpy(this->data.endpoint, epp.data(), epp.size());
}

Ready::Ready(std::string &data)
	: P(0)
{
  PackMan::Memcpy(&(this->data), data.data(),  data.size());
  ec = Success;
}

Ready::~Ready() {}

bool		Ready::isValid()
{
	if (P == 0)
  {
	  this->ec = S_process_fail;
	  return false;
  }
  return true;
}

void		Ready::doOp()
{
  this->P->setStatus(true);
  this->P->setEp(std::string(this->data.endpoint)); //useless
  dynamic_cast<IClientService*>(this->P->getService())->connect(this->data.endpoint); // <3

  RoomManager&	RM = Resources::RM;

  try
  {
	int id = 0;
	bool allready = true;

	id = RM.getRoomIdFromPlayer(this->P);
	std::deque<IPlayer*> players = RM.getPlayersFromRoom(id);

	for (std::deque<IPlayer*>::const_iterator it = players.begin();
		it != players.end();
		++it)
	{
		if ((*it)->isPlaying() == false)
			allready = false;
	}

	if (allready)
	{
		RM.setRoomStatus(id, true);
		RM.linkRoomToThreadPool(id);
	}
  }
  catch (RoomNotFound&)
  {
	  this->ec = S_process_fail;
  }
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
  return std::string(this->data.endpoint);
}
eRequestType	Ready::getType()
{
  return READY;
}

Ready::parameter&  Ready::getParam()
{
	return this->data;
}
