#include <iostream>
#include <string>
#include <typeinfo>

#include "main.hpp"

// implementation code

void VerbsBuffer::write() {
  std::puts("ibverbs write");
}

void VerbsBuffer::read() {
  std::puts("ibverbs read");
}

void LibfabricBuffer::write() {
  std::puts("libfabric write");
}

void LibfabricBuffer::read() {
  std::puts("libfabric read");
}

int main() {
    LibfabricBuffer lf_buf(0);
    lf_buf.read();
    lf_buf.write();

    VerbsBuffer ib_buf;
    ib_buf.read();
    ib_buf.write();
}

