#ifndef OOD_ARTIFICIALDUCK_H
#define OOD_ARTIFICIALDUCK_H

#include "Duck.h"
#include "Fly/FlyNoWay.h"
#include "Quack/SqueakBehavior.h"

class ArtificialDuck : public Duck
{
public:
  ArtificialDuck()
    : Duck(std::make_unique<SqueakBehavior>(),
           std::make_unique<FlyNoWay>())
  {
  }

  void Display() const override
  {
    std::cout << "Fire at an artificial duck factory\n";
  }
};

#endif //OOD_ARTIFICIALDUCK_H
