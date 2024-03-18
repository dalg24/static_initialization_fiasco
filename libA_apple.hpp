#pragma once

#include <iosfwd>

namespace libA {
struct Apple {
  static void initialize();
  static void finalize();
  void print_info(std::ostream& os) const;
};
}  // namespace libA
