
#ifndef CIRCUIT____VEC_HH
#define CIRCUIT____VEC_HH

#include <cstdint>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <typeinfo>

#ifdef GEN
class Vec {};

class Vuint16_t;
class Vuint16_tAdd;
class Vuint16_tArg;
class Vuint16_tConst;

typedef const Vuint16_t& Uint16_t;

class Vuint16_t : public Vec {
public:
  Vuint16_t() {}
  Vuint16_t(int v);

  virtual
  Vuint16_t* operator+(Uint16_t o) const;


  virtual void run(std::ostream& s) const {};

};

std::ostream& operator<<(std::ostream& os, const Vuint16_t& dt);


class Vuint16_tAdd : public Vuint16_t {
public:
  Vuint16_tAdd(Uint16_t a, Uint16_t b) : a(a), b(b) {}
  virtual void run(std::ostream& s) const {
    a.run(s);
    s << " + ";
    b.run(s);
  }

private:
  const Vuint16_t &a, &b;
};

class Vuint16_tArg : public Vuint16_t {
public:
  Vuint16_tArg(std::string name) : name(name) {}

  std::string name;

  virtual void run(std::ostream& s) const { s << name;}
};

class Vuint16_tConst : public Vuint16_t {
public:
  Vuint16_tConst(int v) : v(v) {}

  int v;

  virtual void run(std::ostream& s) const { s << v;}
};

inline
const Vuint16_t &c(int i) { return *new Vuint16_tConst(i); }

inline
const Vuint16_t & operator ""_v8 (unsigned long long i) { return *new Vuint16_tConst(i); }

#else

typedef uint16_t Uint16_t;

inline
const uint16_t operator ""_v8 (unsigned long long i) { return i; }

#endif


Uint16_t sim();

#endif // CIRCUIT____VEC_HH
