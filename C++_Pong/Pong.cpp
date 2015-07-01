#include <SFML/Graphics.hpp>
#include "Pong.h"
#include <stdio.h>
#include "Paddle.h"

Pong::Pong(){
   _window.create(sf::VideoMode (WIDTH,HEIGHT),"C++ Pong!");
   _window.setFramerateLimit(FPS);

   _window.setVisible(false);
   _running = true;
   _pause = false;

   _jug.createPadlle("sprites/paddleJUG.bmp",0, (HEIGHT/2 ) - 50 ,20);
   _cpu.createPadlle("sprites/paddleCPU.bmp",WIDTH-10,(HEIGHT/2 ) - 50,20);


}

void Pong::configure(int widht){

}

void Pong::run(){
   _running = true;
   _window.setVisible(true);
   while (_running == true){
      input ();
      updateModel ();
      render ();
   }

   finish ();
}

void Pong::drawLimits (){
   sf::RectangleShape line;
   line.setFillColor(sf::Color::White);

   // Up border
   line.setSize (sf::Vector2f(WIDTH,5));
   _window.draw(line);

   // Down border
   line.setPosition(0,HEIGHT-50);
   _window.draw(line);


}

void Pong::input (){
   while (_window.pollEvent(_event)){
      switch (_event.type){
      case sf::Event::Closed:
         _running = false;
         break;

      case sf::Event::KeyPressed:
         doInput();
         break;

      default:
         break;
      }
   }
}

void Pong::doInput(){
   switch(_event.key.code){
   // Spacebar
   case sf::Keyboard::Space:
      if (_pause == true) _pause = false;
      else _pause = true;
      break;

   case sf::Keyboard::Up:
      _jug.moveUp ();
      break;

   case sf::Keyboard::Down:
      _jug.moveDown ();
      break;

   default:
      break;
   }
}

void Pong::updateModel (){

   if (_pause != true){
      sf::FloatRect p1 = _jug.getGlobalBounds();
      sf::FloatRect p2 = _cpu.getGlobalBounds();

      if (_ball.moveBall(p1,p2,_score) == true){   // Player or CPU win a point
         _ball.reset();
      }
      _cpu.moveCpu(_ball);
   }

}

void Pong::render(){

   _window.clear();
   _score.showMessage(_window,"C++ Pong",(WIDTH/2)-200,50,64,80);

   if (_pause == true)  _score.showMessage(_window,"Pausa",(WIDTH/2)-50,HEIGHT/2,255,25);

   drawLimits ();
   _jug.drawPaddle (_window);
   _cpu.drawPaddle (_window);
   _ball.drawBall (_window);
   _score.showScore (_window);

   _window.display ();
}

void Pong::finish (){
   _window.close ();
}


