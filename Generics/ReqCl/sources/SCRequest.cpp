//
// SCRequest.cpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Thu Jan  3 18:45:41 2013 alexandre teisseire
// Last update Sat Jan 19 00:19:03 2013 alexandre teisseire
//

#include <sstream>
#include "PackMan.h"
#include "SCRequest.h"

AnswerCreateRoom::AnswerCreateRoom(int roomId) :
  ec(Success)
{
  parameters.roomId = roomId;
}

AnswerCreateRoom::AnswerCreateRoom(std::string &data) :
  ec(Success)
{
  PackMan::Memcpy(&(this->parameters), data.data(), data.size());
}

AnswerCreateRoom::~AnswerCreateRoom() {}

bool		AnswerCreateRoom::isValid()
{
  return true;
}

void		AnswerCreateRoom::doOp()
{
  std::cout << "I got my room Id : " << this->parameters.roomId << std::endl;
}

void		AnswerCreateRoom::finalize(IService *S)
{
  IRequest*	IR = new ACK(this->ec);
  S->push(IR);
}

bool		AnswerCreateRoom::manageRequest(IService *S)
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
  std::stringstream	ss;

  ss << this->parameters.roomId;
  return (ss.str());
}

eRequestType	AnswerCreateRoom::getType()
{
  return ANSWER_CREATE_ROOM;
}

ClientInvited::ClientInvited(char *usernameFrom, int roomId) :
  ec(Success)
{
  parameters.usernameFrom = usernameFrom;
  parameters.roomId = roomId;  
}

ClientInvited::ClientInvited(std::string &data) :
  ec(Success)
{
  PackMan::Memcpy(&(this->parameters), data.data(), data.size());
}

ClientInvited::~ClientInvited() {}

bool		ClientInvited::isValid()
{
  return true;
}

void		ClientInvited::doOp() {}

void		ClientInvited::doOp(IService *S)
{
  IRequest*	IR = new JoinRoom(this->parameters.roomId);
  S->push(IR);
}

void		ClientInvited::finalize(IService*)
{
  //
  // ACK
  //
}

bool		ClientInvited::manageRequest(IService *S)
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
  std::stringstream	ss;

  ss << this->parameters.usernameFrom << ":" << this->parameters.roomId;
  return (ss.str());
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

void		ACK::finalize(IService*)
{
  // S->push(this);
}

bool		ACK::manageRequest(IService *S)
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
  std::stringstream ss;

  ss << this->parameters.eCode;
  return (ss.str());
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

void		GameLaunched::finalize(IService*)
{
  //
  // ACK
  //
}

bool		GameLaunched::manageRequest(IService *S)
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
  std::stringstream	ss;

  ss << this->parameters.timestamp << ":" << this->parameters.clock;
  return (ss.str());
}

eRequestType	GameLaunched::getType()
{
  return GAME_LAUNCHED;
}
