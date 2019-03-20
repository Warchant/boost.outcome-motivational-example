cmake_minimum_required(VERSION 3.5)

include("cmake/Hunter/HunterGate.cmake")
HunterGate(
  URL "https://github.com/ruslo/hunter/archive/v0.23.135.tar.gz"
  SHA1 "72eecdf1dea9fb6299d7fb61bbd00bd4ca170fa4"
)

project(example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

hunter_add_package(Boost)
find_package(Boost REQUIRED)

include_directories(
  deps/outcome/single-header
)

add_executable(main main.cpp)
target_link_libraries(main Boost::boost)
