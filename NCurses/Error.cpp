//
// Error.cpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 09:47:56 2014 bernar_w
// Last update Wed Mar 12 09:48:08 2014 bernar_w
//

#include "Error.hpp"

Error::Error(std::string const& str) throw()
{
  _str = str;
}

const char* Error::what() const throw()
{
  return (_str.c_str());
}
