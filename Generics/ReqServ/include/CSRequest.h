#pragma once

#include	"Resources.h"
#include	"RoomManager.h"
#include	"IRequest.h"
#include	"IPlayer.h"



class		Connect : public IRequest
{
private:
  struct	parameter
  {
    char	username[32];
    char	passwd[32];
  };

  parameter	data;
  errorCode	ec;
private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

private:
    void		doOp(IService*);

public:
  Connect(std::string const&, std::string const&);
  Connect(std::string &);
  ~Connect();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
  parameter&			getParam();
};

class		CreateRoom : public IRequest
{
private:
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  void			doOp(IService*);
  virtual void		finalize(IService*);

public:
  CreateRoom();
  CreateRoom(std::string &);
  ~CreateRoom();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		LeaveRoom : public IRequest
{
private:
  struct	parameter
  {
    int		roomId;
  };

  parameter	data;
  errorCode	ec;
  IPlayer*	P;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

private:
    void		doOp(IService*);

public:
  LeaveRoom(int);
  LeaveRoom(std::string &);
  ~LeaveRoom();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
  parameter&			getParam();
};

class		JoinRoom : public IRequest
{
private:
  struct	parameter
  {
    int		roomId;
  };

  parameter	data;
  errorCode	ec;
  IPlayer	*P;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  JoinRoom(int);
  JoinRoom(std::string &);
  ~JoinRoom();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
  parameter&			getParam();
};

class		InvitePlayer : public IRequest
{
private:
  struct	parameter
  {
    char	username[32];
  };

  parameter	data;
  errorCode	ec;
  IPlayer*	P;

private:
  virtual bool		isValid();
  virtual void		doOp();
  void			doOp(IService*);
  virtual void		finalize(IService*);

public:
  InvitePlayer(char  *);
  InvitePlayer(std::string &);
  ~InvitePlayer();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
  parameter&			getParam();
};

class		SetGameParam : public IRequest
{
private:
  struct	parameter
  {
    char	param[32];
  };

  parameter	data;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  SetGameParam(int, int);
  SetGameParam(std::string &);
  ~SetGameParam();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
  parameter&			getParam();
};

class		LaunchGame : public IRequest
{
private:
  struct	parameter
  {
    int		roomId;
  };

  parameter	data;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  LaunchGame(int);
  LaunchGame(std::string &);
  ~LaunchGame();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
  parameter&			getParam();
};

class		Ping : public IRequest
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
  Ping(std::string &);
  ~Ping();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		Ready : public IRequest
{
private:
  struct	parameter
  {
    char	endpoint[32];
  };

  parameter	data;
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
  Ready(std::string &);
  ~Ready();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
  parameter&			getParam();
};
