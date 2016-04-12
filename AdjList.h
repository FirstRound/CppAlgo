//
// Created by pisatel on 07.04.16.
//

#ifndef CPPALGO_ADJLIST_H
#define CPPALGO_ADJLIST_H

#include <vector>
#include <map>
#include <set>

template<class T>
class AdjList {
private:
    std::map<T, std::vector<T>> _list;
    std::set<T> _vertices;
public:
    void addEdge(T to, T from) {
        _list[from].push_back(to);
        _vertices.insert(from);
    }
    void deleteEdge(T to, T from) {
        if (_list.find(from) != _list.end()) {
            typename std::vector<T>::const_iterator tmp = std::find(_list[from].begin(), _list[from].end(), to);
            if (tmp != _list[from].end())
                _list[from].erase(tmp);
        }
    }
    std::vector<T>&  getAdjToVertex(T from) {
        if (_list.find(from) != _list.end()) {
            return _list[from];
        }

    }

    std::set<T>& getVertices() {
        return _vertices;
    }

};

#endif //CPPALGO_ADJLIST_H
