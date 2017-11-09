//
// Game.cpp for Nibbler in /home/almozi_c/rendu/Nibbler
// 
// Made by Claire ALMOZINOS
// Login   <almozi_c@epitech.net>
// 
// Started on  Wed Mar 12 09:41:12 2014 Claire ALMOZINOS
// Last update Sat Apr  5 16:25:47 2014 Claire Almozinos
//

#include		"Game.hpp"
#include		"Action.hpp"

Game::Game(int xmax, int ymax, IGraph *lib)
{
  int			sx;
  int			sy;

  _snake.push_back(new Snake(xmax / 2, ymax / 2, xmax, ymax, true));
  for (int i = 0; i < 3; ++i)
    _snake.push_back(new Snake((xmax / 2) + i + 1, (ymax / 2),
			       xmax, ymax));
  _head = *(_snake.begin());
  _sizeSnake = 4;
  sx = setRandPos(xmax);
  sy = setRandPos(ymax);
  _fruit = new Fruit(sx, sy, 1);
  _score = new Score("myScore.txt");
  _fruitTurn = false;
  _lib = lib;
  _xMove = -1;
  _yMove = 0;
  _i = 0;
  _mySleep = 100000;
}

Game::~Game()
{
  delete _fruit;
  delete _score;
  _snake.erase (_snake.begin(),_snake.end());
}

std::vector<Snake *>	*Game::getSnake()
{
  return (&_snake);
}

Snake			*Game::getHead() const
{
  return (_head);
}

Fruit			*Game::getFruit() const
{
  return (_fruit);
}

IGraph			*Game::getLib() const
{
  return (_lib);
}

int			Game::getSizeSnake() const
{
  return (_sizeSnake);
}

int			Game::getXmove() const
{
  return (_xMove);
}

int			Game::getYmove() const
{
  return (_yMove);
}

void			Game::howSleep(bool decr)
{
  if (decr)
    _mySleep -= 2000;
  else
    usleep(_mySleep);
}

void			Game::setFruit()
{
  int			value;

  srand(time(NULL));
  value = 0;
  while (value < 1)
    value = rand() % 4;
  _fruit->setX(setRandPos(_head->getXMax()));
  _fruit->setY(setRandPos(_head->getYMax()));
  _fruit->setValue(value);
}

int			Game::setRandPos(int max)
{
  int			i;
  int			p;

  srand(time(NULL));
  i = 0;
  p = rand() % max;
  while (p == 0 || p == max || (p == i && i < _sizeSnake))
    {
      p = rand() % max;
      i = (max / 2) + i;
      i++;
    }
  return (p);
}

void			Game::setSizeSnake()
{
  _sizeSnake = _snake.size();
}

bool			Game::haveLoose(int x, int y) const
{
  if (!this->_fruitTurn)
    {
      for (std::vector<Snake *>::const_iterator it = _snake.begin();
	   it != _snake.end(); ++it)
	{
	  if (x < 0 || y < 0 || x >= (*it)->getXMax() || y >= (*it)->getYMax())
	    return (true);
	  if ((*it)->getX() == x && (*it)->getY() == y && it != _snake.begin())
	    return (true);
	}
    }
  return (false);
}

void			Game::addPart(int nb)
{
  revItSnake it = _snake.rbegin();
  Snake			*last = (*it);

  _score->addLive(nb);
  _lib->displayLiveScore(_score->getLive());
  for (int i = 0; i < nb; ++i)
    {
      _snake.push_back(new Snake(last->getX() + i*_xMove + _xMove,
  				 last->getY() + i*_yMove + _yMove,
  				 last->getXMax(), last->getYMax()));
    }
  howSleep(true);
}

void			Game::moveHead(int x, int y, revItSnake rit)
{
  (*rit)->setX((*rit)->getX() + x);
  (*rit)->setY((*rit)->getY() + y);
  if (_fruit->isFruit(_head->getX(), _head->getY()))
    {
      _fruitTurn = true;
      addPart(_fruit->getValue());
      setFruit();
      _lib->display(_fruit->getX(), _fruit->getY(), _fruit->getValue() + 2, _score->getLive());
    }
  _lib->display((*rit)->getX(), (*rit)->getY(), 2, _score->getLive());
}

void			Game::move(int x, int y, int lastX, int lastY, revItSnake rit2)
{
  for (revItSnake rit = _snake.rbegin(); rit != _snake.rend(); ++rit)
    {
      if ((*rit)->isHead())
	moveHead(x, y, rit);
      else
	{
	  (*rit)->setX((*rit2)->getX());
	  (*rit)->setY((*rit2)->getY());
	  _lib->display((*rit)->getX(), (*rit)->getY(), 1, _score->getLive());
	}
      if (rit2 != _snake.rend())
	rit2++;
    }
  if (!(_fruit->isFruit(lastX, lastY)))
    _lib->display(lastX, lastY, 0, _score->getLive());
  else
    _lib->display(_fruit->getX(), _fruit->getY(), _fruit->getValue() + 2, _score->getLive());
}

void			Game::moveInit(int flag)
{
  int			lastX;
  int			lastY;

  if (flag)
    setDirection(flag);
  _snake.reserve(_snake.size() + _fruit->getValue());
  revItSnake rit2 = _snake.rbegin();
  lastX = (*rit2)->getX();
  lastY = (*rit2)->getY();
  rit2++;
  _fruitTurn = false;
  move(_xMove, _yMove, lastX, lastY, rit2);
}

void			Game::setDirection(int flag)
{
  int			xTab[4];
  int			yTab[4];

  xTab[0] = -1;
  xTab[1] = 0;
  xTab[2] = 1;
  xTab[3] = 0;
  yTab[0] = 0;
  yTab[1] = 1;
  yTab[2] = 0;
  yTab[3] = -1;
  _i -= flag;
  if (_i >= 4)
    _i = 0;
  else if (_i < 0)
    _i = 3;
  _xMove = xTab[_i];
  _yMove = yTab[_i];
}

void			Game::manage(int nbr1, int nbr2)
{
  Action::initAction(this);
  this->_lib->init(nbr1, nbr2, _score->getHighScore());
  this->setFruit();
  this->_lib->display(this->getFruit()->getX(), this->getFruit()->getY(),
	       this->getFruit()->getValue() + 2, _score->getLive());
  while (!this->haveLoose(this->_head->getX(), this->_head->getY()))
    {
      this->_lib->getEvent();
      this->moveInit(0);
      this->howSleep(false);
    }
  this->_lib->stop();
  _score->displayHighScore();
}
