#include "libA_apple.hpp"
#include "libA_backend_registry.hpp"

namespace {
libA::BackendRegistry::Add<libA::Derived<libA::Apple>> X("Apple",
                                                         "hello world!");
}

