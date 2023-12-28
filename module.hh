#ifndef CIRCUIT____MODULE_HH
#define CIRCUIT____MODULE_HH

#include "vec.hh"

static const size_t bitsPerByte = 8;
#ifdef GEN

class module;

class instantiation : public Vec<uint16_t> {
public:
    instantiation(module &mod, v<uint16_t> a, v<uint16_t> b) : mod(mod), a(a), b(b) {}

    virtual void run(std::ostream &s) const;;

    module &mod;
    v<uint16_t> a;
    v<uint16_t> b;

};

class module {

    virtual v<uint16_t> lambda(v<uint16_t> a, v<uint16_t> b) = 0;

public:
    module(std::string name) : name(name) {}
    void init(){
        size_t len = sizeof(uint16_t) * bitsPerByte;
        std::cout << "module " << name << "(input [" << len - 1 << ":0] a, input [" << len - 1 << ":0] b, output ["
                  << len - 1 << ":0] r);\n";

        v<uint16_t> v = lambda(VecArg<uint16_t>("a"), VecArg<uint16_t>("b"));
        std::cout << "\n\tassign r = ";
        v.run(std::cout);
        std::cout << ";\n\n";
        std::cout << "endmodule\n\n";
    }


    v<uint16_t> operator()(v<uint16_t> a, v<uint16_t> b) {
        return *new instantiation(*this, a, b);
    }

    std::string name;
};

#else

class module {

    virtual v<uint16_t> lambda(v<uint16_t> a, v<uint16_t> b) = 0;

public:
   module(std::string)  {}


  v<uint16_t> operator() (v<uint16_t> a, v<uint16_t> b) {
    return lambda(a, b);
  }

    void init() {

    }
};

#endif

#endif // CIRCUIT____MODULE_HH
