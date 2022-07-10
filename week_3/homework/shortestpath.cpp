#include "shortestpath.h"
#include "graph.h"
#include <list>
#include <stdexcept>

std::list<int> ShortestPath::vertices() {

}

std::list<int> ShortestPath::djikstra_algo(int u, int w) {

}

std::list<int> ShortestPath::path(int u, int w) {
    // perform input validation
    if (u < 0 || u > G.V() || w < 0 || w > G.V()) {
        throw std::invalid_argument("Invalid argument(s)");
    }
    PriorityQueue min_heap = PriorityQueue();

    // Recursively update path lengths to neighboring nodes using
    //  Djikstra's algo


}

int ShortestPath::path_size(int u, int w) {

}



