#include <front/parse/parse_header.hpp>

void ControlFlowNode::read(std::ifstream& file) {
    Token tok = expect(file,FLOW);
    this->statement = strToFlow(tok.str);
    this->line = tok.line;
    Token next = lex::lex(file);
    if (sym::in_global_scope()) {
        ZF_ERROR("line %d: control flow in global scope", tok.line);
    }
    if (next.type == TreeComp::SEMICOLON) {
        this->expression = nullptr;
        lex::unlex(next); // statement expects a trailing ';'
    } else {
        if (this->statement != RETURN) {
            ZF_ERROR("line %d: did not expect expression after %s", tok.line, tok.raw_content());
        }
        lex::unlex(next);
        this->expression = new ExprNode();
        this->expression->read(file);
    }
    // Check that return type is valid
    if (
        ( (this->expression == nullptr) ? VOID : *get_type(this->expression) )
         != sym::current_function()->ret) {
        ZF_ERROR("line %d: expected return type of %s, found expression of type %s"
        , this->expression->line, sym::current_function()->ret.to_human_str().c_str(), get_type(this->expression)->to_human_str().c_str());
    }
}
