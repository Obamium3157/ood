#ifndef OOD_MALLARDDUCK_H
#define OOD_MALLARDDUCK_H

#include "Duck.h"
#include "Behaviors/QuackBehaviors.h"
#include "Behaviors/FlyBehaviors.h"
#include "Behaviors/DanceBehaviors.h"

class MallardDuck : public Duck
{
public:
  MallardDuck()
    : Duck(std::make_unique<QuackBehavior>(SimpleQuack),
           std::make_unique<FlyBehavior>(FlyWithWings),
           std::make_unique<DanceBehavior>(DanceWaltz))
  {
  }

  void Display() const override
  {
    std::cout << "I... am Mallard duck\n";
  }
};

#endif //OOD_MALLARDDUCK_H
