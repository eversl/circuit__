
#ifndef CIRCUIT____VEC_HH
#define CIRCUIT____VEC_HH

#include <cstdint>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <typeinfo>

#ifdef GEN


template<typename T>
class Vec {
public:
    Vec(T v);

    Vec<T> & operator+(const Vec<T> &o) const;

    virtual void run(std::ostream &ostream) const = 0;

protected:
    Vec() {}

private:

};


template<typename T>
using v = const Vec<T> &;


template<typename T>
std::ostream &operator<<(std::ostream &os, const v<T> dt);


template<typename T>
class VecAdd : public Vec<T> {
public:
    VecAdd(v<T> a, v<T> b) : a(a), b(b) {}

    virtual void run(std::ostream &s) const {
        a.run(s);
        s << " + ";
        b.run(s);
    }

private:
    const Vec<T> &a, &b;
};

template<typename T>
class VecArg : public Vec<T> {
public:
    VecArg(std::string name) : name(name) {}

    std::string name;

    virtual void run(std::ostream &s) const { s << name; }
};

template<typename T>
class VecConst : public Vec<T> {
public:
    VecConst(T v) : v(v) {}

    T v;

    virtual void run(std::ostream &s) const { s << v; }
};

template<typename T>
inline const Vec<T> &c(int i) { return *new VecConst<T>(i); }


template<typename T>
Vec<T> & Vec<T>::operator+(const Vec<T> &o) const {
    VecAdd<T> *res = new VecAdd(*this, o);
    return *res;
}

template<typename T>
Vec<T>::Vec(T v) {
    *this = *new VecConst<T>>
    (v);
}


template<typename T>
std::ostream &operator<<(std::ostream &os, const Vec<T> &dt) {
    dt.run(os);
    return os;
}


const Vec<uint16_t> &operator ""_v16(unsigned long long i);

#else

template <typename T>
class v {
public:
    v(T val) : val(val) {}
    operator T() const { return val; }
    v<T> operator*(uint64_t other) const { return v(val * other); }
    v<T> operator*(uint8_t other) const { return v(val * other); }
    v<T> operator+(int other) const { return v(val + other); }
    v<T> operator+(v<T> other) const { return v(val + other); }
    bool operator<=(T other) const { return val <= other; }

private:
    T val;
};

inline const uint16_t operator""_v16(unsigned long long i) { return i; }

#endif


v<uint16_t> sim();

#endif // CIRCUIT____VEC_HH
