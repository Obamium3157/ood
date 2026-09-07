#ifndef OOD_QUACKBEHAVIOR_H
#define OOD_QUACKBEHAVIOR_H
#include <iostream>

#include "IQuackBehavior.h"

class QuackBehavior : public IQuackBehavior
{
public:
  void Quack() const override
  {
    std::cout << "Quack!\n";
  }
};

#endif //OOD_QUACKBEHAVIOR_H
