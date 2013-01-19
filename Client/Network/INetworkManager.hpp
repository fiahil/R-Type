//
// INetworkManager.hpp for ClientRtype in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 21:50:28 2013 alexandre teisseire
// Last update Sat Jan 19 15:41:58 2013 alexandre teisseire
//

#ifndef		_INETWORKMANAGER_HPP_
#define		_INETWORKMANAGER_HPP_

#include	"Command.h"

class		INetworkManager
{
public:
  virtual ~INetworkManager() {}
  virtual void		run() = 0;
  virtual ICommand* getAction() = 0;
};

#endif
