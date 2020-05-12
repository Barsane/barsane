//
// Created by souls on 30/04/2020.
//

template<typename T> Indexer<T>::Indexer(vector<T*> buf): buffer(buf), index(0) {
    __documents__.insert(buf.begin(), buf.end());
}

template<typename T> Indexer<T>::~Indexer() {
    for (auto elt : buffer) {
        if (__documents__.count(elt)) {
            delete elt;
            __documents__.erase(elt);
        }
    }
}

template<typename T> void Indexer<T>::next() {
    ++index;
}

template<typename T> void Indexer<T>::back() {
    --index;
}

template<typename T> void Indexer<T>::reindex(unsigned int pos) {
    index = pos;
}

template<typename T> unsigned int Indexer<T>::size() const {
    return buffer.size();
}

template<typename T> T* Indexer<T>::current() {
    if (index >= 0 && index < buffer.size())
        return buffer[index];
    return 0;
}

template<typename T> unsigned int Indexer<T>::position() {
    return index;
}

template<typename T> bool Indexer<T>::end() {
    return index >= buffer.size();
}

template<typename T> ostream& operator<<(ostream& out, const Indexer<T>& indexer) {
   /* out << "Position: " << indexer.position() << " Current: " << indexer.current()
        << "Is end: " << indexer.end() << endl;*/
    return out;
}
