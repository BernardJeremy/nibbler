//
// NCurses.hpp for Nibbler in /home/almozi_c/rendu/Nibbler/NCURSES
// 
// Made by Claire ALMOZINOS
// Login   <almozi_c@epitech.net>
// 
// Started on  Thu Mar 13 14:47:11 2014 Claire ALMOZINOS
// Last update Sat Apr  5 15:55:08 2014 Claire Almozinos
//

#ifndef		NCURSES_HPP_
# define	NCURSES_HPP_

#include	<ncurses.h>
#include	<string>
#include	<iostream>
#include	<unistd.h>
#include	"Action.hpp"
#include	"IGraph.hpp"

# define	SIZEMAX 50
# define	ECHAP	27
# define	BACK	0
# define	SNAKE	1
# define	HEAD	2
# define	FRUIT1	3
# define	FRUIT2	4
# define	FRUIT3	5

class		NCurses : public  IGraph
{
public:
  NCurses();
  virtual ~NCurses();
  void		init(int xmax, int ymax, int highScore);
  void		stop() const;
  void		getEvent() const;
  void		display(int x, int y, int flag, int score) const;
  void		displayLiveScore(int score) const;

  void		initScoreWin(int xmax, int highScore);
private:
  WINDOW	*_window;
  WINDOW	*_scoreWindow;
  std::string	to_string(int value) const;
};

#endif		/* !NCURSES_HPP_ */
