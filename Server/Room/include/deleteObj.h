
#pragma once

template<typename T>
void	deleteObject(T* obj)
{
	delete obj;
	obj = 0;
}
