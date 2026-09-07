#ifndef OOD_DANCEMINUET_H
#define OOD_DANCEMINUET_H

#include <iostream>

#include "IDanceBehavior.h"

class DanceMinuet : public IDanceBehavior
{
public:
  void Dance() const override
  {
    std::cout << "Minueting\n";
  }
};

#endif //OOD_DANCEMINUET_H
