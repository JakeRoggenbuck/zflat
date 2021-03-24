#include "gen_main.hpp"

namespace {

int indentation_level = 0;

}

namespace gen {

void write(std::ostream& file, std::string str) {

    // tabs
    for (int i = 0; i < indentation_level; ++i)
        file.write("\t");

    file.write(str.c_str());

}

void writeln(std::ofstream& file, std::string str) {
    write(file, str);
    file.write("\n");
}

void indent() {
    ++indentation_level;
}

void unindent() {
    --indentation_level;
    if (indentation_level < 0)
        ZF_BACK_ERR("indentation level went below zero in generated code");
}

}