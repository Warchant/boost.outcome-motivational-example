add_library(errc error.cpp)

add_executable(main main.cpp)
target_link_libraries(main
  Boost::boost
  errc
  )
