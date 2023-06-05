#ifndef __MAIN_HPP__
#define __MAIN_HPP__

template <typename D, typename T>
struct Buffer {
  void write(T val) {
    std::cout << "log write" << std::endl;
    static_cast<D*>(this)->write_impl(val);
  }

  T read() {
    // Shared code here
    std::cout << "log read" << std::endl;
    return static_cast<D*>(this)->read_impl(); // Specific code
    // More shared code
  }
};

template <typename T>
struct LibfabricBuffer : Buffer<LibfabricBuffer<T>, T> {
  T val;

  LibfabricBuffer(T v) : val(v) {}
  void write_impl(T val);
  T read_impl();
};


template <typename T>
struct VerbsBuffer : Buffer<VerbsBuffer<T>, T> {
  T val;
  int c;

  VerbsBuffer() : val{}, c(0) {}
  void write_impl(T v);
  T read_impl();
};

#endif
