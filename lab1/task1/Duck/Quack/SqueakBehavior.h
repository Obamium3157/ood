#ifndef OOD_SQUEAKBEHAVIOR_H
#define OOD_SQUEAKBEHAVIOR_H

#include <iostream>

#include "IQuackBehavior.h"

class SqueakBehavior : public IQuackBehavior
{
public:
  void Quack() override
  {
    std::cout << "Squeak!\n";
  }
};

#endif //OOD_SQUEAKBEHAVIOR_H
