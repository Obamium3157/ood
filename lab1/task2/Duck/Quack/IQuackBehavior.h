#ifndef OOD_IQUACKBEHAVIOR_H
#define OOD_IQUACKBEHAVIOR_H

class IQuackBehavior
{
public:
  virtual ~IQuackBehavior() = default;
  virtual void Quack() const = 0;
};

#endif //OOD_IQUACKBEHAVIOR_H
