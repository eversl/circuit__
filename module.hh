#ifndef CIRCUIT____MODULE_HH
#define CIRCUIT____MODULE_HH

#include "vec.hh"

static const size_t bitsPerByte = 8;
#ifdef GEN

template<typename F>
class module;

template<typename F>
class instantiation : public Vec<uint16_t> {
public:
    instantiation(module<F> &mod, v<uint16_t> a, v<uint16_t> b) : mod(mod), a(a), b(b) {}

    virtual void run(std::ostream &s) const {
        s << mod.name << " " << "m1" << " (\n" <<
          "r, a, b " << "); ";
    };

    module<F> &mod;
    v<uint16_t> a;
    v<uint16_t> b;

};

template<typename F>
class module {
public:
    module(std::string name, F &&lambda) : name(name), f(lambda) {
        size_t len = sizeof(uint16_t) * bitsPerByte;
        std::cout << len << "\n";
        std::cout << "module " << name << "(input [" << len - 1 << ":0] a, input  [" << len - 1 << ":0] b, output ["
                  << len - 1 << ":0] r);\n";

        Vec<uint16_t> *v = lambda(VecArg<uint16_t>("a"), VecArg<uint16_t>("b"));
        std::cout << "\n\tassign r = ";
        v->run(std::cout);
        std::cout << ";\n\n";
        std::cout << "endmodule\n\n";
    }


    v<uint16_t> operator()(v<uint16_t> a, v<uint16_t> b) {
        return *new instantiation<F>(*this, a, b);
    }

    std::string name;
    F f;
};

#else

template <typename F>
class module {
public:
   module(std::string, F&& lambda) : f(lambda) {}


  v<uint16_t> operator() (v<uint16_t> a, v<uint16_t> b) {
    return f(a, b);
  }
  F f;
};

#endif

#endif // CIRCUIT____MODULE_HH
