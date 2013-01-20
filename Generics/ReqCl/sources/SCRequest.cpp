//
// SCRequest.cpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Thu Jan  3 18:45:41 2013 alexandre teisseire
// Last update Sat Jan 19 02:54:33 2013 alexandre teisseire
//


#include "PackMan.h"
#include "IClientService.h"
#include "SCRequest.h"

AnswerCreateRoom::AnswerCreateRoom(int roomId) :
  ec(Success)
{
  parameters.roomId = roomId;
}

AnswerCreateRoom::AnswerCreateRoom(std::string &data) :
  ec(Success)
{
  PackMan::MemSet(&(this->parameters), sizeof(this->parameters));
  PackMan::Memcpy(&(this->parameters), data.data(), data.size());
}

AnswerCreateRoom::~AnswerCreateRoom() {}

bool		AnswerCreateRoom::isValid()
{
  return true;
}

void		AnswerCreateRoom::doOp()
{
}

void		AnswerCreateRoom::finalize(ITCPClientService *)
{
}

bool		AnswerCreateRoom::manageRequest(ITCPClientService *S)
{
  if (this->isValid())
    this->doOp();
  else
    this->ec = C_connection_failed;
  this->finalize(S);
  return (true);
}

std::string	AnswerCreateRoom::toString()
{
  return (std::string(reinterpret_cast<char const *>(&this->parameters), sizeof(this->parameters)));
}

eRequestType	AnswerCreateRoom::getType()
{
  return ANSWER_CREATE_ROOM;
}

ClientInvited::ClientInvited(std::string const &usernameFrom, int roomId) :
  ec(Success)
{
  PackMan::Memcpy(parameters.usernameFrom, usernameFrom.data(), usernameFrom.size());
  parameters.roomId = roomId;
}

ClientInvited::ClientInvited(std::string &data) :
  ec(Success)
{
  PackMan::MemSet(&(this->parameters), sizeof(this->parameters));
  PackMan::Memcpy(&(this->parameters), data.data(), data.size());
}

ClientInvited::~ClientInvited() {}

bool		ClientInvited::isValid()
{
  return true;
}

void		ClientInvited::doOp() {}

void		ClientInvited::doOp(ITCPClientService *S)
{
  IRequest*	IR = new JoinRoom(this->parameters.roomId);
  TCPPacket*	P = PackMan::pack(IR);
  S->sendData(P);
}

void		ClientInvited::finalize(ITCPClientService*)
{
}

bool		ClientInvited::manageRequest(ITCPClientService *S)
{
  if (this->isValid())
    this->doOp(S);
  else
    this->ec = C_client_refuse;
  this->finalize(S);
  return (true);
}

std::string	ClientInvited::toString()
{
  return (std::string(reinterpret_cast<char const *>(&this->parameters), sizeof(this->parameters)));
}

eRequestType	ClientInvited::getType()
{
  return CLIENT_INVITED;
}


ACK::ACK(errorCode e)
{
  parameters.eCode = static_cast<int>(e);
}

ACK::ACK(std::string &data)
{
  PackMan::MemSet(&(this->parameters), sizeof(this->parameters));
  PackMan::Memcpy(&(this->parameters), data.data(), data.size());
}

ACK::~ACK() {}

bool		ACK::isValid()
{
  return true;
}

void		ACK::doOp()
{
  //
  //	- treat Error -
  //
}

void		ACK::finalize(ITCPClientService*)
{
}

bool		ACK::manageRequest(ITCPClientService *S)
{
  if (this->isValid())
    this->doOp();
  else
    this->ec = User_did_not_respond;
  this->finalize(S);
  return (true);
}

std::string	ACK::toString()
{
  return std::string(reinterpret_cast<char const *>(&this->parameters), sizeof(this->parameters));
}

eRequestType	ACK::getType()
{
  return (ACK_);
}

GameLaunched::GameLaunched(int timeStamp, float clock) :
  ec(Success)
{
  parameters.timestamp = timeStamp;
  parameters.clock = clock;
}

GameLaunched::GameLaunched(std::string &data) :
  ec(Success)
{
  PackMan::MemSet(&(this->parameters), sizeof(this->parameters));
  PackMan::Memcpy(&(this->parameters), data.data(), data.size());
}

GameLaunched::~GameLaunched() {}

bool		GameLaunched::isValid()
{
  return true;
}

void		GameLaunched::doOp()
{
  //
  // start Load
  //
}

void		GameLaunched::finalize(ITCPClientService*)
{
}

bool		GameLaunched::manageRequest(ITCPClientService *S)
{
  if (this->isValid())
    this->doOp();
  else
    this->ec = C_connection_failed;
  this->finalize(S);
  return (true);
}

std::string	GameLaunched::toString()
{
  return (std::string(reinterpret_cast<char const *>(&this->parameters), sizeof(this->parameters)));
}

eRequestType	GameLaunched::getType()
{
  return GAME_LAUNCHED;
}
