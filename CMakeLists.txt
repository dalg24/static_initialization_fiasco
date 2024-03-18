cmake_minimum_required(VERSION 3.12)
project(MyProject CXX)
add_library(libA
  libA.cpp
  libA_apple.cpp
  libA_apple_registered.cpp
  libA_banana.cpp
  libA_banana_registered.cpp
  libA_kiwi.cpp
  libA_orange.cpp
)
target_compile_features(libA PUBLIC cxx_std_17)
add_executable(MyExe
  main.cpp
)
target_link_libraries(MyExe PRIVATE libA)
