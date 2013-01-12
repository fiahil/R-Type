//
// ClientService.cpp for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/Network
// 
// Made by alexandre teisseire
// Login   <teisse_a@epitech.net>
// 
// Started on  Sat Jan 12 18:27:56 2013 alexandre teisseire
// Last update Sat Jan 12 18:56:30 2013 alexandre teisseire
//

#include "ClientService.h"

ClientService::ClientService(Net::EndPoint const&)
{

}

ClientService::~ClientService() {}

void		ClientService::operator()()
{
}

IRequest*	ClientService::pull()
{
  return (NULL);
}

void		ClientService::push(IRequest*)
{

}
