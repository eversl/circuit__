#ifndef CIRCUIT____MODULE_HH
#define CIRCUIT____MODULE_HH

#include "vec.hh"

#ifdef GEN

template <typename F>
class module;

template <typename F>
class instantiation : public Vuint16_t {
  public:
  instantiation(module<F> &mod, Uint16_t a, Uint16_t b) : mod(mod), a(a), b(b) {}

  virtual void run(std::ostream& s) const {
    s << mod.name << " " << "m1" << " (\n" <<
                                    "r, a, b " << "); ";
  };

  module<F> &mod;
  Uint16_t a;
  Uint16_t b;

};

template <typename F>
class module {
public:
  module(std::string name, F&& lambda) : name(name), f(lambda) {
    std::cout << "module " << name << "(input [15:0] a, input  [15:0] b, output [15:0] r);\n";

    Vuint16_t* v = lambda(Vuint16_tArg("a"), Vuint16_tArg("b"));
    std::cout << "\n\tassign r = ";
    v->run(std::cout);
    std::cout << ";\n\n";
    std::cout << "endmodule\n\n";
  }


  Uint16_t operator() (Uint16_t a, Uint16_t b) {
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


  Uint16_t operator() (Uint16_t a, Uint16_t b) {
    return f(a, b);
  }
  F f;
};

#endif

#endif // CIRCUIT____MODULE_HH
