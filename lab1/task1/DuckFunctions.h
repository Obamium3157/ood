#ifndef OOD_DUCKFUNCTIONS_H
#define OOD_DUCKFUNCTIONS_H

#include <iostream>

#include "Duck/Duck.h"

inline void DrawDuck(const Duck& duck)
{
  duck.Display();
}

inline void PlayWithDuck(const Duck& duck)
{
  DrawDuck(duck);
  duck.PerformQuack();
  duck.PerformFly();
  duck.PerformDance();
  std::cout << "\n";
}


#endif //OOD_DUCKFUNCTIONS_H
