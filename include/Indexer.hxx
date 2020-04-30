//
// Created by souls on 30/04/2020.
//

template<typename T> Indexer<T>::Indexer(vector<T*> buf): buffer(buf), index(0) {
}

template<typename T> Indexer<T>::~Indexer() {
}

template<typename T> void Indexer<T>::next() {
}

template<typename T> void Indexer<T>::back() {
}

template<typename T> void Indexer<T>::reindex(unsigned int pos) {
}

template<typename T> const unsigned int Indexer<T>::size() const {
    return 0;
}

template<typename T> T* Indexer<T>::current() {
    static char msg[] ="Not implemented yet";
    return msg;
}


template<typename T> unsigned int Indexer<T>::position() {
    return 0;
}



template<typename T> bool Indexer<T>::end() {
    return false;
}

template<typename T> ostream& operator<<(ostream& out, const Indexer<T>& indexer) {
    return out;
}
