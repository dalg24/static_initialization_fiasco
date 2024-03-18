#include "libA_banana.hpp"
#include <iostream>

void libA::Banana::initialize() { std::cout << "-- initialized Banana\n"; }

void libA::Banana::finalize() { std::cout << "-- finalized Banana\n"; }

void libA::Banana::print_info(std::ostream& os) const {
  os << "print info Banana\n";
}
