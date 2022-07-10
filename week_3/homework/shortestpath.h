#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <list>
#include "graph.h"
#include "priorityqueue.h"

// class used to calculate an input Graph's shortest path
// TODO: add any necessary data members
// TODO: implement constructor and destructor
// TODO: implement remaining methods
class ShortestPath {
private:
    Graph G;

    // private methods

    std::list<int> djikstra_algo(int u, int w);

public:
    // constructors/destructor
    ShortestPath(Graph G) : G(G) {}
    ~ShortestPath() = default;

    // list of vertices in G(V,E)
    std::list<int> vertices();
    // find the shortest path between u-w and returns the sequence of vertices representing shortest path u-v1-v2-…-vn-w
    std::list<int> path(int u, int w);
    // return the path cost associated with the shortest path
    int path_size(int u, int w);
};

#endif // SHORTEST_PATH_H