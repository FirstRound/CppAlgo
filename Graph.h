//
// Created by pisatel on 07.04.16.
//

#ifndef CPPALGO_GRAPH_H
#define CPPALGO_GRAPH_H


template<class T>
class Graph {
public:
    virtual void dfs() = 0;
    virtual void bfs() = 0;
    virtual void readGraphFromFile(std::string) = 0;
    virtual ~Graph(){}
};



#endif //CPPALGO_GRAPH_H
