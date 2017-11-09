/*
** sdl.c for rush in /home/bernar_w/Projet/rush/etape_1
** 
** Made by bernar_w
** Login   <bernar_w@epitech.net>
** 
** Started on  Fri Mar  7 22:31:52 2014 bernar_w
// Last update Sat Apr  5 16:32:50 2014 Claire Almozinos
*/

#include	"Allegro.hpp"
#include	"Action.hpp"

extern "C"
{
  IGraph	*getObjectLib()
  {
    return (new LibAllegro());
  }
}

LibAllegro::LibAllegro()
{
}

void		LibAllegro::init(int xMax, int yMax, int highScore)
{
  std::string	nb = to_string(highScore);

  try
    {
      if (xMax > 48 || yMax > 26)
	throw Error("Bad value on X and Y. X have to be lower 48 and Y lower than 26\n");
      _highScore = nb;
      _xMax = xMax;
      if (allegro_init() != 0)
	throw Error("Allegro init Fail\n");
      install_keyboard();
      set_color_depth(16);
      if ((set_gfx_mode(GFX_AUTODETECT_WINDOWED, xMax * PIXEL, yMax * PIXEL, 0, 0)) != 0)
	throw Error("Allegro init Fail\n");
      clear_bitmap(screen);
      displayScores(0);
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what();
      stop();
      std::exit(EXIT_FAILURE);
    }
}

void		LibAllegro::stop() const
{
  allegro_exit();
}

void   LibAllegro::getEvent() const
{
  int	input;

  if (keypressed())
    {
      input = readkey();
      switch (input >> 8)
	{
	case KEY_LEFT : Action::onAction(-1); break;
	case KEY_RIGHT : Action::onAction(1); break;
	case KEY_ESC : Action::onEchap(); break;
	default : break;
	}
      clear_keybuf();
    }
}

void		LibAllegro::display(int x, int y, int flag, int score) const
{
  x *= PIXEL;
  y *= PIXEL;
  rectfill(screen, x, y, x + PIXEL, y + PIXEL, getColor(flag));
  displayScores(score);
}

void		LibAllegro::displayLiveScore(int score) const
{
  display(2, 0, 0, score);
  display(3, 0, 0, score);
}

void		LibAllegro::displayScores(int score) const
{
  std::string   nb = to_string(score);

  textout_ex(screen, font, "LIVE SCORE : ", 10, 10, makecol(0, 255, 0), -1);
  textout_ex(screen, font, nb.c_str(), 115, 10, makecol(0, 255, 0), -1);
  textout_ex(screen, font, "HIGH SCORE : ", (_xMax - 3.5) * PIXEL, 10, makecol(0, 255, 0), -1);
  textout_ex(screen, font, _highScore.c_str(), (_xMax - 0.8) * PIXEL, 10, makecol(0, 255, 0), -1);
}

int		LibAllegro::getColor(int flag) const
{
  switch (flag)
    {
    case BACK : return (makecol(0, 0, 0));
    case SNAKE : return (makecol(116, 208, 241));
    case HEAD : return (makecol(44, 117, 255));
    case FRUIT1 : return (makecol(252, 220, 18));
    case FRUIT2 : return (makecol(255, 127, 0));
    case FRUIT3 : return (makecol(255, 0, 0));
    }
  return (0);
}

std::string	LibAllegro::to_string(int value) const
{
  std::ostringstream os;

  os << value;
  return (os.str());
}
