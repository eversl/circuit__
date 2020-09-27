#include "vec.hh"


Vuint16_t *Vuint16_t::operator+(Uint16_t o) const {
  Vuint16_tAdd *res = new Vuint16_tAdd(*this, o);
  return res;
}

Vuint16_t::Vuint16_t(int v) { *this = *new Vuint16_tConst(v); }


std::ostream &operator<<(std::ostream &os, const Vuint16_t &dt) {
  dt.run(os);
  return os;
}
