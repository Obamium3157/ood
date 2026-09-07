#ifndef OOD_DANCEBEHAVIORS_H
#define OOD_DANCEBEHAVIORS_H

#include <functional>
#include <iostream>

using DanceBehavior = std::function<void()>;

inline void DanceMinuet()
{
  std::cout << "Minueting\n";
}

inline void DanceWaltz()
{
  std::cout << "Dancing waltz\n";
}

inline void DanceNoWay() { }

#endif //OOD_DANCEBEHAVIORS_H
