/*
** sdl.c for rush in /home/bernar_w/Projet/rush/etape_1
** 
** Made by bernar_w
** Login   <bernar_w@epitech.net>
** 
** Started on  Fri Mar  7 22:31:52 2014 bernar_w
// Last update Sat Apr  5 16:35:21 2014 Claire Almozinos
*/

#include		"Sdl.hpp"
#include		"Action.hpp"

extern "C"
{
  IGraph		*getObjectLib()
  {
    return (new LibSDL());
  }
}

LibSDL::LibSDL()
{
}

void			LibSDL::getEvent() const
{
  SDL_Event		event;

  if (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT :
	  Action::onEchap();
	  break;
	case SDL_KEYDOWN :
	  switch ((int)event.key.keysym.sym)
	    {
	      case SDLK_ESCAPE : Action::onEchap(); break;
	      case SDLK_RIGHT : Action::onAction(1); break;
	      case SDLK_LEFT : Action::onAction(-1); break;
	    }
	  break;
	}
    }
}

std::string		LibSDL::get_img(int c) const
{
  std::string		img[8];

  img[0] = FOND;
  img[1] = SNAKE;
  img[2] = HEAD;
  img[3] = FRUIT1;
  img[4] = FRUIT2;
  img[5] = FRUIT3;
  img[6] = BLACK;
  img[7] = OVER;
  return (img[c]);
}

void			LibSDL::display_img(SDL_Surface *screen, int i, int x, int y) const
{
  SDL_Surface		*sdlImg;
  SDL_Rect		pos;

  pos.x = x;
  pos.y = y;
  sdlImg = _allImg[i];
  SDL_SetColorKey(sdlImg, SDL_SRCCOLORKEY, SDL_MapRGB(sdlImg->format, 254, 255, 237));
  SDL_BlitSurface(sdlImg, NULL, screen, &pos);
}

void			LibSDL::display_content(SDL_Surface *screen, int xmax, int ymax) const
{
  int			x;
  int			y;

  y = 0;
  while (y < ymax * PIXEL)
    {
      x = 0;
      while (x < xmax * PIXEL)
	{
	  if (y == 0)
	    display_img(screen, 6, x, y);
	  else
	    display_img(screen, 0, x, y);
	  x += PIXEL;
	}
      y += PIXEL;
    }
}

std::string		LibSDL::to_string(int value) const
{
  std::ostringstream	os;

  os << value;
  return (os.str());
}

void			LibSDL::imgInit()
{
  try
    {
      for (int i = 0; i < 8; i++)
	{
	  _allImg[i] = IMG_Load(get_img(i).c_str());
	  if (!_allImg[i])
	    throw Error("Image can't be loaded.\n");
	}
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what();
      std::exit(EXIT_FAILURE);
    }
}

void			LibSDL::init(int xMax, int yMax, int highScore)
{
  SDL_Surface		*screen;
  SDL_Color		color = {0, 255, 0, 0};
  std::string		nb = to_string(highScore);

  try
    {
      yMax++;
      if (xMax > 48 || yMax > 26)
	throw Error("Bad value on X and Y. X have to be lower 48 and Y lower than 26\n");
      if (SDL_Init(SDL_INIT_VIDEO) == -1)
	throw Error("SDL init Fail\n");
      if (TTF_Init() == -1)
	throw Error("Error initialisation of TTF_Init\n");
      if ((screen = SDL_SetVideoMode(xMax*PIXEL, yMax*PIXEL, 32, SDL_HWSURFACE)) == NULL)
	throw Error("SDL screen init Fail\n");
      this->_screen = screen;
      _police = TTF_OpenFont("Police/angelina.ttf", 45);
      _color = color;
      _highScore = nb;
      _xMax = xMax;
      imgInit();
      SDL_WM_SetCaption("Nibbler", NULL);
      SDL_FillRect(_screen, NULL, SDL_MapRGB(_screen->format, 111, 111, 111));
      display_content(_screen, xMax, yMax);
      displayLiveScore(0);
      SDL_Flip(_screen);
      getEvent();
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what();
      std::exit(EXIT_FAILURE);
    }
}

void			LibSDL::stop() const
{
  SDL_Surface		*screen;

  TTF_CloseFont(_police);
  TTF_Quit();
  SDL_Quit();
  try
    {
      if (SDL_Init(SDL_INIT_VIDEO) == -1)
	throw Error("SDL init Fail\n");
      if ((screen = SDL_SetVideoMode(600, 337, 32, SDL_HWSURFACE)) == NULL)
	throw Error("SDL screen init Fail\n");
      display_img(screen, 7, 0, 0);
      SDL_Flip(screen);
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what();
      std::exit(EXIT_FAILURE);
    }
  SDL_Delay(500);
  SDL_Quit();
}

void			LibSDL::display(int x, int y, int flag, int score) const
{
  y++;
  display_img(this->_screen, flag, x*PIXEL, y*PIXEL);
  SDL_Flip(this->_screen);
  displayLiveScore(score);
}

void			LibSDL::displayLiveScore(int score) const
{
  SDL_Surface		*texte;
  SDL_Rect		position;
  std::string		nb = to_string(score);
  int			i;

  i = 0;
  while (i < _xMax)
    {
      display_img(this->_screen, 6, i*PIXEL, 0*PIXEL);
      i++;
    }
  texte = TTF_RenderText_Blended(_police, "Live Score :", _color);
  position.x = 0.3 * PIXEL;
  position.y = 0;
  SDL_BlitSurface(texte, NULL, _screen, &position);
  texte = TTF_RenderText_Blended(_police, nb.c_str(), _color);
  position.x = 4.5 * PIXEL;
  position.y = 0;
  SDL_BlitSurface(texte, NULL, _screen, &position);
  texte = TTF_RenderText_Blended(_police, "High Score : ", _color);
  position.x = (_xMax - 5.8) * PIXEL;
  position.y = 0;
  SDL_BlitSurface(texte, NULL, _screen, &position);
  texte = TTF_RenderText_Blended(_police, _highScore.c_str(), _color);
  position.x = (_xMax - 1.3) * PIXEL;
  position.y = 0;
  SDL_BlitSurface(texte, NULL, _screen, &position);
}
