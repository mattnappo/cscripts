#ifndef __MAIN_HPP__
#define __MAIN_HPP__

template <class Derived>
struct Base {
  void interface() {
    static_cast<Derived*>(this)->impl();
  }
};

struct D1 : Base<D1> {
  void impl();
};

struct D2 : Base<D2> {
  void impl();
};

#endif
