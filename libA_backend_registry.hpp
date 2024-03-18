#pragma once

#include "libA_registry.hpp"

namespace libA {

struct Base {
  virtual ~Base() = default;

  virtual void initialize() = 0;
  virtual void finalize()   = 0;
};

template <class T>
struct Derived : Base {
  void initialize() override { T::initialize(); }
  void finalize() override { T::finalize(); }
};

using BackendRegistry = Registry<Base>;

}  // namespace libA
