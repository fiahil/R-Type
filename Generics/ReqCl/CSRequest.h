#pragma once

#include	"IRequest.h"

class		Connect : public IRequest
{
public:
  typedef struct	parameter
  {
    char	username[20];
    char	passwd[20];
  }		parameters;

private:
  parameters	param;
  errorCode	ec;
private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

private:
    void		doOp(IService*);

public:
    Connect(std::string, std::string);
  Connect(std::string &);
  ~Connect();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
  parameters&	getParam();
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
public:
  typedef struct	parameter
  {
    int		roomId;
  }		parameters;

private:
  parameters	param;
  // IPlayer*	P;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);
  parameters&		getParam();

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
public:
  typedef struct	parameter
  {
    int		roomId;
  }		parameters;

private:
  parameters	param;
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
  parameters&		getParam();
};

class		InvitePlayer : public IRequest
{
public:
  typedef struct	parameter
  {
    char	username[20];
  }		parameters;

private:
  parameters	param;
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
  parameters&		getParam();
};

class		SetGameParam : public IRequest
{
public:
  typedef struct	parameter
  {
    int		key;
    int  	value;
  }		parameters;

private:
  parameters	param;
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
  parameters&		getParam();
};

class		LaunchGame : public IRequest
{
public:
  typedef struct	parameter
  {
    int		roomId;
  }		parameters;

private:
  parameters	param;
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
  parameters&		getParam();
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
public:
  typedef struct	parameter
  {
    char	endpoint[25];
  }		parameters;

private:
  parameters	param;
  errorCode	ec;
  // IPlayer*	P;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);
  parameters&		getParam();

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