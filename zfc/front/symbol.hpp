/**
 * symbol - symbols that AST nodes will have references to.
 */

#pragma once

#include <string>
#include <vector>

#include <common/type.hpp>

namespace sym {

extern std::string argsep, retsep, scopesep;

struct Symbol {
    std::string name;
    int lineno;
    bool var;
    inline Symbol(std::string n) : name(n) {}
};

struct Variable : public Symbol {
    Type type;
    inline Variable(std::string n) : Symbol(n) { var = true; }
};

struct Function : public Symbol {
    std::vector<Variable> args;
    Type ret;
    bool extc;
    inline Function(std::string n) : Symbol(n) { var = false; }
    std::string get_overloaded_name();
};

void enter_scope();
void exit_scope();

void add_symbol(Symbol* s);
void add_global_symbol(Symbol* s);

Variable* resolve_var(std::string name);
Function* resolve_fn(std::string name, std::vector<Type> args);

bool in_global_scope();

Function* current_function();
void set_function(Function* fn);

std::vector<std::vector<sym::Symbol*>>* getsymtab();

}
