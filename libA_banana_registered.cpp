#include "libA_banana.hpp"
#include "libA_backend_registry.hpp"

namespace {
libA::BackendRegistry::Add<libA::Derived<libA::Banana>> X("Banana", "salut!!!");
}
