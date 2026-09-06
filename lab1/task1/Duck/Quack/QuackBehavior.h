#ifndef OOD_QUACKBEHAVIOR_H
#define OOD_QUACKBEHAVIOR_H
#include <iostream>

#include "IQuackBehavior.h"

class QuackBehavior : public IQuackBehavior
{
public:
  void Quack() override
  {
    std::cout << "Quack!\n";
  }
};

#endif //OOD_QUACKBEHAVIOR_H
