
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
    char	*usernameFrom;
    int		roomId;
  };

  parameters	parameters;
  errorCode	ec;

private:
  virtual bool		isValid();
  virtual void		doOp();
  virtual void		finalize(IService*);

public:
  ClientInvited(char *, int);
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
  virtual void		finalize(IService*);

public:
  StartDataStream(char const *);
  StartDataStream(std::string &);
  ~StartDataStream();

public:
  virtual bool		manageRequest(IService*);
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
  virtual void		finalize(IService*);

public:
  Stream(char const *, char const *);
  Stream(std::string &);
  ~Stream();

public:
  virtual bool		manageRequest(IService*);
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
  virtual void		finalize(IService*);

public:
  StopDataStream(char const *, char const *, int, char const *);
  StopDataStream(std::string &);
  ~StopDataStream();

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
