#ifndef OOD_ARTIFICIALDUCK_H
#define OOD_ARTIFICIALDUCK_H

#include "Behaviors/QuackBehaviors.h"
#include "Behaviors/FlyBehaviors.h"
#include "Behaviors/DanceBehaviors.h"

class ArtificialDuck : public Duck
{
public:
  ArtificialDuck()
    : Duck(std::make_unique<QuackBehavior>(Squak),
           std::make_unique<FlyBehavior>(FlyNoWay),
           std::make_unique<DanceBehavior>(DanceNoWay))
  {
  }

  void Display() const override
  {
    std::cout << "Fire at the artificial duck factory\n";
  }
};

#endif //OOD_ARTIFICIALDUCK_H
