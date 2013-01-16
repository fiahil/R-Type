//
// CSRequest.cpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Thu Jan  3 18:32:43 2013 alexandre teisseire
// Last update Wed Jan 16 18:19:49 2013 alexandre teisseire
//

#include	<assert.h>
#include	<sstream>
#include	"PackMan.h"
#include	"CSRequest.h"

Connect::Connect(std::string usr, std::string passwd) :
  ec(Success)
{
  PackMan::Memcpy(param.username, usr.data(), usr.size());
  PackMan::Memcpy(param.passwd, passwd.data(), passwd.size());
}

Connect::Connect(std::string &data)
{
  PackMan::Memcpy(&(this->param), data.data(), data.size());
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
  return (std::string(this->param.username) + ":" + std::string(this->param.passwd));
}

eRequestType	Connect::getType()
{
  return CONNECT;
}

Connect::parameters&	Connect::getParam()
{
  return this->param;
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
  param.roomId = roomId;
}

LeaveRoom::LeaveRoom(std::string &data)
{
  PackMan::Memcpy(&(this->param), data.data(),  static_cast<size_t>(data.length()));
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

bool		LeaveRoom::manageRequest(IService *)
{
  assert(0);
  return true;
}

std::string	LeaveRoom::toString()
{
  std::stringstream ss;

  ss << this->param.roomId;
  return (ss.str());
}

eRequestType	LeaveRoom::getType()
{
  return LEAVE_ROOM;
}

LeaveRoom::parameters&	LeaveRoom::getParam()
{
  return this->param;
}

JoinRoom::JoinRoom(int roomId) :
  ec(Success)
{
  param.roomId = roomId;
}

JoinRoom::JoinRoom(std::string &data)
{
  PackMan::Memcpy(&(this->param), data.data(),  data.size());
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

bool		JoinRoom::manageRequest(IService *)
{
  assert(0);
  return true;
}

std::string	JoinRoom::toString()
{
  std::stringstream ss;

  ss << this->param.roomId;
  return (ss.str());
}

eRequestType	JoinRoom::getType()
{
  return JOIN_ROOM;
}

JoinRoom::parameters&	JoinRoom::getParam()
{
  return this->param;
}

InvitePlayer::InvitePlayer(char *) :
  ec(Success)
{
  // param.username = usr;
}

InvitePlayer::InvitePlayer(std::string &data)
{
  PackMan::Memcpy(&(this->param), data.data(),  data.size());
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
  return std::string(this->param.username);
}
eRequestType	InvitePlayer::getType()
{
  return INVITE_PLAYER;
}

InvitePlayer::parameters&	InvitePlayer::getParam()
{
  return this->param;
}

SetGameParam::SetGameParam(int key, int value) :
  ec(Success)
{
  param.key = key;
  param.value = value;
}

SetGameParam::SetGameParam(std::string &data)
{
  PackMan::Memcpy(&(this->param), data.data(),  data.size());
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

  ss << this->param.key;
  ss << ":";
  ss << this->param.value;

  return (ss.str());
}

eRequestType	SetGameParam::getType()
{
  return SET_GAME_PARAM;
}

SetGameParam::parameters&	SetGameParam::getParam()
{
  return this->param;
}

LaunchGame::LaunchGame(int roomId) : 
  ec(Success)
{
  param.roomId = roomId;
}

LaunchGame::LaunchGame(std::string &data)
{
  PackMan::Memcpy(&(this->param), data.data(),  data.size());
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

LaunchGame::parameters&	LaunchGame::getParam()
{
  return this->param;
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

Ready::Ready(char *) :
  ec(Success)
{
  // this->param.endpoint = ep;
}

Ready::Ready(std::string &data)
{
  PackMan::Memcpy(&(this->param), data.data(),  data.size());
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
  return std::string(this->param.endpoint);
}
eRequestType	Ready::getType()
{
  return READY;
}

Ready::parameters&	Ready::getParam()
{
  return this->param;
}
