#ifndef SASS_TO_STRING_H
#define SASS_TO_STRING_H

#include <string>

#include "operation.hpp"

namespace Sass {

  class Context;
  class Null;

  class To_String : public Operation_CRTP<std::string, To_String> {
    // import all the class-specific methods and override as desired
    using Operation<std::string>::operator();
    // override this to define a catch-all
    std::string fallback_impl(AST_Node* n);

    struct Sass_Output_Options opt;
    bool in_declaration;

  public:

    To_String(struct Sass_Output_Options opt = Sass_Output_Options(), bool in_declaration = true);
    virtual ~To_String();

    std::string operator()(String_Schema*);
    std::string operator()(String_Quoted*);
    std::string operator()(String_Constant*);

    template <typename U>
    std::string fallback(U n) { return fallback_impl(n); }
  };
}

#endif
