//
// Created by pisatel on 07.04.16.
//

#ifndef CPPALGO_ADJLIST_H
#define CPPALGO_ADJLIST_H

#include "headers.h"

template<class T>
class AdjList {
private:
    std::map<T, std::vector<T>> _list;
public:
    void addEdge(T to, T from) {
        _list[from].push_back(to);
    }
    void deleteEdge(T to, T from) {
        if (_list.find(from) != _list.end()) {
            typename std::vector<T>::const_iterator tmp = std::find(_list[from].begin(), _list[from].end(), to);
            if (tmp != _list[from].end())
                _list[from].erase(tmp);
        }
    }
    const std::vector<T>&  getAdjVector(T from) const {
        if (_list.find(from) != _list.end()) {
            return _list[from];
        }
    }


};

#endif //CPPALGO_ADJLIST_H
