
#include "module.hh"
#include "vec.hh"

class calcModule : public module {
public:
    calcModule(std::string name) : module(name) {}

    v<uint16_t> operator() (v<uint16_t> a, v<uint16_t> b) override {
        return (a + b); };
};

calcModule calc("calc");

//v<uint16_t> calc(v<uint16_t> a, v<uint16_t> b) {
//  return a + b;
//}

v<uint16_t> sim() {
  v<uint16_t> i = calc(10_v16, 12_v16);
  return i;
}
