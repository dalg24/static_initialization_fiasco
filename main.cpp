#include "libA.hpp"

#include <iostream>

int main(int argc, char** argv) {
  libA::initialize(argc, argv);
  {
    libA::Banana b;
    b.print_info(std::cout);
    libA::Orange o;
    o.print_info(std::cout);
  }
  libA::finalize();
  return 0;
}

