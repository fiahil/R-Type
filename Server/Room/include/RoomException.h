
#pragma once

#include <exception>

class RoomNotFound : public std::exception
{
public:
	RoomNotFound() throw() {}
	~RoomNotFound() throw() {}
	virtual const char* what() const throw() { return "Room Not Found"; }
};