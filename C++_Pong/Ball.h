#ifndef _BALL_H_
#define _BALL_H_

#include <SFML/Graphics.hpp>
#include "Score.h"
#include "Config.hpp"

class Ball{

public:

   Ball ();
   void drawBall (sf::RenderWindow& window);
   bool moveBall (sf::FloatRect& paddle1, sf::FloatRect& paddle2, Score& score);
   bool intersects (sf::FloatRect& paddle1, sf::FloatRect& paddle2);
   void reset ();
   sf::Vector2f getSpeed ();
   int getPositionX ();
   int getPositionY ();

private:

   std::string       _path;
   sf::Vector2f       _speed;
   sf::Sprite         _sprite;
   sf::Texture        _texture;

};

#endif // _BALL_H_
