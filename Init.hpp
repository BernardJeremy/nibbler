//
// Init.hpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 15:05:55 2014 bernar_w
// Last update Thu Apr 10 13:16:25 2014 Jeremy Bernard
//

#ifndef			INIT_HPP_
# define		INIT_HPP_

#include		<exception>
#include		<string>
#include		<iostream>
#include		<cstdlib>
#include		<cctype>
#include		<sstream>
#include		"Error.hpp"

#define			SIZEXMIN 15
#define			SIZEYMIN 15

class Init
{
public:
  Init(int ac, char **av, std::string replay);
  ~Init() {}

  bool			manageCheck() const;
  void			replay();
  std::string		getReplay() const;
  void			setReplay(std::string const &replay);

private:
  int			_ac;
  char			**_av;
  std::string		_replay;
  bool			haveThree() const;
  bool			isNbr(int i) const;
  bool			checkSize() const;
};

#endif			/* !INIT_HPP_ */
