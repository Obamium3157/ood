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
        Duck/DecoyDuck.h)