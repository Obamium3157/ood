#ifndef OOD_DECOYDUCK_H
#define OOD_DECOYDUCK_H

#include "Behaviors/QuackBehaviors.h"
#include "Behaviors/FlyBehaviors.h"
#include "Behaviors/DanceBehaviors.h"

class DecoyDuck : public Duck
{
public:
  DecoyDuck()
    : Duck(std::make_unique<QuackBehavior>(MuteQuack),
           std::make_unique<FlyBehavior>(FlyNoWay),
           std::make_unique<DanceBehavior>(DanceNoWay))
  {
  }

  void Display() const override
  {
    std::cout << "definitely not a decoy duck ;)\n";
  }
};

#endif //OOD_DECOYDUCK_H
