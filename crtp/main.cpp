#include <iostream>
#include <string>
#include <typeinfo>

#include "main.hpp"

// implementation code

template <typename T>
void VerbsBuffer<T>::write_impl(T v) {
  val = v;
  ++c;
  std::cout << "ibverbs<" << typeid(T).name() << ">(" << val << "," << c << ") write" << std::endl;
}

template <typename T>
T VerbsBuffer<T>::read_impl() {
  std::cout << "ibverbs<" << typeid(T).name() << ">(" << val << "," << c << ") read" << std::endl;
  return val;
}

template <typename T>
void LibfabricBuffer<T>::write_impl(T v) {
  val = v;
  std::cout << "libfabric<" << typeid(T).name() << ">(" << val << ") write" << std::endl;
}

template <typename T>
T LibfabricBuffer<T>::read_impl() {
  std::cout << "libfabric<" << typeid(T).name() << ">(" << val << ") read" << std::endl;
  return val;
}

template <class Buf, typename T>
void proc(Buf &buf, T v) {
  buf.write(v);
}

int main() {
  LibfabricBuffer<std::string> lf_buf("start");
  lf_buf.read();
  lf_buf.write("done");
  lf_buf.read();

  VerbsBuffer<int> ib_buf;
  ib_buf.read();
  ib_buf.write(15);
  ib_buf.write(17);

  proc(ib_buf, 1000000);
  proc(lf_buf, "nothing");
}

