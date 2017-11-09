//
// IGraph.hpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Wed Mar 12 11:27:37 2014 bernar_w
// Last update Wed Apr  2 17:44:31 2014 Claire Almozinos
//

#ifndef			IGRAPH_HPP_
#define			IGRAPH_HPP_

# include		<string>
# include		<iostream>
# include		<cstdlib>

class			IGraph
{
public:
  virtual void		init(int xMax, int yMax, int highScore) = 0;
  virtual void		stop() const = 0;
  virtual void		getEvent() const = 0;
  virtual void		display(int x, int y, int flag, int score) const = 0;
  virtual void		displayLiveScore(int score) const = 0;

  virtual ~IGraph() {}
};

extern "C"
{
  IGraph		*getObjectLib();
}

#endif			/* !IGRAPH_HPP_ */
