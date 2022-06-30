#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <list>
#include "graph.h"

// class used to calculate an input Graph's shortest path
// TODO: add any necessary data members
// TODO: implement constructor and destructor
// TODO: implement remaining methods
class ShortestPath {
private:

public:
    // constructors/destructor
    ShortestPath() {}
    ~ShortestPath();

    // list of vertices in G(V,E)
    std::list<int> vertices(Graph G);
    // find the shortest path between u-w and returns the sequence of vertices representing shortest path u-v1-v2-…-vn-w
    std::list<int> path(int u, int w);
    // return the path cost associated with the shortest path
    int path_size(int u, int w);
};

#endif // SHORTESTPATH_H