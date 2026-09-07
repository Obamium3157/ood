#ifndef OOD_FLYBEHAVIORS_H
#define OOD_FLYBEHAVIORS_H

#include <iostream>
#include <functional>

using FlyBehavior = std::function<void()>;
using OnFlightCallback = std::function<void(unsigned int)>;

inline FlyBehavior FlyWithWings(const OnFlightCallback& onFlight)
{
  auto flightCount = std::make_shared<unsigned int>(0);

  return [onFlight, flightCount]() mutable
  {
    (*flightCount)++;
    std::cout << "make you take me on your mighty wings ~\n";
    if (onFlight)
    {
      onFlight(*flightCount);
    }
    std::cout << "That was flight #" << *flightCount << "\n";
  };
}

inline FlyBehavior FlyNoWay()
{
  return [] { };
}

#endif //OOD_FLYBEHAVIORS_H
