#ifndef OOD_DUCKFUNCTIONS_H
#define OOD_DUCKFUNCTIONS_H

#include <iostream>

#include "Duck/Duck.h"

inline void DrawDuck(const Duck& duck)
{
  duck.Display();
}

inline void PerformMultipleFlights(const Duck& duck)
{
  for (int i = 0; i < 5; ++i)
  {
    duck.PerformFly();
  }
}

inline void PlayWithDuck(const Duck& duck)
{
  DrawDuck(duck);
  duck.PerformQuack();
  PerformMultipleFlights(duck);
  duck.PerformDance();
  std::cout << "\n";
}


#endif //OOD_DUCKFUNCTIONS_H
