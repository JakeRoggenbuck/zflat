#include <back/gen/gen_main.hpp>

void FuncCallNode::write(std::ofstream& file) {

    gen::write(file, this->call->extc ? this->call->name : this->call->get_overloaded_name());
    gen::write(file, "(");

    for (auto arg : this->args) {
        if (arg != this->args[0])
            gen::write(file, ", ");
        arg->write(file);
    }

    gen::write(file, ")");

}
