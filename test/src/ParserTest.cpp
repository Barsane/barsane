//
// Created by souls on 04/05/2020.
//

#include "../include/ParserTest.h"

void ParserTest::getTree_When_LexerHasNotError() {
    string text = "x: number; x = 5; print x;";
    Lexer lexer(text);
    Parser parser(lexer);
    expect("The tree should not be null", parser.getTree() == nullptr);
}

void ParserTest::raiseError_When_UnknownToken() {
    string text = "x: µ; x = 5; print x";
    Lexer lexer(text);
    Parser parser(lexer);
    expect("Parser should have an error of UNKNOWN type", parser.hasErrors());
}

void ParserTest::raiseError_When_MissingToken() {
    string text = "x: number; x = 5; print x";
    Lexer lexer(text);
    Parser parser(lexer);
    expect("Parser should have an error of MISSING_TOKEN type", parser.hasErrors());
}

void ParserTest::getTree_When_HasDecl() {
    string text = "x: number;";
    Lexer lexer(text);
    Parser parser(lexer);
    AST* tree = parser.getTree();
    expect("Tree should have a declaration", tree->getDeclarations() != nullptr);

    string missingColon = "x number;";
    Lexer lexerMissingColon(missingColon);
    Parser parserMissingColon(lexerMissingColon);
    AST* missingColonTree = parserMissingColon.getTree();
    expect("Tree should not have a declaration due to missing ':'",
            missingColonTree->getDeclarations() == nullptr);

    string missingType = "x : ;";
    Lexer lexerMissingType(missingType);
    Parser parserMissingType(lexerMissingType);
    AST* missingTypeTree = parserMissingType.getTree();
    expect("Tree should not have a declaration due to missing 'type'",
           missingTypeTree->getDeclarations() == nullptr);

    string missingSemiColon = "x : number";
    Lexer lexerMissingSemiColon(missingSemiColon);
    Parser parserMissingSemiColon(lexerMissingSemiColon);
    AST* missingSemiColonTree = parserMissingSemiColon.getTree();
    expect("Tree should not have a declaration due to missing ';'",
           missingSemiColonTree->getDeclarations() == nullptr);

    string missingId = ": number";
    Lexer lexerMissingId(missingId);
    Parser parserMissingId(lexerMissingId);
    AST* missingIdTree = parserMissingId.getTree();
    expect("Tree should not have a declaration due to missing 'id'",
           missingIdTree->getDeclarations() == nullptr);

}

void ParserTest::getTree_When_HasAffect() {
    string text = "x = 5;";
    Lexer lexer(text);
    Parser parser(lexer);
    AST* tree = parser.getTree();
    expect("Tree should have an affect", tree->getAffects() != nullptr);

    string missingSemiColon = "x = 5";
    Lexer lexerMissingSemiColon(missingSemiColon);
    Parser parserMissingSemiColon(lexerMissingSemiColon);
    AST* missingSemiColonTree = parserMissingSemiColon.getTree();
    expect("Tree should not have an affect due to missing ';'",
           missingSemiColonTree->getAffects() == nullptr);

    string missingAssignment = "x 5;";
    Lexer lexerMissingAssignment(missingAssignment);
    Parser parserMissingAssignment(lexerMissingSemiColon);
    AST* missingAssignmentTree = parserMissingAssignment.getTree();
    expect("Tree should not have an affect due to missing '='",
           missingSemiColonTree->getAffects() == nullptr);

    string missingValue = "x = ;";
    Lexer lexerMissingValue(missingValue);
    Parser parserMissingValue(lexerMissingValue);
    AST* missingValueTree = parserMissingValue.getTree();
    expect("Tree should not have an affect due to missing 'value'",
           missingValueTree->getAffects() == nullptr);
}

void ParserTest::run() {
    getTree_When_LexerHasNotError();
    raiseError_When_UnknownToken();
    raiseError_When_MissingToken();
    getTree_When_HasDecl();
    getTree_When_HasAffect();
}