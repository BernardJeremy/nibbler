//
// Snake.cpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 10:22:05 2014 bernar_w
// Last update Wed Mar 12 15:14:37 2014 Claire ALMOZINOS
//

#include		"Snake.hpp"

Snake::Snake(int X, int Y, int Xmax, int Ymax, bool head)
{
  _x = X;
  _y = Y;
  _xmax = Xmax;
  _ymax = Ymax;
  _head = head;
}

int			Snake::getX() const
{
  return (_x);
}

int			Snake::getY() const
{
  return (_y);
}

int			Snake::getXMax() const
{
  return (_xmax);
}

int			Snake::getYMax() const
{
  return (_ymax);
}

void			Snake::setX(int nb)
{
  this->_x = nb;
}

void			Snake::setY(int nb)
{
  this->_y = nb;
}

bool			Snake::isHead() const
{
  return (_head);
}

bool			Snake::isBorder() const
{
  return (_y >= _ymax || _x >= _xmax ? true : false);
}
