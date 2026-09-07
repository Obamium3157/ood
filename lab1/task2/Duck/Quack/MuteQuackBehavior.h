#ifndef OOD_MUTEQUACKBEHAVIOR_H
#define OOD_MUTEQUACKBEHAVIOR_H

#include "IQuackBehavior.h"

class MuteQuackBehavior : public IQuackBehavior
{
public:
  void Quack() const override { }
};

#endif //OOD_MUTEQUACKBEHAVIOR_H
