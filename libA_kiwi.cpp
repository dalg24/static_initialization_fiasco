#include "libA_kiwi.hpp"
#include "libA_backend_registry.hpp"

#include <iostream>

void libA::Kiwi::initialize() { std::cout << "-- initialized Kiwi\n"; }

void libA::Kiwi::finalize() { std::cout << "-- finalized Kiwi\n"; }

void libA::Kiwi::print_info(std::ostream& os) const {
  os << "print info Kiwi\n";
}

namespace {
libA::BackendRegistry::Add<libA::Derived<libA::Kiwi>> X(
    "Kiwi", "description goes here");
}

