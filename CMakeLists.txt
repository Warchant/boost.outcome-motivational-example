cmake_minimum_required(VERSION 3.5)

include("cmake/Hunter/HunterGate.cmake")
HunterGate(
  URL "https://github.com/ruslo/hunter/archive/v0.23.153.tar.gz"
  SHA1 "d4c16d7474a1744eff33b832a82456852232ea60"
)

project(example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

hunter_add_package(Boost)
find_package(Boost REQUIRED)

include_directories(include)

add_subdirectory(src)
