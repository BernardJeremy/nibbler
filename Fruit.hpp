//
// Fruit.hpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 10:41:55 2014 bernar_w
// Last update Thu Apr  3 17:22:10 2014 Claire Almozinos
//

#ifndef			FRUIT_HPP_
# define		FRUIT_HPP_

#include		<exception>
#include		<string>
#include		<iostream>
#include		<cstdlib>

class			Fruit
{
public:
  Fruit(int X, int Y, int value);

  int			getX() const;
  int			getY() const;
  int			getValue() const;
  
  void			setX(int nb);
  void			setY(int nb);
  void			setValue(int nb);

  bool			isFruit(int X, int Y) const;

  ~Fruit() {}

private:
  int			_x;
  int			_y;
  int			_value;
};

#endif			/* !FRUIT_HPP_ */
