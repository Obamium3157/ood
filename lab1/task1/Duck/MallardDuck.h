#ifndef OOD_MALLARDDUCK_H
#define OOD_MALLARDDUCK_H

#include "Duck.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"

class MallardDuck : public Duck
{
public:
  MallardDuck()
    : Duck(std::make_unique<QuackBehavior>(),
           std::make_unique<FlyWithWings>())
  {
  }

  void Display() const override
  {
    std::cout << "I... am Mallard duck\n";
  }
};

#endif //OOD_MALLARDDUCK_H
