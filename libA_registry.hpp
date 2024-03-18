#ifndef LIBA_REGISTRY_HPP
#define LIBA_REGISTRY_HPP

#include <list>
#include <memory>
#include <string>
#include <utility>

namespace libA {

template <class T>
class RegistryEntry {
  std::string name_;
  std::string desc_;
  std::unique_ptr<T> (*ctor_)();

 public:
  RegistryEntry(std::string n, std::string d, std::unique_ptr<T> (*c)())
      : name_(std::move(n)), desc_(std::move(d)), ctor_(c) {}
  std::string const& get_name() const { return name_; }
  std::string const& get_desc() const { return desc_; }
  std::unique_ptr<T> instantiate() const { return ctor_(); }
};

template <class T>
class Registry {
 public:
  using type  = T;
  using Entry = RegistryEntry<T>;

 private:
  Registry() = delete;
  static std::list<Entry*> entries_;
  static void add_entry(Entry* entry);

 public:
  static std::list<Entry*> const& get_entries();

  template <class V>
  class Add {
    Entry entry_;
    static std::unique_ptr<T> ctor_fun_() { return std::make_unique<V>(); }

   public:
    Add(std::string name, std::string desc)
        : entry_(std::move(name), std::move(desc), ctor_fun_) {
      add_entry(&entry_);
    }
  };
};

#define LIBA_INSTANTIATE_REGISTRY(REGISTRY_CLASS)                            \
  template <class T>                                                         \
  std::list<typename libA::Registry<T>::Entry*> libA::Registry<T>::entries_; \
  template <class T>                                                         \
  void libA::Registry<T>::add_entry(                                         \
      typename libA::Registry<T>::Entry* entry) {                            \
    entries_.push_back(entry);                                               \
  }                                                                          \
  template <class T>                                                         \
  std::list<typename libA::Registry<T>::Entry*> const&                       \
  libA::Registry<T>::get_entries() {                                         \
    return entries_;                                                         \
  }                                                                          \
  template std::list<typename libA::Registry<REGISTRY_CLASS::type>::Entry*>  \
      libA::Registry<REGISTRY_CLASS::type>::entries_;                        \
  template void libA::Registry<REGISTRY_CLASS::type>::add_entry(             \
      REGISTRY_CLASS::Entry*);                                               \
  template std::list<                                                        \
      typename libA::Registry<REGISTRY_CLASS::type>::Entry*> const&          \
  libA::Registry<REGISTRY_CLASS::type>::get_entries();

}  // namespace libA

#endif

