//
// Game.hpp for Nibbler in /home/almozi_c/rendu/Nibbler
// 
// Made by Claire ALMOZINOS
// Login   <almozi_c@epitech.net>
// 
// Started on  Wed Mar 12 09:40:32 2014 Claire ALMOZINOS
// Last update Mon Mar 31 20:05:51 2014 Claire Almozinos
//

#ifndef			GAME_HPP_
# define		GAME_HPP_

#include		<cstdlib>
#include		<vector>
#include		"Snake.hpp"
#include		"Fruit.hpp"
#include		"IGraph.hpp"
#include		"Score.hpp"

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

  bool			haveLoose(int x, int y) const;
  void			move(int x, int y);
  void			addPart(int nb);
  void			manage(int nbr1, int nbr2);

private:
  std::vector<Snake *>	_snake;
  Snake			*_head;
  Fruit			*_fruit;
  IGraph		*_lib;
  Score			*_score;
  int			_sizeSnake;
  int			_xMove;
  int			_yMove;
};

#endif			/* !GAME_HPP_ */
