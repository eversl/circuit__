#include "vec.hh"

#ifdef GEN


 const Vec<uint16_t> &operator""_v16(unsigned long long i) {
    return *new VecConst<uint16_t>(i);
}

#endif