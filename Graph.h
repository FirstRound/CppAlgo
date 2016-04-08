//
// Created by pisatel on 07.04.16.
//

#ifndef CPPALGO_GRAPH_H
#define CPPALGO_GRAPH_H


template<class T>
class Graph {
public:
    virtual void dfs();
    virtual void bfs();
    virtual void readGraphFromFile(std::string);
    virtual void print();
    virtual ~Graph();
};



#endif //CPPALGO_GRAPH_H
