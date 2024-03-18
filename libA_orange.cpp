#include "libA_orange.hpp"
#include "libA_backend_registry.hpp"

#include <iostream>

void libA::Orange::initialize() { std::cout << "-- initialized Orange\n"; }

void libA::Orange::finalize() { std::cout << "-- finalized Orange\n"; }

void libA::Orange::print_info(std::ostream& os) const {
  os << "print info Orange\n";
}

namespace {
libA::BackendRegistry::Add<libA::Derived<libA::Orange>> X(
    "Orange", "description goes here");
}
