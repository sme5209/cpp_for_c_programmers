#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <random>
#include <tuple>

// data structure that implements a graph
// TODO: add any necessary additional data members
// TODO: implement remaining methods
class Graph {
    private:
        // structure representing each vertex in graph
        /// NOTE: Node is only visible to Graph
        struct Node {
            // data members
            const int id;
            std::unordered_map<Node*, double> neighbors;
            
            // constructors/destructor
            Node(int id, int expected_neighbors) : id(id), neighbors(expected_neighbors) {}
            ~Node() = default;

            // adds an edge to node y with cost v
            void add_neighbor(Node *y, double v);
            // removes the edge to node y
            void remove_neighbor(Node *y);
            // checks if node has neighbor node y
            bool has_neighbor(Node *y);
            std::vector<int> list_neighbors();
            // gets the cost associated with edge to node y
            int get_edge(Node *y);
            // sets the cost associated with edge to node y
            void set_edge(Node *y);
        };
        std::vector<Node> vertices;
        int total_vertices{};
        int total_edges{};


    public:
        // constructors/destructor
        Graph() : vertices(), total_vertices(0), total_edges(0) {}
        Graph(int total_vertices, double edge_density, double min_cost, double max_cost);
        ~Graph() = default;

        // returns number of vertices in graph
        int V() const;
        // returns number of edges in graph
        int E() const;
        // tests whether there is an edge from node x to node y
        bool is_adjacent(int x, int y);
        // lists all nodes y such that there is an edge from x to y
        std::vector<int> list_neighbors(int x);
        // adds to G the edge from x to y, if it is not there
        void add_edge(int x, int y, int v);
        // removes the edge from x to y, if it is there
        void remove_edge(int x, int y);
        // returns the value associated to the edge (x,y)
        int get_edge_value(int x, int y);
        // sets the value associated with the edge (x,y) to v
        void set_edge_value(int x, int y, int v);
};

#endif // GRAPH_H