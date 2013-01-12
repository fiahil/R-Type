/*
** IServerService.h for R-Type in /home/teisse_a//Documents/Tek3/RType/R-Type/Server/NetWork/include
** 
** Made by alexandre teisseire
** Login   <teisse_a@epitech.net>
** 
** Started on  Wed Jan  9 11:27:08 2013 alexandre teisseire
** Last update Wed Jan  9 11:41:41 2013 alexandre teisseire
*/

#pragma once

#include	"IService.h"
#include	"IClientService.h"

class		IServerService : public IService
{
public:
  virtual ~IServerService() {}
  virtual IClientService*		accept() = 0;
};
