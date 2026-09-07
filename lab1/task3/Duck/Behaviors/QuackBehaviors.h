#ifndef OOD_QUACKBEHAVIORS_H
#define OOD_QUACKBEHAVIORS_H

#include <iostream>
#include <functional>

using QuackBehavior = std::function<void()>;

void SimpleQuack()
{
  std::cout << "Quack!\n";
}

void Squak()
{
  std::cout << "Squak!\n";
}

void MuteQuack() { }

#endif //OOD_QUACKBEHAVIORS_H
