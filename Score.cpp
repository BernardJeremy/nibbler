//
// Score.hpp for nibbler in /home/bernar_w/Projet/Nibbler/core
// 
// Made by bernar_w
// Login   <bernar_w@epitech.net>
// 
// Started on  Thu Mar 13 10:07:38 2014 bernar_w
// Last update Thu Apr  3 17:18:27 2014 Claire Almozinos
//

#include		"Score.hpp"

Score::Score(std::string const & file)
{
  _fileName = file;
  _liveScore = 0;
  openFile();
}

int			Score::getLive() const
{
  return (_liveScore);
}

int			Score::getHighScore() const
{
  return (_highScore);
}

void			Score::setLive(int nb)
{
  _liveScore = nb;
}

void			Score::addLive(int nb)
{
  _liveScore += nb;
}

void			Score::setHighScore(int nb)
{
  _highScore = nb;
}

void			Score::saveHighScore() const
{
  std::ofstream		file(_fileName.c_str(), std::ios::out | std::ios::trunc);
  if (file)
    {
      file << _highScore << std::endl;
      file.close();
    } 
  else
    std::cerr << "Fail write HighScore file" << std::endl;
}

bool			Score::isBetter() const
{
  return (_liveScore > _highScore ? true : false);
}

void			Score::openFile()
{
  std::string		str;
  std::ifstream		file(_fileName.c_str(), std::ios::in);
  
  if (file)
    {
      getline(file, str);
      std::istringstream  str2(str);
      str2 >> _highScore;
      file.close();
    }
  else
    {
      std::cerr << "No Score file." << std::endl;
      _highScore = 0;
    }
}

void			Score::displayLive() const
{
  std::cout << "Live Score : " << _liveScore << std::endl;
}

void			Score::displayHighScore()
{
  if (isBetter())
    {
      _highScore = _liveScore;
      saveHighScore();
      std::cout << "New HighScore : " << _highScore << " !" << std::endl;
    }
}
