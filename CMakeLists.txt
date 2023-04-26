cmake_minimum_required(VERSION 3.7...3.25)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(GroupProject
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
SET_SOURCE_FILES_PROPERTIES(${SOURCE_FILES} PROPERTIES LANGUAGE CXX)
set(SOURCE_FILES src/main.cpp src/DataSetGenerator.cpp src/DataSetGenerator.h src/SortingAlgo.h src/SortingAlgoImpl.h src/SortingAlgoExample.h src/SortingAlgoExample.cpp src/SortingAlgoDriver.h src/ImprovedBubbleSort.cpp src/ImprovedBubbleSort.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
