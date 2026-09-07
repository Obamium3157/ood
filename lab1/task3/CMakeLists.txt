project(task3)

add_executable(SimUDuck3 Main.cpp
        Duck/Duck.h
        Duck/MallardDuck.h
        Duck/Behaviors/QuackBehaviors.h
        Duck/Behaviors/FlyBehaviors.h
        Duck/Behaviors/DanceBehaviors.h
        DuckFunctions.h
        Duck/RedHeadDuck.h
        Duck/ArtificialDuck.h
        Duck/DecoyDuck.h)

add_executable(SimUDuck3Tests Tests/SimUDuck3Tests.cpp)

target_link_libraries(SimUDuck3Tests PRIVATE Catch2::Catch2WithMain)