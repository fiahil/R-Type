//
// CSRequest.cpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Thu Jan  3 18:32:43 2013 alexandre teisseire
// Last update Wed Jan 16 00:49:50 2013 alexandre teisseire
//

#include	<sstream>
#include	"PackMan.h"
#include	"CSRequest.h"

Connect::Connect(char *usr, char *passwd) :
  ec(Success)
{
  parameters.username = usr;
  parameters.passwd = passwd;
}

Connect::Connect(std::string &data)
{
  PackMan::Memcpy(&(this->parameters), data.data(), data.size());
  ec = Success;
}

Connect::~Connect() {}

bool		Connect::isValid()
{
  assert(0);
  return true;
}

void		Connect::doOp()
{
  assert(0);
}

void		Connect::finalize(IService *)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		Connect::manageRequest(IService *)
{
  assert(0);
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
CreateRoom::CreateRoom(std::string &)
{
  ec = Success;
}

CreateRoom::~CreateRoom() {}

bool		CreateRoom::isValid()
{
  assert(0);
  return true;
}

void		CreateRoom::doOp()
{
  assert(0);

  //
  // envoi de la request au client -> SCRequest
  //
}
void		CreateRoom::finalize(IService*)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		CreateRoom::manageRequest(IService *)
{
  assert(0);
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

LeaveRoom::LeaveRoom(std::string &data)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  static_cast<size_t>(data.length()));
  ec = Success;
}

LeaveRoom::~LeaveRoom() {}

bool		LeaveRoom::isValid()
{
  assert(0);
  return true;
}

void		LeaveRoom::doOp()
{

}

void		LeaveRoom::doOp(IService *)
{
  assert(0);
}

void		LeaveRoom::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		LeaveRoom::manageRequest(IService *S)
{
  assert(0);
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

JoinRoom::JoinRoom(std::string &data)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  data.size());
  ec = Success;
}

JoinRoom::~JoinRoom() {}

bool		JoinRoom::isValid()
{
  assert(0);
  return 0;
}

void		JoinRoom::doOp()
{
  assert(0);
}

void		JoinRoom::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		JoinRoom::manageRequest(IService *S)
{
  assert(0);
  return true;
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

InvitePlayer::InvitePlayer(std::string &data)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  data.size());
  ec = Success;
}

InvitePlayer::~InvitePlayer() {}

bool		InvitePlayer::isValid()
{
  assert(0);
  return true;
}

void		InvitePlayer::doOp()
{
  assert(0);
  //
  // faire suivre la requete d invitation au player correspondant
  //
}

void		InvitePlayer::finalize(IService*)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		InvitePlayer::manageRequest(IService *)
{
  assert(0);
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

SetGameParam::SetGameParam(std::string &data)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  data.size());
  ec = Success;
}

SetGameParam::~SetGameParam() {}

bool		SetGameParam::isValid()
{
  assert(0);
  //
  // a definir
  //
  return true;
}

void		SetGameParam::doOp()
{
  assert(0);
  //
  // a definir
  // 
}

void		SetGameParam::finalize(IService*)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		SetGameParam::manageRequest(IService *)
{
  assert(0);
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
  assert(0);
  return true;
}

void		LaunchGame::doOp()
{
  assert(0);

  //
  // notifier les autres clients que le jeu est lancé
  //
}

void		LaunchGame::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		LaunchGame::manageRequest(IService *)
{
  assert(0);
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

Ping::Ping(std::string &)
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

void		Ping::finalize(IService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		Ping::manageRequest(IService *)
{
  assert(0);
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

Ready::Ready(std::string &data)
{
  PackMan::Memcpy(&(this->parameters), data.data(),  data.size());
  ec = Success;
}

Ready::~Ready() {}

bool		Ready::isValid()
{
  assert(0);
  return true;
}

void		Ready::doOp()
{
  assert(0);
  //
  // are players ready for game ?
  //
}

void		Ready::finalize(IService*)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		Ready::manageRequest(IService *)
{
  assert(0);
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
