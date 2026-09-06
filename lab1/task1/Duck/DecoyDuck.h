#ifndef OOD_DECOYDUCK_H
#define OOD_DECOYDUCK_H

#include "Duck.h"
#include "Fly/FlyNoWay.h"
#include "Quack/MuteQuackBehavior.h"

class DecoyDuck : public Duck
{
public:
  DecoyDuck()
    : Duck(std::make_unique<MuteQuackBehavior>(),
           std::make_unique<FlyNoWay>())
  {
  }

  void Display() const override
  {
    std::cout << "definitely not a decoy duck ;)\n";
  }
};

#endif //OOD_DECOYDUCK_H
