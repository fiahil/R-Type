//
// CSRequest.cpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Thu Jan  3 18:32:43 2013 alexandre teisseire
// Last update Sun Jan 20 21:33:34 2013 alexandre teisseire
//

#include	<assert.h>
#include	"IClientService.h"
#include	"PackMan.h"
#include	"CSRequest.h"

Connect::Connect(std::string const& usr, std::string const& passwd) :
  ec(Success)
{
  PackMan::MemSet(&this->param, sizeof(this->param));
  PackMan::Memcpy(param.username, usr.data(), usr.size());
  PackMan::Memcpy(param.passwd, passwd.data(), passwd.size());
}

Connect::Connect(std::string &data)
{
  PackMan::MemSet(&this->param, sizeof(this->param));
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

void		Connect::finalize(ITCPClientService *)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		Connect::manageRequest(ITCPClientService *)
{
  assert(0);
  return true;
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
void		CreateRoom::finalize(ITCPClientService*)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		CreateRoom::manageRequest(ITCPClientService *)
{
  assert(0);
  return true;
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
  PackMan::MemSet(&this->param, sizeof(this->param));
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

void		LeaveRoom::doOp(ITCPClientService *)
{
  assert(0);
}

void		LeaveRoom::finalize(ITCPClientService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		LeaveRoom::manageRequest(ITCPClientService *)
{
  assert(0);
  return true;
}

std::string	LeaveRoom::toString()
{
  return std::string(reinterpret_cast<char const *>(&(this->param)), sizeof(this->param));
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
  PackMan::MemSet(&this->param, sizeof(this->param));
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

void		JoinRoom::finalize(ITCPClientService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		JoinRoom::manageRequest(ITCPClientService *)
{
  assert(0);
  return true;
}

std::string	JoinRoom::toString()
{
  return std::string(reinterpret_cast<char const *>(&(this->param)), sizeof(this->param));
}

eRequestType	JoinRoom::getType()
{
  return JOIN_ROOM;
}

JoinRoom::parameters&	JoinRoom::getParam()
{
  return this->param;
}

InvitePlayer::InvitePlayer(const char *u, int) :
  ec(Success)
{
  std::string usr(u);
  PackMan::MemSet(&this->param, sizeof(this->param));
  PackMan::Memcpy(this->param.username, usr.data(), usr.size());
}

InvitePlayer::InvitePlayer(std::string &data)
{
  PackMan::MemSet(&this->param, sizeof(this->param));
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

void		InvitePlayer::finalize(ITCPClientService*)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		InvitePlayer::manageRequest(ITCPClientService *)
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
  PackMan::MemSet(&this->param, sizeof(this->param));
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

void		SetGameParam::finalize(ITCPClientService*)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		SetGameParam::manageRequest(ITCPClientService *)
{
  assert(0);
  return (true);
}

std::string	SetGameParam::toString()
{
  return std::string(reinterpret_cast<char const *>(&(this->param)), sizeof(this->param));
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
  PackMan::MemSet(&this->param, sizeof(this->param));
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

void		LaunchGame::finalize(ITCPClientService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		LaunchGame::manageRequest(ITCPClientService *)
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

void		Ping::finalize(ITCPClientService*)
{
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		Ping::manageRequest(ITCPClientService *)
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

Ready::Ready(char const * ep, int) :
  ec(Success)
{
	std::string	data(ep);
  PackMan::MemSet(&this->param, sizeof(this->param));
  PackMan::Memcpy(&(this->param.endpoint), data.data(),  data.size());
}

Ready::Ready(std::string &data)
{
  PackMan::MemSet(&this->param, sizeof(this->param));
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

void		Ready::finalize(ITCPClientService*)
{
  assert(0);
  // IRequest	*req = new ACK(this->ec);
  // S.push(req);
}

bool		Ready::manageRequest(ITCPClientService *)
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
