//
// SCRequest.cpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Thu Jan  3 18:45:41 2013 alexandre teisseire
// Last update Thu Jan 17 16:22:15 2013 alexandre teisseire
//

#include <assert.h>
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
  assert(0);
  return true;
}

void		AnswerCreateRoom::doOp()
{
  assert(0);
}

void		AnswerCreateRoom::finalize(IService*)
{
  assert(0);
}

bool		AnswerCreateRoom::manageRequest(IService *)
{
  assert(0);
  return true;
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

ClientInvited::ClientInvited(std::string const &usernameFrom, int roomId) :
  ec(Success)
{
	PackMan::Memcpy(&(this->parameters.usernameFrom), usernameFrom.data(), usernameFrom.size());
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
  assert(0);
  return true;
}

void		ClientInvited::doOp()
{
  assert(0);
}

void		ClientInvited::finalize(IService*)
{
  assert(0);
  //
  // ACK
  //
}

bool		ClientInvited::manageRequest(IService *)
{
  assert(0);
  return true;
}

std::string	ClientInvited::toString()
{
	return std::string(reinterpret_cast<char const*>(&this->parameters), sizeof(this->parameters));
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
  // treatError
}

void		ACK::finalize(IService* S)
{
	S->push(this);
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
  assert(0);
  return true;
}

void		GameLaunched::doOp()
{
  assert(0);
}

void		GameLaunched::finalize(IService*)
{
  assert(0);
}

bool		GameLaunched::manageRequest(IService *)
{
  assert(0);
  return true;
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
