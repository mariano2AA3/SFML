#include "Ball.h"

Ball::Ball(){
   _path = "sprites/ball.bmp";
   if (_texture.loadFromFile(_path)){
      _sprite.setTexture(_texture);
      _sprite.setPosition(WIDTH/2,HEIGHT/2);
      _speed.x = -5;
      _speed.y = -5;
   }


}


void Ball::drawBall(sf::RenderWindow& window){
   window.draw(_sprite);
}

/**
   Returns true if player or cpu goal
**/
bool Ball::moveBall (sf::FloatRect& paddle1, sf::FloatRect& paddle2, Score& score){

   float left = _sprite.getPosition().x - _sprite.getOrigin().x;
   float right = _sprite.getPosition().x + _sprite.getOrigin().x;
   float top = _sprite.getPosition().y - _sprite.getOrigin().y;
   float bottom = _sprite.getPosition().y + _sprite.getOrigin().y;
   bool scored = false;

   if (left < 0 && _speed.x < 0){
      _speed.x *= -1;
      score.addPointCPU();
      scored = true;

   }
   if (right > 690 && _speed.x > 0){
      _speed.x *= -1;
      score.addPointPlayer();
      scored = true;
   }
   if ((top < 5 && _speed.y < 0) || (bottom > 340 && _speed.y > 0)){
      _speed.y *= -1;
   }

   if (this->intersects(paddle1,paddle2)){
		_speed.x *= -1;
	}

   _sprite.move(_speed.x, _speed.y);

   return scored;
}

bool Ball::intersects(sf::FloatRect& paddle1, sf::FloatRect& paddle2){
   return _sprite.getGlobalBounds().intersects(paddle1) || _sprite.getGlobalBounds().intersects(paddle2);
}

void Ball::reset (){
   _sprite.setPosition(WIDTH/2,HEIGHT/2);
}

sf::Vector2f Ball::getSpeed(){
   return _speed;
}

int Ball::getPositionX(){
   return _sprite.getPosition().x;
}

int Ball::getPositionY(){
   return _sprite.getPosition().y;
}

