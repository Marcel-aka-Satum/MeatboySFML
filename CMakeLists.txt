cmake_minimum_required(VERSION 3.21)
project(projectAP)

set(CMAKE_CXX_STANDARD 14)

add_executable(projectAP main.cpp src/Representation/Game.cpp src/Representation/Game.h src/Logic/AbstractFactory.h src/Logic/World.cpp src/Logic/World.h src/Logic/Camera.cpp src/Logic/Camera.h
        src/Logic/Observer.cpp src/Logic/Observer.h src/Logic/EntityLogic.cpp src/Logic/EntityLogic.h src/Representation/Entity.cpp src/Representation/Entity.h src/Representation/ConcreteWindow.cpp src/Representation/ConcreteWindow.h src/Logic/AbstractWindow.h src/Representation/ConcreteFactory.cpp src/Representation/ConcreteFactory.h src/Logic/Subject.h src/Logic/StopWatch.h src/Logic/StopWatch.cpp src/Representation/State.h src/Representation/StateManager.cpp src/Representation/StateManager.h src/Representation/Menu.cpp src/Representation/Menu.h src/Representation/MenuLevel.cpp src/Representation/MenuLevel.h src/Representation/Level.cpp src/Representation/Level.h Parser/tinystr.cpp Parser/tinystr.h Parser/tinyxml.cpp Parser/tinyxml.h Parser/tinyxmlerror.cpp Parser/tinyxmlparser.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS audio system graphics window network REQUIRED)

include_directories(C:/SFML-2.5.1/include)
target_link_libraries(projectAP sfml-system sfml-graphics sfml-audio sfml-window sfml-network)