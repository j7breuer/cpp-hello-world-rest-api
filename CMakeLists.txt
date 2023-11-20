# Set version and project name
cmake_minimum_required(VERSION 3.10)
project(MyHelloWorldApi)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the path to Boost
set(BOOST_ROOT "./lib/boost")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")
set(Boost_NO_SYSTEM_PATHS ON)

# Find Boost
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Include Crow
include_directories("../lib/crow/include")

# Define your executable and source files
add_executable(helloWorldApi src/main.cpp)

# Link Boost libraries (if you use compiled Boost components)
target_link_libraries(helloWorldApi ${Boost_LIBRARIES})
