
#pragma once

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
  virtual void		finalize(TCPService*);

private:
  void			doOp(TCPService*);
public:
  AnswerCreateRoom(int);
  AnswerCreateRoom(std::string &);
  ~AnswerCreateRoom();

public:
  virtual bool		manageRequest(TCPService*);
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
  void			doOp(TCPService*);
  virtual void		finalize(TCPService*);

public:
  ClientInvited(std::string const &, int);
  ClientInvited(std::string &);
  ~ClientInvited();

public:
  virtual bool		manageRequest(TCPService*);
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
  virtual void		finalize(TCPService*);

public:
  ACK(errorCode);
  ACK(std::string &);
  ~ACK();

public:
  virtual bool		manageRequest(TCPService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		StartDataStream : public IRequest
{
private:
  struct	parameters
  {
    char	*filename;
  };

  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(TCPService*);

public:
  StartDataStream(char const *);
  StartDataStream(std::string &);
  ~StartDataStream();

public:
  virtual bool		manageRequest(TCPService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};


class		Stream : public IRequest
{
private:
  struct	parameters
  {
    char	*filename;
    char	*data;
  };

  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(TCPService*);

public:
  Stream(char const *, char const *);
  Stream(std::string &);
  ~Stream();

public:
  virtual bool		manageRequest(TCPService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};


class		StopDataStream : public IRequest
{
private:
  struct	parameters
  {
    char	*filename;
    char	*lastData;
    int		datalen;
    char	*hash;
  };

  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(TCPService*);

public:
  StopDataStream(char const *, char const *, int, char const *);
  StopDataStream(std::string &);
  ~StopDataStream();

public:
  virtual bool		manageRequest(TCPService*);
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
  virtual void		finalize(TCPService*);

public:
  GameLaunched(int, float);
  GameLaunched(std::string &);
  ~GameLaunched();

public:
  virtual bool		manageRequest(TCPService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};
