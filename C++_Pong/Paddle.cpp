#include "Paddle.h"


Paddle::Paddle(){
   _path = "";
   _x = 0;
   _y = 0;
   _speed.x = 0;
   _speed.y = 0;
}

void Paddle::createPadlle(std::string path,int x, int y, int speed){
   _path = path;
   _x = x;
   _y = y;
   _speed.x = speed;
   _speed.y = speed;
   if (_texture.loadFromFile(_path)){
      _sprite.setTexture(_texture);
      _sprite.setPosition(_x,_y);
   }
}

void Paddle::setPaddleColor (sf::Color color){
   _sprite.setColor(color);
}


void Paddle::drawPaddle (sf::RenderWindow& window){
   window.draw (_sprite);
}

void Paddle::setPaddlePosition (int x, int y){
   _x = x;
   _y = y;
   _sprite.setPosition(_x,_y);
}

sf::FloatRect Paddle::getGlobalBounds (){
   sf::FloatRect r =_sprite.getLocalBounds();
   return _sprite.getGlobalBounds();
}

void Paddle::moveUp(){
   if (_sprite.getPosition().y > 9){
      if (_speed.y > 0)
         _speed.y *= -1;
      _sprite.move(0,_speed.y);
   }
}

void Paddle::moveDown(){
   if (_sprite.getPosition().y < 300){
      if (_speed.y < 0)
         _speed.y *= -1;
      _sprite.move(0,_speed.y);
   }
}

void Paddle::moveCpu (Ball& ball){
	if(ball.getSpeed().x >= 0 && ball.getPositionX() >= WIDTH/2.0f){
		if(_sprite.getPosition().y < ball.getPositionY())
         _sprite.move (0,_speed.y);
		if(_sprite.getPosition().y > ball.getPositionY())
			_sprite.move(0, -_speed.y);
	}

}
