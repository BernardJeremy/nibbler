//
// Sdl.hpp for nibbler in /home/bernar_w/Projet/Nibbler/SDL
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Fri Mar 14 09:06:45 2014 bernar_w
// Last update Thu Apr  3 09:31:10 2014 Claire Almozinos
//

#ifndef		LIBALLEGRO_HPP_
# define	LIBALLEGRO_HPP_

# include	<allegro.h>
# include	<unistd.h>
# include	"IGraph.hpp"
# include	"Error.hpp"

# define	PIXEL	40
# define	BACK	0
# define	SNAKE	1
# define	HEAD	2
# define	FRUIT1	3
# define	FRUIT2	4
# define	FRUIT3	5

class		LibAllegro: public IGraph
{
public:
  LibAllegro();
  virtual ~LibAllegro() {}

  void		init(int xMax, int yMax, int highScore);
  void		stop() const;
  void		getEvent() const;
  void		display(int x, int y, int flag, int score) const;
  void		displayLiveScore(int score) const;

  void		displayScores(int score) const;
  int		getColor(int flag) const;
private:
  std::string	to_string(int value) const;
  std::string	_highScore;
  int		_xMax;
};

#endif		/* !LIBALLEGRO */
