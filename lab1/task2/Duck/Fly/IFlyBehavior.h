#ifndef OOD_IFLYBEHAVIOR_H
#define OOD_IFLYBEHAVIOR_H

class IFlyBehavior
{
public:
  virtual ~IFlyBehavior() = default;
  virtual void Fly() = 0;
  virtual std::optional<unsigned int> GetFlightCount() const = 0;
};

#endif //OOD_IFLYBEHAVIOR_H
