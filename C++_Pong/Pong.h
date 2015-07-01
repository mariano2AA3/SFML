#ifndef _PONG_H_
#define _PONG_H_

#include <SFML/Graphics.hpp>
#include "Config.hpp"
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"

class Pong{

public:

   Pong ();
   void configure (int widht);
   void run ();
   void drawLimits ();


private:

   sf::RenderWindow     _window;
   sf::Event            _event;
   Paddle               _jug;
   Paddle               _cpu;
   Ball                 _ball;
   Score                _score;
   bool                 _running;
   bool                 _pause;


   void input ();
   void doInput ();
   void updateModel ();
   void render ();
   void finish ();


};

#endif // _PONG_H_
