//
// main.cpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 09:42:17 2014 bernar_w
// Last update Sat Apr  5 09:28:18 2014 Claire Almozinos
//

#include		"Game.hpp"
#include		"Lib.hpp"
#include		"Init.hpp"
#include		"IGraph.hpp"
#include		"Snake.hpp"
#include		"Action.hpp"

int			main(int ac, char **av)
{
  Init			init(ac, av, "y");
  int			nbr1;
  int			nbr2;
  IGraph		*myLib;
  Lib			lib(av[3]);
  std::string		stg1(av[1]);
  std::string		stg2(av[2]);
  std::istringstream	str1(stg1);
  std::istringstream	str2(stg2);
  std::string		replay;

  str1 >> nbr1;
  str2 >> nbr2;

  while (init.getReplay() == "y")
    {
      myLib = lib.getLib();

      Game			game(nbr1, nbr2, myLib);

      game.manage(nbr1, nbr2);
      std::cout << "Do you want to replay ? [y\\n]" << std::endl;
      std::cin >> replay;
      init.setReplay(replay);
    }
  return (0);
}
