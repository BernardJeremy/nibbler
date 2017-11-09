//
// Game.hpp for Nibbler in /home/almozi_c/rendu/Nibbler
// 
// Made by Claire ALMOZINOS
// Login   <almozi_c@epitech.net>
// 
// Started on  Wed Mar 12 09:40:32 2014 Claire ALMOZINOS
// Last update Sat Apr  5 16:17:37 2014 Jeremy Bernard
//

#ifndef			GAME_HPP_
# define		GAME_HPP_

#include		<cstdlib>
#include		<vector>
#include		<unistd.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		"Snake.hpp"
#include		"Fruit.hpp"
#include		"IGraph.hpp"
#include		"Score.hpp"

typedef std::vector<Snake *> snakeVector;
typedef snakeVector::reverse_iterator revItSnake;

class			Game
{
public:
  Game(int xmax, int ymax, IGraph *lib);
  ~Game();
   std::vector<Snake *>	*getSnake();
  Snake			*getHead() const;
  Fruit			*getFruit() const;
  IGraph		*getLib() const;
  int			getSizeSnake() const;
  int			getXmove() const;
  int			getYmove() const;

  void			setFruit();
  int			setRandPos(int max);
  void			setSizeSnake();

  void			howSleep(bool decr);
  bool			haveLoose(int x, int y) const;
  void			moveInit(int flag);
  void			setDirection(int flag);
  void			move(int x, int y, int lastX, int lastY, revItSnake rit2);
  void			moveHead(int x, int y, revItSnake rit);
  void			addPart(int nb);
  void			manage(int nbr1, int nbr2);

private:
  std::vector<Snake *>	_snake;
  Snake			*_head;
  Fruit			*_fruit;
  IGraph		*_lib;
  Score			*_score;
  bool			_fruitTurn;
  int			_sizeSnake;
  int			_xMove;
  int			_yMove;
  int			_mySleep;
  int			_i;
};

#endif			/* !GAME_HPP_ */
