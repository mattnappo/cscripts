#ifndef __MAIN_HPP__
#define __MAIN_HPP__

template <class D>
struct Buffer {
  void write() {
    static_cast<D*>(this)->write();
  }

  void read() {
    // Shared code here
    static_cast<D*>(this)->read(); // Specific code
    // More shared code
  }
};

struct LibfabricBuffer : Buffer<LibfabricBuffer> {
  int i;

  LibfabricBuffer(int i) : i(i) {}
  void write();
  void read();
};

struct VerbsBuffer : Buffer<VerbsBuffer> {
  VerbsBuffer() {}
  void write();
  void read();
};

#endif
