//
// Error.hpp<2> for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 09:47:19 2014 bernar_w
// Last update Thu Apr  3 17:22:43 2014 Claire Almozinos
//

#ifndef			ERROR_HPP_
# define		ERROR_HPP_

#include		<exception>
#include		<string>
#include		<iostream>
#include		<cstdlib>

class Error: public std::exception
{
public:
  Error(std::string const& str="") throw();
  virtual const char*	what() const throw();
  virtual ~Error() throw() {}

private:
  std::string		_str;
};

#endif			/* !ERROR_HPP_ */
