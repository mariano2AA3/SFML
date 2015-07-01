#include <SFML/Graphics.hpp>
#include "Pong.h"
#include <iostream>
#include <stdio.h>

// Global variables
Pong pong;


// Functions and methods
int menu ();
void initGame ();
void changeOpcions ();
void showHelp ();


int main(){

   int op = 0;

   std::cout << "C++ Pong!!\n";
   std::cout << "Desarrollado por Mariano Hernandez Garcia\n";

   do{
      op = menu ();
      if (op == 0) printf ("Gracias por jugar a C++ Pong\n");
      else if (op == 1) initGame ();
      else if (op == 2) changeOpcions ();
      else if (op == 3) showHelp ();
      else printf ("Error, las opciones son 0,1,2,3\n");
   }while (op != 0);



   return 0;
}


int menu (){
   int op = 0;

   std::cout << "\n - - - - - - - MENU - - - - - - - \n";
   std::cout << " 0 - Salir\n";
   std::cout << " 1 - Nueva partida\n";
   std::cout << " 2 - Opciones\n";
   std::cout << " 3 - Ayuda\n";
   std::cout << " Opcion: ";

   std::cin >> op;
   std::cin.sync();

   return op;
}

void initGame (){
   pong.configure (800);
   pong.run();
}

void changeOpcions(){
   std::cout << "\n - - - - - - - OPCIONES - - - - - - - \n";
   std::cout <<  " - - - - - - - - -  - - - - - - - - -\n" ;
}

void showHelp (){
   std::cout << "\n - - - - - - - AYUDA - - - - - - - \n";
   std::cout << "Controles:\n";
   std::cout << " Arriba: flecha direccion arriba\n";
   std::cout << " Abajo: flecha direccion abajo\n";
   std::cout << " Pausa: barra espaciadora\n";
   std::cout <<  " - - - - - - - - -  - - - - - - - - -\n" ;
}

