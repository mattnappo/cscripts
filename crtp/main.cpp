#include <cstdio>

#include "main.hpp"

void D1::impl() {
  std::puts("D1::impl()");
}

void D2::impl() {
  std::puts("D2::impl()");
}

int main() {
  D1 d1;
  d1.interface();

  D2 d2;
  d2.interface();
}

