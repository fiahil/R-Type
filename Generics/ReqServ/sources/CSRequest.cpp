//
// CSRequest.cpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Thu Jan  3 18:32:43 2013 alexandre teisseire
// Last update Wed Jan  9 11:05:25 2013 alexandre teisseire
//

#include	<sstream>
// #include	"PackMan.hpp"
#include	"CSRequest.hpp"

Connect::Connect(char *usr, char *passwd) :
  ec(Success)
{
  parameters.username = usr;
  parameters.passwd = passwd;
}

Connect::~Connect() {}

bool		Connect::isValid()
{
  RoomManager&	RM = Resources::RM;
  std::string	username(parameters.username);

  if (RM.getPlayerFromName(username) == NULL)
    return true;
  return false;
}

void		Connect::doOp()
{

}

void		Connect::doOp(IService*S)
{
  RoomManager&	RM = Resources::RM;
  std::string	username(parameters.username);
  std::string	password(parameters.passwd);

  RM.addPlayerToHall(username, password, S);
}

void		Connect::finalize(IService *)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
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


CreateRoom::CreateRoom() :
  ec(Success)
{
}

CreateRoom::~CreateRoom() {}

bool		CreateRoom::isValid()
{
  return true;
}

void		CreateRoom::doOp()
{
  RoomManager&	RM = Resources::RM;
  int		idRoom;

  if((idRoom = RM.createRoom()) == -1)
    this->ec = S_cmd_refused;

  //
  // envoi de la request au client -> SCRequest
  //
}
void		CreateRoom::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		CreateRoom::manageRequest(IService *S)
{
  if (this->isValid())
    this->doOp();
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
  ec(Success)
{
  parameters.roomId = roomId;
}

LeaveRoom::~LeaveRoom() {}

bool		LeaveRoom::isValid()
{
  return true;
}

void		LeaveRoom::doOp()
{

}

void		LeaveRoom::doOp(IService *S)
{
  RoomManager&	RM = Resources::RM;

  RM.removePlayerFromRoom(this->P->getId(), parameters.roomId);
  RM.addPlayerToHall(this->P->getName(), this->P->getHash(), S);
}

void		LeaveRoom::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		LeaveRoom::manageRequest(IService *S)
{
  RoomManager&	RM = Resources::RM;

  this->P = RM.getPlayerFromRoom(S, parameters.roomId);

  if (this->isValid())
    this->doOp();
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

JoinRoom::JoinRoom(int roomId) :
  ec(Success)
{
  parameters.roomId = roomId;
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

void		JoinRoom::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
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

InvitePlayer::InvitePlayer(char *usr) :
  ec(Success)
{
  parameters.username = usr;
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
  //
  // faire suivre la requete d invitation au player correspondant
  //
}

void		InvitePlayer::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		InvitePlayer::manageRequest(IService *S)
{
  if (this->isValid())
    this->doOp();
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

SetGameParam::SetGameParam(int key, int value) :
  ec(Success)
{
  parameters.key = key;
  parameters.value = value;
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

void		SetGameParam::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
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
  std::stringstream ss;

  ss << this->parameters.key;
  ss << ":";
  ss << this->parameters.value;

  return (ss.str());
}

eRequestType	SetGameParam::getType()
{
  return SET_GAME_PARAM;
}

LaunchGame::LaunchGame() : 
  ec(Success)
{

}

LaunchGame::~LaunchGame() {}

bool		LaunchGame::isValid()
{
  return true;
}

void		LaunchGame::doOp()
{
  RoomManager&	RM = Resources::RM;
  std::deque<IPlayer*> players = RM.getPlayersFromRoom(this->parameters.roomId);

  RM.setRoomStatus(this->parameters.roomId, true);
  RM.linkRoomToThreadPool(this->parameters.roomId);

  //
  // notifier les autres clients que le jeu est lancé
  //
}

void		LaunchGame::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
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

Ping::Ping() :
  ec(Success)
{

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

void		Ping::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
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
  ec(Success)
{
  this->parameters.endpoint = ep;
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

void		Ready::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
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
