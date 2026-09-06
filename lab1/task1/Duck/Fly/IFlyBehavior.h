#ifndef OOD_IFLYBEHAVIOR_H
#define OOD_IFLYBEHAVIOR_H

class IFlyBehavior
{
public:
  virtual ~IFlyBehavior() {}
  virtual void Fly() = 0;
};

#endif //OOD_IFLYBEHAVIOR_H
