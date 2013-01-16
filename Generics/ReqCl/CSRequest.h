#pragma once

#include	"IRequest.h"

class		Connect : public IRequest
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
  Connect(std::string &);
  ~Connect();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		CreateRoom : public IRequest
{
private:
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
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
  struct	parameters
  {
    int		roomId;
  };

  parameters	parameters;
  // IPlayer*	P;
  errorCode	ec;

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
};

class		JoinRoom : public IRequest
{
private:
  struct	parameters
  {
    int		roomId;
  };

  parameters	parameters;
  errorCode	ec;
  // IPlayer	*P;

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
};

class		InvitePlayer : public IRequest
{
private:
  struct	parameters
  {
    char	*username;
  };

  parameters	parameters;
  // IPlayer*	P;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  InvitePlayer(char  *);
  InvitePlayer(std::string &);
  ~InvitePlayer();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		SetGameParam : public IRequest
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
  SetGameParam(std::string &);
  ~SetGameParam();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		LaunchGame : public IRequest
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
  LaunchGame(int);
  LaunchGame(std::string &);
  ~LaunchGame();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		Ping : public IRequest
{
private:
  errorCode	ec;
  // IPlayer*	P;

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
  struct	parameters
  {
    char	*endpoint;
  };

  parameters	parameters;
  errorCode	ec;
  // IPlayer*	P;

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
};
