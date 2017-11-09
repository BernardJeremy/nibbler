//
// Score.hpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Thu Mar 13 10:07:38 2014 bernar_w
// Last update Mon Mar 31 20:03:40 2014 Claire Almozinos
//

#ifndef			SCORE_HPP_
# define		SCORE_HPP_

#include		<fstream>
#include		<string>
#include		<iostream>
#include		<cstdlib>
#include		<sstream>

class Score
{
public:
  Score(std::string const & file);

  int			getLive() const;
  int			getHighScore() const;

  void			setLive(int nb);
  void			addLive(int nb);
  void			setHighScore(int nb);

  void			saveHighScore() const;
  bool			isBetter() const;

  void			openFile();

  void			displayLive() const;
  void			displayHighScore();

  ~Score() {}

private:
  int			_liveScore;
  int			_highScore;
  std::ifstream		_fileFD;
  std::string		_fileName;
};

#endif			/* !SCORE_HPP_ */
