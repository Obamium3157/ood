#ifndef OOD_MUTEQUACKBEHAVIOR_H
#define OOD_MUTEQUACKBEHAVIOR_H

#include "IQuackBehavior.h"

class MuteQuackBehavior : public IQuackBehavior
{
public:
  void Quack() override { }
};

#endif //OOD_MUTEQUACKBEHAVIOR_H
