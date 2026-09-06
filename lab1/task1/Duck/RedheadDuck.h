#ifndef OOD_REDHEADDUCK_H
#define OOD_REDHEADDUCK_H

#include "Duck.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"

class RedheadDuck : public Duck
{
public:
  RedheadDuck()
    : Duck(std::make_unique<QuackBehavior>(),
           std::make_unique<FlyWithWings>())
  {
  }

  void Display() const override
  {
    std::cout << "Me art Redhead duck.\n";
  }
};

#endif //OOD_REDHEADDUCK_H
