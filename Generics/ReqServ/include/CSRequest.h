//
// CSRequest.hpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Thu Jan  3 15:39:14 2013 alexandre teisseire
// Last update Wed Jan  9 11:03:53 2013 alexandre teisseire
//

#pragma once

#include	"Resources.hpp"
#include	"RoomManager.h"
#include	"IRequest.hpp"
#include	"IPlayer.h"

class		Connect : protected IRequest
{
private:
  struct	parameters
  {
    char	*username;
    char	*passwd;
  };

  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

private:
    void		doOp(IService*);

public:
  Connect(char  *, char  *);
  ~Connect();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		CreateRoom : protected IRequest
{
private:
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  CreateRoom();
  ~CreateRoom();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		LeaveRoom : protected IRequest
{
private:
  struct	parameters
  {
    int		roomId;
  };

  parameters	parameters;
  IPlayer*	P;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

private:
    void		doOp(IService*);

public:
  LeaveRoom(int);
  ~LeaveRoom();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		JoinRoom : protected IRequest
{
private:
  struct	parameters
  {
    int		roomId;
  };

  parameters	parameters;
  errorCode	ec;
  IPlayer	*P;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  JoinRoom(int);
  ~JoinRoom();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		InvitePlayer : protected IRequest
{
private:
  struct	parameters
  {
    char	*username;
  };

  parameters	parameters;
  IPlayer*	P;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  InvitePlayer(char  *);
  ~InvitePlayer();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		SetGameParam : protected IRequest
{
private:
  struct	parameters
  {
    int		key;
    int  	value;
  };

  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  SetGameParam(int, int);
  ~SetGameParam();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		LaunchGame : protected IRequest
{
private:
  struct	parameters
  {
    int		roomId;
  };

  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  LaunchGame();
  ~LaunchGame();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		Ping : protected IRequest
{
private:
  errorCode	ec;
  IPlayer*	P;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  Ping();
  ~Ping();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		Ready : protected IRequest
{
private:
  struct	parameters
  {
    char	*endpoint;
  };

  parameters	parameters;
  errorCode	ec;
  IPlayer*	P;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

private:
  Ready();

public:
  Ready(char *ep);
  ~Ready();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};
