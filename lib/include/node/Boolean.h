//
// Created by souls on 14/05/2020.
//

#ifndef BARZANE_BOOLEAN_H
#define BARZANE_BOOLEAN_H

#include "../Node.h"
#include "../str.h"

namespace BooleanType {
    enum Value {
        TRUE,
        FALSE,
        UNDEFINED
    };
}

/**
 * boolean: "true" | "false"
 */
class Boolean: public Node {

    public:
        Boolean(Indexer<Symbol>* tokens);

        virtual ~Boolean();

        void construct();

        const string json(unsigned int indentSize = 1) const;

        BooleanType::Value getValue() const;

    private:
        BooleanType::Value value;
};


#endif //BARZANE_BOOLEAN_H
