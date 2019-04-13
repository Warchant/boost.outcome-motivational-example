add_library(errc error.cpp)
target_link_libraries(errc
  Boost::boost
  )

add_executable(main main.cpp)
target_link_libraries(main
  errc
  )
