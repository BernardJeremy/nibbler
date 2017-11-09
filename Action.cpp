//
// Action.cpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 19:36:46 2014 bernar_w
// Last update Sat Apr  5 16:05:36 2014 Jeremy Bernard
//

#include		"Action.hpp"

Game			*Action::initAction(Game *game)
{
  static Game		*_game = NULL;

  if (!_game )
    {
      _game = game;
      return (_game);
    }
  if (!game)
    return (_game);
  return (NULL);
}

void			Action::onAction(int flag, bool exit)
{
  Game			*_game = Action::initAction(NULL);

  if (!exit)
    _game->moveInit(flag);
  else
    Action::onEchap();
}

bool			Action::onEchap()
{
  Game			*_game = Action::initAction(NULL);

  _game->getLib()->stop();
  std::exit(EXIT_SUCCESS);
}
