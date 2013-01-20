
#pragma once

#include	"IClientService.h"
#include	"IService.h"
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
  virtual void		finalize(ITCPClientService*);

private:
  void			doOp(ITCPClientService*);
public:
  AnswerCreateRoom(int);
  AnswerCreateRoom(std::string &);
  ~AnswerCreateRoom();

public:
  virtual bool		manageRequest(ITCPClientService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
  void	finalize(IService*);
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
  void			doOp(ITCPClientService*);
  virtual void		finalize(ITCPClientService*);

public:
  ClientInvited(std::string const &, int);
  ClientInvited(std::string &);
  ~ClientInvited();

public:
  virtual bool		manageRequest(ITCPClientService*);
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
  virtual void		finalize(ITCPClientService*);

public:
  ACK(errorCode);
  ACK(std::string &);
  ~ACK();

public:
  virtual bool		manageRequest(ITCPClientService*);
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
  virtual void		finalize(ITCPClientService*);

public:
  GameLaunched(int, float);
  GameLaunched(std::string &);
  ~GameLaunched();

public:
  virtual bool		manageRequest(ITCPClientService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};
