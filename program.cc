
#include "module.hh"
#include "vec.hh"

module calc("calc", [](Uint16_t a, Uint16_t b) { return a + b; });

//Uint16_t calc(Uint16_t a, Uint16_t b) {
//  return a + b;
//}

Uint16_t sim() {
  Uint16_t i = calc(10_v16, 12_v16);
  return i;
}
