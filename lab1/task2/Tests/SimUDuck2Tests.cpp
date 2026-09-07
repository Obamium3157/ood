#include <functional>
#include <catch2/catch_test_macros.hpp>

#include "../../task1/Duck/Dance/DanceNoWay.h"
#include "../../task1/Duck/Quack/IQuackBehavior.h"
#include "../Duck/Duck.h"
#include "../Duck/Fly/IFlyBehavior.h"

namespace
{
  class MockFlyBehavior : public IFlyBehavior
  {
  public:
    MockFlyBehavior(std::function<void()>&& onFlight)
      : m_onFlight(std::move(onFlight))
    {
    }

    void Fly() override
    {
      m_flightCounter++;
      m_onFlight();
    }

    std::optional<unsigned int> GetFlightCount() const override
    {
      return m_flightCounter;
    }

  private:
    unsigned int m_flightCounter = 0;
    std::function<void()> m_onFlight;
  };

  class MockUncountedFlyBehavior : public IFlyBehavior
  {
  public:
    MockUncountedFlyBehavior(std::function<void()>&& onFlight)
      : m_onFlight(std::move(onFlight))
    {
    }

    void Fly() override
    {
      m_onFlight();
    }

    std::optional<unsigned int> GetFlightCount() const override
    {
      return std::nullopt;
    }

  private:
    std::function<void()>&& m_onFlight;
  };

  class MockQuackBehavior : public IQuackBehavior
  {
  public:
    void Quack() const override
    {
      m_quackCallCount++;
    }

    unsigned int GetQuackCallCount() const
    {
      return m_quackCallCount;
    }

  private:
    mutable unsigned int m_quackCallCount = 0;
  };

  template <typename FLyBehavior>
  class FlyingQuackingDuck : public Duck
  {
  public:
    FlyingQuackingDuck(std::unique_ptr<IQuackBehavior>&& quackBehavior)
      : Duck(std::move(quackBehavior),
             std::make_unique<FLyBehavior>([this] { OnFly(); }),
             std::make_unique<DanceNoWay>())
    {
    }

    void Display() const override { }

  private:
    void OnFly()
    {
      if (const auto flights = m_flyBehavior->GetFlightCount();
        flights && *flights % 2 == 0 && *flights != 0)
      {
        m_quackBehavior->Quack();
      }
    }
  };
}

TEST_CASE("A flying duck quacks with pleasure after each second flight")
{
  auto quackBehavior = std::make_unique<MockQuackBehavior>();
  const auto* quackBehaviorPtr = quackBehavior.get();

  FlyingQuackingDuck<MockFlyBehavior> duck(std::move(quackBehavior));

  CHECK(quackBehaviorPtr->GetQuackCallCount() == 0);
  duck.PerformFly();
  CHECK(quackBehaviorPtr->GetQuackCallCount() == 0);

  CHECK(quackBehaviorPtr->GetQuackCallCount() == 0);
  duck.PerformFly();
  CHECK(quackBehaviorPtr->GetQuackCallCount() == 1);

  CHECK(quackBehaviorPtr->GetQuackCallCount() == 1);
  duck.PerformFly();
  CHECK(quackBehaviorPtr->GetQuackCallCount() == 1);

  CHECK(quackBehaviorPtr->GetQuackCallCount() == 1);
  duck.PerformFly();
  CHECK(quackBehaviorPtr->GetQuackCallCount() == 2);
}

TEST_CASE("A duck never quacks if its fly behavior cannot count flights")
{
  auto quackBehavior = std::make_unique<MockQuackBehavior>();
  const auto* quackBehaviorPtr = quackBehavior.get();

  FlyingQuackingDuck<MockUncountedFlyBehavior> duck(std::move(quackBehavior));

  for (int i = 0; i < 10; ++i)
  {
    duck.PerformFly();
  }

  CHECK(quackBehaviorPtr->GetQuackCallCount() == 0);
}