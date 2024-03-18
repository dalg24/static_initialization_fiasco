#include "libA.hpp"
#include "libA_backend_registry.hpp"

#include <iostream>

LIBA_INSTANTIATE_REGISTRY(libA::BackendRegistry)

namespace {
std::vector<std::unique_ptr<libA::Base>> registered_backends;
}

void libA::initialize(int&, char**) {
  std::cout << "Initialize all backends\n";
  for (auto const& entry : BackendRegistry::get_entries()) {
    std::cout << entry->get_name() << " (" << entry->get_desc() << ")\n";
    registered_backends.push_back(entry->instantiate());
  }
  for (auto const& backend : registered_backends) {
    backend->initialize();
  }
  std::cout << "Initialization done\n";
}

void libA::finalize() {
  std::cout << "Finalize all backends\n";
  for (auto const& backend : registered_backends) {
    backend->finalize();
  }
  std::cout << "Finalization done\n";
}
