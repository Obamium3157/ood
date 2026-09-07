#ifndef OOD_FLYWITHWINGS_H
#define OOD_FLYWITHWINGS_H

#include <iostream>

#include "IFlyBehavior.h"

class FlyWithWings : public IFlyBehavior
{
public:
  void Fly() const override
  {
    std::cout << "make you take me on your mighty wings ~\n";
  }
};

#endif //OOD_FLYWITHWINGS_H
