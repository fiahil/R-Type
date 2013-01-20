
#pragma once

#include	"IRequest.h"

class		AnswerCreateRoom : public IRequest
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

private:
  void			doOp(IService*);
public:
  AnswerCreateRoom(int);
  AnswerCreateRoom(std::string &);
  ~AnswerCreateRoom();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		ClientInvited : public IRequest
{
private:
  struct	parameters
  {
    char	usernameFrom[32];
    int		roomId;
  };

  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  ClientInvited(std::string const &, int);
  ClientInvited(std::string &);
  ~ClientInvited();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		ACK : public IRequest
{
private:
  struct	parameters
  {
    int		eCode;
  };

  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  ACK(errorCode);
  ACK(std::string &);
  ~ACK();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		GameLaunched : public IRequest
{
private:
  struct	parameters
  {
    int		timestamp;
    float	clock;
  };
  
  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  GameLaunched(int, float);
  GameLaunched(std::string &);
  ~GameLaunched();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};
