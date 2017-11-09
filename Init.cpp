//
// Init.cpp for nibbler in /home/bernar_w/Projet/Nibbler/core
//
// Made by bernar_w
// Login   <bernar_w@epitech.net>
//
// Started on  Wed Mar 12 15:18:29 2014 bernar_w
// Last update Sat Apr  5 09:20:35 2014 Claire Almozinos
//

#include	"Init.hpp"

Init::Init(int ac, char **av, std::string replay): _ac(ac), _av(av), _replay(replay)
{
  manageCheck();
}

std::string	Init::getReplay() const
{
  return (_replay);
}

void		Init::setReplay(std::string const &replay)
{
  _replay = replay;
}

bool		Init::manageCheck() const
{
  return (haveThree() && isNbr(1) && isNbr(2) && checkSize());
}

bool		Init::haveThree() const
{
    try
    {
      if (_ac != 4)
	throw Error("Usage : ./nibbler Xmax Ymax ./lib.so\n");
      else
	return (true);
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what();
      std::exit(EXIT_FAILURE);
    }
}

bool		Init::checkSize() const
{
  int		nb1;
  int		nb2;
  std::string	str1(_av[1]);
  std::string	str2(_av[2]);
  std::istringstream st1(str1);
  std::istringstream st2(str2);

  st1 >> nb1;
  st2 >> nb2;
  try
    {
      if (nb1 >= SIZEXMIN && nb2 >= SIZEYMIN)
	return (true);
      else
	throw Error("Bad value on X and Y. They have to be upper than 15\n");
      return (false);
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what();
      std::exit(EXIT_FAILURE);
    }
}

bool		Init::isNbr(int i) const
{
  std::string	str(_av[i]);
  std::string::const_iterator it = str.begin();

  try
    {
      if (!str.empty())
	{
	  while (it != str.end() && std::isdigit(*it))
	    ++it;
	  if (it != str.end())
	    throw Error("Argument 1 & 2 have to be a number\n");
	  return (true);
	}
      throw Error("Bad Argument, empty\n");
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what();
      std::exit(EXIT_FAILURE);
    }
}
