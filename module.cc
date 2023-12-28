//
// Created by Leon Evers on 03/04/2020.
//

#include "vec.hh"
#include "module.hh"

#ifdef GEN

void instantiation::run(std::ostream &s) const {
    s << mod.name << " " << "m1" << " (\n" <<
      "r, a, b " << "); ";
}

#endif