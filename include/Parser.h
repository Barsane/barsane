//
// Created by souls on 04/05/2020.
//

#ifndef BARZANE_PARSER_H
#define BARZANE_PARSER_H


#include "Lexer.h"
#include "AST.h"

class Parser {

    public:
        Parser(Lexer& lexer);
        ~Parser();

        AST* getTree() const;
        void display();
        void displayErrors();
        bool hasErrors();

};


#endif //BARZANE_PARSER_H
