//
// IRequest.h for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan  2 10:13:52 2013 alexandre teisseire
// Last update Sun Jan 13 04:41:14 2013 alexandre teisseire
//

#pragma once

#include <string>
#include "IService.h"
#include "TCPPacket.h"

enum			errorCode
  {
    Success = 101,
    User_refused = 201,
    User_did_not_respond = 202,
    C_connection_failed = 203,
    C_client_refuse = 204,
    S_transfert_fail = 301,
    S_process_fail = 302,
    S_cmd_refused = 303,
    S_access_refused = 304,
    G_invalid_request = 401,
    G_incomplete_request = 402,
    G_forbidden_request = 403,
    G_request_not_found = 404
  };

enum			eRequestType
  {
    CONNECT = 1201,
    CREATE_ROOM = 1202,
    LEAVE_ROOM = 1203,
    JOIN_ROOM = 1204,
    INVITE_PLAYER = 1205,
    SET_GAME_PARAM = 1206,
    LAUNCH_GAME = 1207,
    PING = 1208,
    READY = 1209,
    ANSWER_CREATE_ROOM = 1301,
    CLIENT_INVITED = 1302,
    ACK_ = 1303,
    GAME_LAUNCHED = 1304
  };

class			IRequest
{
private:
  virtual bool		isValid() = 0;
  virtual void		doOp() = 0;
  virtual void		finalize(IService*) = 0;

public:
  virtual		~IRequest() {};
  virtual bool		manageRequest(IService*) = 0;
  virtual std::string	toString() = 0;
  virtual eRequestType	getType() = 0;
};
