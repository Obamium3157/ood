#ifndef OOD_DUCK_H
#define OOD_DUCK_H

#include <iostream>
#include <memory>

#include "Fly/IFlyBehavior.h"
#include "Quack/IQuackBehavior.h"

class Duck
{
public:
  Duck(std::unique_ptr<IQuackBehavior>&& quackBehavior,
       std::unique_ptr<IFlyBehavior>&& flyBehavior)
    : m_quackBehavior{std::move(quackBehavior)}
    , m_flyBehavior{std::move(flyBehavior)}
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

  void Swim() const
  {
    std::cout << "Swimmin'~\n";
  }

  virtual void Display() const = 0;

private:
  std::unique_ptr<IQuackBehavior> m_quackBehavior;
  std::unique_ptr<IFlyBehavior> m_flyBehavior;
};


#endif //OOD_DUCK_H
