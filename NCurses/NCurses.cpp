//
// NCurses.cpp for Nibbler in /home/almozi_c/rendu/Nibbler/NCURSES
// 
// Made by Claire ALMOZINOS
// Login   <almozi_c@epitech.net>
// 
// Started on  Thu Mar 13 14:57:56 2014 Claire ALMOZINOS
// Last update Sun Apr  6 17:50:01 2014 Claire Almozinos
//

#include	"NCurses.hpp"
#include	"Error.hpp"

extern "C"
{
  IGraph		*getObjectLib()
  {
    return (new NCurses());
  }
}

NCurses::NCurses()
{
}

NCurses::~NCurses()
{
}

void		NCurses::init(int xmax, int ymax, int highScore)
{
  try
    {
      if (xmax > SIZEMAX || ymax > SIZEMAX)
  	throw Error("Bad value on X and Y. X have to be lower 50\n");
      initscr();
      raw();
      noecho();
      curs_set(0);
      crmode();
      if ((_window = newwin(ymax + 2, xmax + 2, 0, 0)) == NULL)
	throw Error("Newwin goesn't work");
      box(_window, 0, 0);
      keypad(_window, true);
      nodelay(_window, true);
      wrefresh(_window);
    }
  catch(const std::exception &e)
    {
      std::cerr << e.what();
      endwin();
      std::exit(EXIT_FAILURE);
    }
  initScoreWin(xmax, highScore);
}

void		NCurses::initScoreWin(int xmax, int highScore)
{
  std::string	nb = to_string(highScore);

  try
    {
      if ((_scoreWindow = newwin(7, 25, 0, xmax + 2)) == NULL)
	throw Error("Newwin goesn't work");
      box(_scoreWindow, 0, 0);
    }
  catch(const std::exception &e)
    {
      std::cerr << e.what();
      endwin();
      std::exit(EXIT_FAILURE);
    }
  mvwprintw(_scoreWindow, 0, 10, "SCORE");
  mvwprintw(_scoreWindow, 2, 5, "Live score : 0");
  mvwprintw(_scoreWindow, 4, 5, "High score : ");
  mvwprintw(_scoreWindow, 4, 18, nb.c_str());
  wrefresh(_scoreWindow);
}

void		NCurses::stop() const
{
  endwin();
}

void		NCurses::getEvent() const
{
  int		keyPress;

  keyPress = wgetch(_window);
  switch (keyPress)
    {
    case ECHAP : Action::onEchap(); break;
    case KEY_LEFT : Action::onAction(-1); break;
    case KEY_RIGHT: Action::onAction(1); break;
    }
}

void		NCurses::display(int x, int y, int flag, int score) const
{
  x++;
  y++;
  switch (flag)
    {
    case BACK : mvwprintw(_window, y, x, " "); break;
    case SNAKE : mvwprintw(_window, y, x, "o"); break;
    case HEAD : mvwprintw(_window, y, x, "O"); break;
    case FRUIT1 : mvwprintw(_window, y, x, "1"); break;
    case FRUIT2 : mvwprintw(_window, y, x, "2"); break;
    case FRUIT3 : mvwprintw(_window, y, x, "3"); break;
    }
  (void)score;
}

void		NCurses::displayLiveScore(int score) const
{
  std::string	nb = to_string(score);

  mvwprintw(_scoreWindow, 2, 18, nb.c_str());
  wrefresh(_scoreWindow);
}

std::string	NCurses::to_string(int value) const
{
  std::ostringstream os;

  os << value;
  return (os.str());
}
