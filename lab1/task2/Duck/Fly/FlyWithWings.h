#ifndef OOD_FLYWITHWINGS_H
#define OOD_FLYWITHWINGS_H

#include <functional>
#include <iostream>

#include "IFlyBehavior.h"

class FlyWithWings : public IFlyBehavior
{
public:
  FlyWithWings(std::function<void()>&& onFlight)
    : m_onFlight(std::move(onFlight))
  {
  }

  void Fly() override
  {
    m_flightCounter++;


    std::cout << "make you take me on your mighty wings ~\n";
    m_onFlight();


    std::cout << "That was flight #" << m_flightCounter << "\n";
  }

  std::optional<unsigned int> GetNumbrOfFlights() const override
  {
    return m_flightCounter;
  }

private:
  unsigned int m_flightCounter = 0;
  std::function<void()> m_onFlight;
};

#endif //OOD_FLYWITHWINGS_H
