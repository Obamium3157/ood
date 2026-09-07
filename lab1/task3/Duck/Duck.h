#ifndef OOD_DUCK3_H
#define OOD_DUCK3_H

#include <iostream>
#include <memory>

#include "Behaviors/QuackBehaviors.h"
#include "Behaviors/FlyBehaviors.h"
#include "Behaviors/DanceBehaviors.h"

class Duck
{
public:
  Duck(std::unique_ptr<QuackBehavior>&& quackBehavior,
       std::unique_ptr<FlyBehavior>&& flyBehavior,
       std::unique_ptr<DanceBehavior>&& danceBehavior)
    : m_quackBehavior(std::move(quackBehavior))
    , m_flyBehavior(std::move(flyBehavior))
    , m_danceBehavior(std::move(danceBehavior))
  {
  }

  virtual ~Duck() = default;

  void PerformQuack() const
  {
    if (m_quackBehavior)
    {
      (*m_quackBehavior)();
    }
  }

  void PerformFly() const
  {
    if (m_flyBehavior)
    {
      (*m_flyBehavior)();
    }
  }

  void PerformDance() const
  {
    if (m_danceBehavior)
    {
      (*m_danceBehavior)();
    }
  }

  void Swim() const
  {
    std::cout << "Swimmin'~\n";
  }

  virtual void Display() const = 0;

protected:
  std::unique_ptr<QuackBehavior> m_quackBehavior;
  std::unique_ptr<FlyBehavior> m_flyBehavior;
  std::unique_ptr<DanceBehavior> m_danceBehavior;
};

#endif //OOD_DUCK3_H
