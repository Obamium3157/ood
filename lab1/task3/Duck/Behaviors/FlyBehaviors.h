#ifndef OOD_FLYBEHAVIORS_H
#define OOD_FLYBEHAVIORS_H

#include <iostream>
#include <functional>

using FlyBehavior = std::function<void()>;

void FlyWithWings()
{
  std::cout << "make you take me on your mighty wings ~\n";
}

void FlyNoWay() { }

#endif //OOD_FLYBEHAVIORS_H
