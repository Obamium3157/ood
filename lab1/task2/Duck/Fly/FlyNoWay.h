#ifndef OOD_FLYNOWAY_H
#define OOD_FLYNOWAY_H

#include "IFlyBehavior.h"

class FlyNoWay : public IFlyBehavior
{
public:
  void Fly() override { }

  std::optional<unsigned int> GetFlightCount() const override
  {
    return std::nullopt;
  }
};

#endif //OOD_FLYNOWAY_H
