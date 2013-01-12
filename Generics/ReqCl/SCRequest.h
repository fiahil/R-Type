//
// SCRequest.hpp for RType in /home/teisse_a//Documents/Tek3/RType/Requests
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Wed Jan  2 10:17:31 2013 alexandre teisseire
// Last update Wed Jan  9 09:36:14 2013 alexandre teisseire
//

#pragma once

#include	"IRequest.hpp"

class		AnswerCreateRoom : protected IRequest
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
  ~AnswerCreateRoom();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		ClientInvited : protected IRequest
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
  ~ClientInvited();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		ACK : protected IRequest
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
  ~ACK();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		StartDataStream : protected IRequest
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
  ~StartDataStream();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};


class		Stream : protected IRequest
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
  ~Stream();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};


class		StopDataStream : protected IRequest
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
  ~StopDataStream();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};

class		GameLaunched : protected IRequest
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
  ~GameLaunched();

public:
  virtual bool		manageRequest(IService*);
  virtual std::string	toString();
  virtual eRequestType	getType();
};
