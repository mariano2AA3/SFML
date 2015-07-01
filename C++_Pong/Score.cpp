#include "Score.h"
#include "Config.hpp"
#include <sstream>

Score::Score(){
   _pointsPlayer = 0;
   _pointsCpu = 0;
   _font.loadFromFile("fonts/University.ttf");

   _textPlayer.setFont(_font);
   _textPlayer.setCharacterSize(30);
   _textPlayer.setColor(sf::Color::Blue);
   _textPlayer.setPosition(20, HEIGHT-40);

   _textCpu.setFont(_font);
   _textCpu.setCharacterSize(30);
   _textCpu.setColor(sf::Color::Red);
   _textCpu.setPosition(WIDTH-120,HEIGHT-40);
}

void Score::showScore(sf::RenderWindow& window){
   std::stringstream ss;
   std::stringstream ss2;

   ss << _pointsPlayer;
   ss2 << _pointsCpu;

   _textPlayer.setString("Player: " + ss.str());
   _textCpu.setString("CPU: " + ss2.str());

   window.draw (_textPlayer);
   window.draw (_textCpu);
}

void Score::showMessage(sf::RenderWindow& window,std::string msg, int x, int y, int transparency, unsigned int size){
   std::stringstream ss;
   sf::Text text;

   text.setFont(_font);

   ss << msg;
   text.setString(msg);
   text.setCharacterSize(size);
   text.setPosition(x,y);
   text.setColor(sf::Color(255,255,255,transparency));
   window.draw(text);

}

void Score::showFPS(sf::RenderWindow& window, int x, int y){
   int fps = 0;
   showMessage(window,"FPS: " + fps,x,y,255,25);
}

int getFrameRate(){
      static int frameCounter = 0;
      static int fps = 0;
      sf::Time thetime;
      sf::Clock elapsed;
      frameCounter++;

      thetime = elapsed.getElapsedTime();
      if(thetime.asMilliseconds() > 999)
      {
         fps = frameCounter;
         frameCounter = 0;
         elapsed.restart();
      }

      return fps;
}


void Score::addPointCPU(){
   _pointsCpu++;
}

void Score::addPointPlayer(){
   _pointsPlayer++;
}


