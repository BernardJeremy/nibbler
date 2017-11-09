//
// Action.hpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 19:32:22 2014 bernar_w
// Last update Sat Apr  5 16:01:41 2014 Claire Almozinos
//


#ifndef			ACTION_HPP_
# define		ACTION_HPP_

#include		<exception>
#include		<string>
#include		<iostream>
#include		<cstdlib>
#include		"IGraph.hpp"
#include		"Game.hpp"

class			Action
{
public:

  static Game		*initAction(Game *game);
  static void		onAction(int flag, bool exit = false);
  static bool		onEchap();
};

#endif			/* !ACTION_HPP_ */
