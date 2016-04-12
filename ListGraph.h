//
// Created by pisatel on 07.04.16.
//

#ifndef CPPALGO_LISTGRAPH_H
#define CPPALGO_LISTGRAPH_H

#include <iostream>
#include "Graph.h"
#include "AdjList.h"
#include <map>
#include <vector>
#include <fstream>
#include <queue>

template<class T>
class ListGraph: public Graph<T> {
private:
    AdjList<T> _adj_list;
    std::map<T, bool> _used;
public:
    void readGraphFromFile(std::string filename) {
        std::ifstream file(filename, std::ios::in);
        T line1, line2;
        if (file.is_open())
        {
            while (!file.eof()) {
                file >> line1 >> line2;
                std::cout << line1 << " " << line2 << std::endl;
                _adj_list.addEdge(line1, line2);
            }
            file.close();
        }
        std::cout << std::endl;
    }
    void dfsHelper(T vertex) {
        if (_used[vertex] == 1)
            return;
        _used[vertex] = 1;
        for(T i : _adj_list.getAdjToVertex(vertex)) {
            dfsHelper(i);
            std::cout << vertex << "; " << std::endl;
        }
    }
    void dfs() {
        _used.clear();
        auto v = _adj_list.getVertices();
        for (T i : v) {
            _used[i] = 0;
        }
        dfsHelper(*(v.begin()));
    }
    void bfsHelper(T vertex) {
        std::queue<T> que;
        que.push(vertex);
        while (!que.empty()) {
            T tmp = que.front();
            _used[tmp] = 1;
            que.pop();
            std::cout << tmp << std::endl;
            for (auto i : _adj_list.getAdjToVertex(tmp)) {
                if (_used[i] == 0) {
                    que.push(i);
                }
            }
        }
    }
    void bfs() {
        _used.clear();
        auto v = _adj_list.getVertices();
        for (auto i : v) {
            _used[i] = 0;
        }
        bfsHelper(*(v.begin()));
    }

    void print() {

    }

    ~ListGraph() {

    }
};


#endif //CPPALGO_LISTGRAPH_H
