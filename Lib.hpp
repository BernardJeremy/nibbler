//
// Lib.hpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 12:37:06 2014 bernar_w
// Last update Thu Apr  3 17:19:21 2014 Claire Almozinos
//

#ifndef			LIB_HPP_
# define		LIB_HPP_

#include		<exception>
#include		<string>
#include		<iostream>
#include		<cstdlib>
#include		<dlfcn.h>
#include		"Error.hpp"
#include		"IGraph.hpp"

class Lib
{
public:
  Lib(std::string const & file);

  int			closeLib() const;
  char			*errorLib() const;

  const std::string	&getFile() const;
  void			*getHandle() const;
  IGraph		*getLib() const;

  ~Lib() {}

private:
  std::string		_file;
  void			*_handle;
};

#endif			/* !LIB_HPP_ */
