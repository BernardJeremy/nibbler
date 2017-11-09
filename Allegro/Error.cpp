//
// Error.cpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 09:47:56 2014 bernar_w
// Last update Thu Apr  3 08:29:05 2014 Claire Almozinos
//

#include	"Error.hpp"

Error::Error(std::string const& str) throw()
{
  _str = str;
}

const char*	Error::what() const throw()
{
  return (_str.c_str());
}
