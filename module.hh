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
public:
    module(std::string name) : name(name) {
        size_t len = sizeof(uint16_t) * bitsPerByte;
        std::cout << len << "\n";
        std::cout << "module " << name << "(input [" << len - 1 << ":0] a, input  [" << len - 1 << ":0] b, output ["
                  << len - 1 << ":0] r);\n";

        v<uint16_t> val = (*this)(VecArg<uint16_t>("a"), VecArg<uint16_t>("b"));
        std::cout << "\n\tassign r = ";
        val.run(std::cout);
        std::cout << ";\n\n";
        std::cout << "endmodule\n\n";
    }

virtual v<uint16_t> operator()(v<uint16_t> a, v<uint16_t> b) {
        return *new instantiation(*this, a, b);
    }

    std::string name;
};

#else

class module {
public:
 module(std::string )  {}

    virtual v<uint16_t> operator()(v<uint16_t> a, v<uint16_t> b) = 0;

};

#endif

#endif // CIRCUIT____MODULE_HH
