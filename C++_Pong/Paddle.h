#ifndef _PADDLE_H_
#define _PADDLE_H_

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Config.hpp"

class Paddle{

public:

   Paddle ();
   void createPadlle (std::string path,int x, int y, int speed);
   void setPaddleColor (sf::Color color);
   void drawPaddle (sf::RenderWindow& window);
   void setPaddlePosition (int x, int y);
   sf::FloatRect getGlobalBounds ();
   void moveUp ();
   void moveDown ();
   void moveCpu (Ball& ball);

private:

   std::string    _path;
   int             _x;
   int             _y;
   sf::Vector2f    _speed;
   sf::Sprite      _sprite;
   sf::Texture     _texture;


};


#endif // _PADDLE_H_
