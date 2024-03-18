#include "libA_apple.hpp"

#include <iostream>

void libA::Apple::initialize() { std::cout << "-- initialized Apple\n"; }

void libA::Apple::finalize() { std::cout << "-- finalized Apple\n"; }

void libA::Apple::print_info(std::ostream& os) const {
  os << "print info Apple\n";
}
