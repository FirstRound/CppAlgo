//
// Created by pisatel on 07.04.16.
//

#ifndef CPPALGO_LISTGRAPH_H
#define CPPALGO_LISTGRAPH_H

#include "headers.h"

template<class T>
class ListGraph: public Graph<T> {
private:
    AdjList<T> _adj_list;
public:
    void readGraphFromFile(std::string filename) {
        std::ifstream file(filename);
        std::string line1, line2;
        if (file.is_open())
        {
            while (file >> line1 && file >> line2) {
                _adj_list.addEdge(line1, line2);
            }
            file.close();
        }
    }
    void dfs() {

    }
    void bfs() {

    }
};


#endif //CPPALGO_LISTGRAPH_H
