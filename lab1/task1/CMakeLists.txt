project(task1)

add_executable(SimUDuck Main.cpp
        Duck/Duck.h
        Duck/Fly/IFlyBehavior.h
        Duck/Quack/IQuackBehavior.h
        DuckFunctions.h
        Duck/MallardDuck.h
        Duck/Fly/FlyWithWings.h
        Duck/Quack/QuackBehavior.h
        Duck/Quack/SqueakBehavior.h
        Duck/Quack/MuteQuackBehavior.h
        Duck/Fly/FlyNoWay.h
        Duck/RedheadDuck.h
        Duck/ArtificialDuck.h
        Duck/DecoyDuck.h
        Duck/Dance/IDanceBehavior.h
        Duck/Dance/DanceWaltz.h
        Duck/Dance/DanceMinuet.h
        Duck/Dance/DanceNoWay.h
        ../task3/Main.cpp)

add_executable(SimUDuckTest Tests/TestDance.cpp)

target_link_libraries(SimUDuckTest PRIVATE Catch2::Catch2WithMain)