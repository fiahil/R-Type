
#pragma once

typedef unsigned short ID;

struct Move
{
  ID	id;
  int	x;
  int	y;
  int	speedx;
  int	speedy;
};

struct Fire
{
  ID	id;
  int	x;
  int	y;
  int	speedx;
  int	speedy;
  int	power;
};

struct Death
{
  ID	id;
};

struct NewEntity
{
  ID	id;
  int	idSkin;
  int	x_start;
  int	y_start;
};

struct Input
{
  ID	id;
  int	enumKey;
};
