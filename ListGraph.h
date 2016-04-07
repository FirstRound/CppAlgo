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
};


#endif //CPPALGO_LISTGRAPH_H
