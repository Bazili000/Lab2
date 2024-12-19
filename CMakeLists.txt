cmake_minimum_required(VERSION 3.16)

project(MyQtProject)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

set(SOURCES
    GUI.cpp
    main.cpp
    Randomizer.cpp
    PrevLabsContent/IndexChecker.cpp
    Tests/FuncTests.cpp
    Tests/LoadTests.cpp
    Tests/PersonManualTests.cpp
)

set(HEADERS
    GUI.h
    Person.h
    Randomizer.h
    PrevLabsContent/IndexChecker.h
    PrevLabsContent/ArraySequence.h
    PrevLabsContent/DynamicArray.h
    PrevLabsContent/Sequence.h
    PrevLabsContent/unique.h
    Sorts/BubbleSort.h
    Sorts/ISorter.h
    Sorts/QuickSort.h
    Sorts/ShakerSort.h
    Tests/FuncTests.h
    Tests/LoadTests.h
    Tests/OutputManager.h
    Tests/PersonManualTests.h
)

include_directories(PrevLabsContent)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Core Qt6::Gui)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui Concurrent)
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Concurrent)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
)