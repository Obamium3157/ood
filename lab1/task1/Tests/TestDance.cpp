#include <catch2/catch_test_macros.hpp>

#include "../Duck/Duck.h"
#include "..//Duck/Fly/FlyNoWay.h"
#include "../Duck/Dance/DanceNoWay.h"
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

  class BinaryDanceBehavior : public IDanceBehavior
  {
  public:
    void Dance() const override
    {
      m_hasDanced = true;
    }

    bool GetHasDanced() const
    {
      return m_hasDanced;
    }

  private:
    mutable bool m_hasDanced = false;
  };

  class MockFlyBehavior : public IFlyBehavior
  {
  public:
    void Fly() const override
    {
      m_flyCount++;
    }

    unsigned int GetFlyCount() const
    {
      return m_flyCount;
    }

  private:
    mutable unsigned int m_flyCount = 0;
  };

  class MockQuackBehavior : public IQuackBehavior
  {
  public:
    void Quack() const override
    {
      m_quackCount++;
    }

    unsigned int GetQuackCount() const
    {
      return m_quackCount;
    }

  private:
    mutable unsigned int m_quackCount = 0;
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

  class FlyingDuck : public Duck
  {
  public:
    FlyingDuck(std::unique_ptr<MockFlyBehavior>&& flyBehavior)
      : Duck(std::make_unique<MuteQuackBehavior>(),
             std::move(flyBehavior),
             std::make_unique<DanceNoWay>())
    {
    }

    void Display() const override { }
  };

  class QuackingDuck : public Duck
  {
  public:
    QuackingDuck(std::unique_ptr<MockQuackBehavior>&& quackBehavior)
      : Duck(std::move(quackBehavior),
             std::make_unique<FlyNoWay>(),
             std::make_unique<DanceNoWay>())
    {
    }

    void Display() const override { }
  };
}

// TODO: добавить тест (вызов одной стратегии не виляет на другие стратегии)

TEST_CASE("A dancing duck can dance", "[StandardBehaviorCheck]")
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

TEST_CASE("A flying duck can fly", "[StandardBehaviorCheck]")
{
  auto flyBehavior = std::make_unique<MockFlyBehavior>();
  const auto* flyBehaviorRef = flyBehavior.get();

  FlyingDuck duck(std::move(flyBehavior));

  CHECK(flyBehaviorRef->GetFlyCount() == 0);
  duck.PerformFly();
  CHECK(flyBehaviorRef->GetFlyCount() == 1);
}

TEST_CASE("A quacking duck can quack", "[StandardBehaviorCheck]")
{
  auto quackBehavior = std::make_unique<MockQuackBehavior>();
  const auto* quackBehaviorRef = quackBehavior.get();

  QuackingDuck duck(std::move(quackBehavior));

  CHECK(quackBehaviorRef->GetQuackCount() == 0);
  duck.PerformQuack();
  CHECK(quackBehaviorRef->GetQuackCount() == 1);
}


TEST_CASE("Strategy is changeable in runtime", "[ChangeBehavior]")
{
  auto mockDanceBehavior = std::make_unique<MockDanceBehavior>();
  const auto* mockDanceBehaviorRef = mockDanceBehavior.get();

  auto binaryDanceBehavior = std::make_unique<BinaryDanceBehavior>();
  const auto* binaryDanceBehaviorRef = binaryDanceBehavior.get();

  DancingDuck duck(std::move(mockDanceBehavior));
  CHECK(mockDanceBehaviorRef->GetDanceCount() == 0);
  duck.PerformDance();
  CHECK(mockDanceBehaviorRef->GetDanceCount() == 1);

  duck.SetDanceBehavior(std::move(binaryDanceBehavior));
  CHECK(binaryDanceBehaviorRef->GetHasDanced() == false);
  duck.PerformDance();
  CHECK(binaryDanceBehaviorRef->GetHasDanced() == true);
}