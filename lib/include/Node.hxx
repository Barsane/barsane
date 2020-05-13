
inline Node::Node(Indexer<Symbol>* tokens): indexer(tokens) {
    __indexers__.insert(tokens);
};

inline Node::~Node() {
    set<Indexer<Symbol>*>::iterator it;
    if (__indexers__.count(indexer)) {
        delete indexer;
        __indexers__.erase(indexer);
    }
}

inline bool Node::validate(bool cond, string msg) {
    if (!nextIf(cond)) {
        unsigned int line = current()->getLine();
        unsigned int colon = current()->getColon();
        Error syntax = Error(SYNTAX_ERROR, msg, line, colon);
        errorHandler.add(syntax);
        jump(SEMI_COLON);
        return false;
    }

    return true;
}

inline void Node::jump(SymbolType type) {
    while (!indexer->end() && current()->getType() != type) {
        indexer->next();
    }
}

inline Symbol* Node::current() {
    Symbol* current = indexer->current();
    if (current)
        return current;
    string unknown = "";
    static Symbol symbol = Symbol(unknown, 1, 1);
    return &symbol;
}

inline bool Node::nextIf(const bool cond) {
    if (indexer->end()) {
        unsigned int line = current()->getLine();
        unsigned int colon = current()->getColon();
        Error missing = Error(MISSING_TOKEN, "Missing delimiter ;", line, colon);
        errorHandler.add(missing);
        return false;
    }

    if (cond) {
        indexer->next();
        return true;
    }

    return false;
}

inline bool Node::grantNext(const bool cond) {
    return !indexer->end() && cond;
}

inline bool Node::isFactor() {
    str token = str(current()->getToken());
    return current()->isMinus()         ||
           current()->isId()            ||
           token.isNumeric()            ||
           current()->isLeftBracket();
}
