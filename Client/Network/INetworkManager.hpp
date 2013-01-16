//
// INetworkManager.hpp for ClientRtype in /home/teisse_a//Documents/Tek3/RType/R-Type/Client/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Tue Jan 15 21:50:28 2013 alexandre teisseire
// Last update Tue Jan 15 22:31:16 2013 alexandre teisseire
//

#ifndef		_INETWORKMANAGER_HPP_
#define		_INETWORKMANAGER_HPP_

class		INetworkManager
{
public:
  virtual ~INetworkManager() {}
  virtual void		run() = 0;
};

#endif
