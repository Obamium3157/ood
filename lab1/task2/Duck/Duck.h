#ifndef OOD_DUCK_H
#define OOD_DUCK_H

#include <iostream>
#include <memory>

#include "Dance/IDanceBehavior.h"
#include "Fly/IFlyBehavior.h"
#include "Quack/IQuackBehavior.h"

class Duck
{
public:
  Duck(std::unique_ptr<IQuackBehavior>&& quackBehavior,
       std::unique_ptr<IFlyBehavior>&& flyBehavior,
       std::unique_ptr<IDanceBehavior>&& danceBehavior)
    : m_quackBehavior{std::move(quackBehavior)}
    , m_flyBehavior{std::move(flyBehavior)}
    , m_danceBehavior{std::move(danceBehavior)}
  {
  }

  virtual ~Duck() = default;

  void PerformQuack() const
  {
    m_quackBehavior->Quack();
  }

  void PerformFly() const
  {
    m_flyBehavior->Fly();
  }

  void PerformDance() const
  {
    m_danceBehavior->Dance();
  }

  void Swim() const
  {
    std::cout << "Swimmin'~\n";
  }

  virtual void Display() const = 0;

protected:
  std::unique_ptr<IQuackBehavior> m_quackBehavior;
  std::unique_ptr<IFlyBehavior> m_flyBehavior;
  std::unique_ptr<IDanceBehavior> m_danceBehavior;
};


#endif //OOD_DUCK_H
