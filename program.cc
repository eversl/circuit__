
#include "module.hh"
#include "vec.hh"


class calcModule : public module {

     virtual v<uint16_t> lambda(v<uint16_t> a, v<uint16_t> b) override {
         v<uint16_t> c = a + b;
         v<uint32_t> d = (v<uint32_t>) c;
         v<uint16_t> e = (v<uint16_t>) d;
         return e; }

public:

    calcModule() : module("calc") {init();}
};

module& calc = *new calcModule();

v<uint16_t> sim() {
    v<uint16_t> i = calc(10_v16, 12_v16);
    return i;
}
