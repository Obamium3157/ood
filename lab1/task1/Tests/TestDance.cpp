#include <catch2/catch_test_macros.hpp>

#include "../Duck/Duck.h"
#include "..//Duck/Fly/FlyNoWay.h"
#include "../Duck/Dance/IDanceBehavior.h"
#include "../Duck/Quack/MuteQuackBehavior.h"

namespace
{
  class MockDanceBehavior : public IDanceBehavior
  {
  public:
    void Dance() const override
    {
      m_danceCount++;
    }

    unsigned int GetDanceCount() const
    {
      return m_danceCount;
    }

  private:
    mutable unsigned int m_danceCount = 0;
  };

  class DancingDuck : public Duck
  {
  public:
    DancingDuck(std::unique_ptr<MockDanceBehavior>&& danceBehavior)
      : Duck(std::make_unique<MuteQuackBehavior>(),
             std::make_unique<FlyNoWay>(),
             std::move(danceBehavior))
    {
    }

    void Display() const override { }
  };
}

TEST_CASE("A dancing duck can dance")
{
  auto danceBehavior = std::make_unique<MockDanceBehavior>();
  const auto* danceBehaviorRef = danceBehavior.get();

  DancingDuck duck(std::move(danceBehavior));

  CHECK(danceBehaviorRef->GetDanceCount() == 0);
  duck.PerformDance();
  CHECK(danceBehaviorRef->GetDanceCount() == 1);

  for (int i = 0; i < 5; ++i)
  {
    duck.PerformDance();
  }
  CHECK(danceBehaviorRef->GetDanceCount() == 6);
}