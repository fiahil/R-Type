
#pragma once

class IEntity
{
public:
	int		x;
	int		y;
	int		width;
	int		heigth;

public:
	IEntity(int q, int w, int e, int r) : x(q), y(w), width(e + q), heigth(r + w) {}
	void	getPos(int& v, int& b) { v = x; b = y; }
	int		getXDown() const {return x;}
	int		getXUp() const {return heigth;}
	int		getYRight() const {return width;}
	int		getYLeft()	const {return y;}
};