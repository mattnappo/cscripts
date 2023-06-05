#include <iostream>
#include <string>
#include <typeinfo>

#include "main.hpp"

// implementation code

template <typename T>
void VerbsBuffer<T>::write_impl(T v) {
  std::puts("ibverbs write");
}

template <typename T>
T VerbsBuffer<T>::read_impl() {
  std::puts("ibverbs read");
  return nullptr;
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

int main() {
    LibfabricBuffer<std::string> lf_buf("start");
    lf_buf.read();
    //lf_buf.write("done");
    //lf_buf.read();

    //VerbsBuffer<int> ib_buf;
    //ib_buf.read();
    //ib_buf.write(15);
}

