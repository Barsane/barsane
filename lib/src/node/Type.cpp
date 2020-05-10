//
// Created by souls on 05/05/2020.
//

#include "../../include/node/Type.h"

Type::Type(Indexer<Symbol> &tokens): Node(tokens), type(NodeType::UNDEFINED) {
}

Type::~Type() {
}

void Type::construct() {
    string token = current()->getToken();
    if (validate(current()->isType(), "Type must be number, boolean or string")) {
        if (token == "number") {
            type = NodeType::NUMBER;
        } else if (token == "boolean") {
            type = NodeType::BOOLEAN;
        } else {
            type = NodeType::STRING;
        }
    }
}

const string Type::json(unsigned int indentSize) const {
    stringstream repr;
    string indent(indentSize, INDENT);
    string backIndent(indentSize - 1, INDENT);
    string typeName = "null";

    repr << "{\n" << indent
         << "\"type\": \"Type\"," << "\n" << indent
         << "\"value\": ";

    switch(type) {
        case NodeType::NUMBER:
            repr << "\"NUMBER\"" << "\n" << backIndent << "}";
            break;
        case NodeType::BOOLEAN:
            repr << "\"BOOLEAN\"" << "\n" << backIndent << "}";
            break;
        case NodeType::STRING:
            repr << "\"STRING\"" << "\n" << backIndent << "}";
            break;
        default:
            repr << "null" << "\n" << backIndent << "}";
    }

    return repr.str();
}

NodeType::type Type::getType() const {
    return type;
}
