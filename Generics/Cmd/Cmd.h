
#pragma once

typedef unsigned short ID;

struct Move
{
  ID  id;
  int x;
  int y;
  int speedx;
  int speedy;
};

struct Fire
{
  ID  id;
  int x;
  int y;
  int speedx;
  int speedy;
  int power;
};

struct Death
{
  ID  id;
  int x;
  int y;
};

struct NewEntity
{
  ID  id;
  int x;
  int y;
  int speedx;
  int speedy;
  int type;
};