#ifndef OOD_DANCEWALTZ_H
#define OOD_DANCEWALTZ_H

#include <iostream>

#include "IDanceBehavior.h"

class DanceWaltz : public IDanceBehavior
{
public:
  void Dance() const override
  {
    std::cout << "Dancing waltz\n";
  }
};

#endif //OOD_DANCEWALTZ_H
