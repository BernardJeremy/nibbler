//
// Lib.cpp for nibbler in /home/bernar_w/Projet/Nibbler/core
//
// Made by bernar_w
// Login   <bernar_w@epitech.net>
//
// Started on  Wed Mar 12 13:03:01 2014 bernar_w
// Last update Thu Apr  3 17:19:34 2014 Claire Almozinos
//

#include		"Lib.hpp"

Lib::Lib(std::string const & file)
{
  try
    {
      _file = file;
      this->_handle = dlopen(file.c_str(), RTLD_LAZY);
      if (!_handle)
	throw Error("dlopen() fail, use like \"./lib_env.so\".\n");
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what();
      std::exit(EXIT_FAILURE);
    }
}

int			Lib::closeLib() const
{
  int			ret = 0;

  try
    {
      ret = dlclose(_handle);
      if (ret)
	throw Error(this->errorLib());
      return (ret);
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
      std::exit(EXIT_FAILURE);
    }
}

char			*Lib::errorLib() const
{
  return (dlerror());
}

const std::string	&Lib::getFile() const
{
  return (_file);
}

void			*Lib::getHandle() const
{
  return (_handle);
}

IGraph			*Lib::getLib() const
{
  IGraph* (*getObjectLib)();

  try
    {
      getObjectLib = reinterpret_cast<IGraph* (*)()>(dlsym(_handle, "getObjectLib"));
      if (!getObjectLib)
	throw Error("Unrecognize symbol\n");
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what();
      std::exit(EXIT_FAILURE);
    }
  return (getObjectLib());
}

