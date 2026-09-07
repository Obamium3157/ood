#ifndef OOD_IDANCEBEHAVIOR_H
#define OOD_IDANCEBEHAVIOR_H

class IDanceBehavior
{
public:
  virtual ~IDanceBehavior() { }
  virtual void Dance() const = 0;
};

#endif //OOD_IDANCEBEHAVIOR_H
