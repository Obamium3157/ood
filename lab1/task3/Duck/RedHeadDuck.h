#ifndef OOD_REDHEADDUCK_H
#define OOD_REDHEADDUCK_H

#include "Duck.h"

class RedheadDuck : public Duck
{
public:
  RedheadDuck()
    : Duck(std::make_unique<QuackBehavior>(SimpleQuack),
           std::make_unique<FlyBehavior>(
             FlyWithWings([this](const unsigned int flightCount)
           {
             if (flightCount % 2 == 0 && flightCount != 0)
             {
               (*m_quackBehavior)();
             }
           })),
           std::make_unique<DanceBehavior>(DanceMinuet))
  {
  }

  void Display() const override
  {
    std::cout << "I... am Mallard duck\n";
  }
};

#endif //OOD_REDHEADDUCK_H
