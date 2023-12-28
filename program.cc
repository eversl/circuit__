
#include "module.hh"
#include "vec.hh"


module calc("calc", [](v<uint16_t> a, v<uint16_t> b) { return a + b; });

//v<uint16_t> calc(v<uint16_t> a, v<uint16_t> b) {
//  return a + b;
//}

v<uint16_t> sim() {
  v<uint16_t> i = calc(10_v16, 12_v16);
  return i;
}
