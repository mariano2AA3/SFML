#ifndef _SCORE_H_
#define _SCORE_H_

#include <SFML/Graphics.hpp>

class Score{

public:
   Score ();
   void showScore (sf::RenderWindow& window);
   void showMessage (sf::RenderWindow& window, std::string msg, int x, int y, int transparency, unsigned int size);
   void showFPS (sf::RenderWindow& window, int x, int y);
   void addPointPlayer ();
   void addPointCPU ();

private:


   sf::Font          _font;
   sf::Text          _textPlayer;
   sf::Text          _textCpu;
   unsigned int     _pointsPlayer;
   unsigned int     _pointsCpu;
   int getFrameRate();


};

#endif // _SCORE_H_
