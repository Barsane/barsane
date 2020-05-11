//
// Created by souls on 05/05/2020.
//

#ifndef BARZANE_TYPE_H
#define BARZANE_TYPE_H


#include "../Node.h"
#include "../Symbol.h"
#include "../Indexer.h"


namespace NodeType {
    enum type {
        NUMBER,
        BOOLEAN,
        STRING,
        UNDEFINED
    };
}

/**
 * type: {number} | {boolean} | {string}
 */
class Type: public Node {

    public:
        Type(Indexer<Symbol>* tokens);
        virtual ~Type();

        void construct();
        const string json(unsigned int indentSize = 1) const;

        NodeType::type getType() const;

private:
        NodeType::type type;

};


#endif //BARZANE_TYPE_H
