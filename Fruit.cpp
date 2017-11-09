//
// Fruit.cpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 10:46:06 2014 bernar_w
// Last update Thu Mar 13 13:22:50 2014 Claire ALMOZINOS
//

#include		"Fruit.hpp"

Fruit::Fruit(int X, int Y, int value)
{
  _x = X;
  _y = Y;
  _value = value;
}

int			Fruit::getX() const
{
  return (_x);
}

int			Fruit::getY() const
{
  return (_y);
}

int			Fruit::getValue() const
{
  return (_value);
}

void			Fruit::setX(int nb)
{
  this->_x = nb;
}

void			Fruit::setY(int nb)
{
  this->_y = nb;
}

void			Fruit::setValue(int nb)
{
  this->_value = nb;
}

bool			Fruit::isFruit(int X, int Y) const
{
  return (_y == Y && _x == X ? true : false);
}
