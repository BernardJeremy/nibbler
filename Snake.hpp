//
// Snake.hpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 10:03:02 2014 bernar_w
// Last update Thu Apr  3 11:58:08 2014 Claire Almozinos
//

#ifndef			SNAKE_HPP_
# define		SNAKE_HPP_

#include		<exception>
#include		<string>
#include		<iostream>
#include		<cstdlib>

class			Snake
{
public:
  Snake(int X, int Y, int Xmax, int Ymax, bool head = false);

  int			getX() const;
  int			getY() const;
  int			getXMax() const;
  int			getYMax() const;

  void			setX(int nb);
  void			setY(int nb);

  bool			isHead() const;

  bool			isBorder() const;

  ~Snake() {}

private:
  int			_x;
  int			_y;
  int			_xmax;
  int			_ymax;
  bool			_head;
};

#endif			/* !SNAKE_HPP_ */
