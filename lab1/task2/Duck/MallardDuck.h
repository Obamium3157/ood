#ifndef OOD_MALLARDDUCK_H
#define OOD_MALLARDDUCK_H

#include "Duck.h"
#include "Dance/DanceWaltz.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"

class MallardDuck : public Duck
{
public:
  // TODO: сделать так, чтобы в коллбеке уже была информация
  MallardDuck()
    : Duck(std::make_unique<QuackBehavior>(),
           std::make_unique<FlyWithWings>([this]{ OnFly(); }),
           std::make_unique<DanceWaltz>())
  {
  }

  void Display() const override
  {
    std::cout << "I... am Mallard duck\n";
  }

private:
  // TODO: вынести в одно место
  void OnFly()
  {
    if (const auto flights = m_flyBehavior->GetFlightCount();
      flights && *flights % 2 == 0 && *flights != 0)
    {
      m_quackBehavior->Quack();
    }
  }
};

#endif //OOD_MALLARDDUCK_H
