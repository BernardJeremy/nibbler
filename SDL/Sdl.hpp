//
// Sdl.hpp for nibbler in /home/bernar_w/Projet/Nibbler/SDL
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Fri Mar 14 09:06:45 2014 bernar_w
// Last update Fri Apr  4 07:30:56 2014 Jeremy Bernard
//

#ifndef		SDL_HPP_
# define	SDL_HPP_

# include	<SDL/SDL.h>
# include	<SDL/SDL_image.h>
# include	<SDL/SDL_ttf.h>
# include	"IGraph.hpp"
# include	"Error.hpp"

# define	FOND "SDL/img/fond.jpg"
# define	SNAKE "SDL/img/Snake.png"
# define	HEAD "SDL/img/Head.png"
# define	FRUIT1 "SDL/img/apple.png"
# define	FRUIT2 "SDL/img/kiwi.png"
# define	FRUIT3 "SDL/img/pasteque.png"
# define	OVER "SDL/img/gameOver.jpg"
# define	BLACK "SDL/img/Score.png"
# define	PIXEL 40

class		LibSDL: public IGraph
{
public:
  LibSDL();
  virtual ~LibSDL() {}

  void		init(int xMax, int yMax, int highScore);
  void		stop() const;
  void		getEvent() const;
  void		display(int x, int y, int flag, int score) const;
  void		displayLiveScore(int score) const;

  void		imgInit();
  std::string	get_img(int c) const;
  void		display_img(SDL_Surface *screen, int i, int x, int y) const;
  void		display_content(SDL_Surface *screen, int xmax, int ymax) const;
  void		scoreDisplay() const;

private:
  std::string	to_string(int value) const;
  SDL_Surface	*_screen;
  TTF_Font	*_police;
  SDL_Color	_color;
  int		_xMax;
  std::string	_highScore;
  SDL_Surface 	*_allImg[8];
};

#endif		/* !SDL_HPP_ */
