#include <iostream>
#include <vector>
#include <random>

class Node {
    private:

    public:
};

class Graph {
    private:

    public:
        // constructor(s)
        Graph() {}  

        // destructor
        ~Graph();

        // returns number of vertices in graph
        int V();
        // returns number of edges in graph
        int E();
        // tests whether there is an edge from node x to node y
        bool is_adjacent(Node x, Node y);
        // lists all nodes y such that there is an edge from x to y
        std::vector<Node> neighbors(Node x);
        // adds to G the edge from x to y, if it is not there
        void add_edge(Node x, Node y);
        // removes the edge from x to y, if it is there
        void delete_edge(Node x, Node y);
        // returns the value associated with the node x
        int get_node_value(Node x);
        // sets the value associated with the node x to a
        void set_node_value(Node x, int a);
        // returns the value associated to the edge (x,y)
        int get_edge_value(Node x, Node y);
        // sets the value associated with the edge (x,y) to v
        void set_edge_value(Node x, Node y, int v);
};

class PriorityQueue {
    private:

    public:
        // constructor(s)
        PriorityQueue() {}

        // destructor
        ~PriorityQueue();

        // changes the priority (node value) of queue element
        void change_priority(int priority);
        // removes the top element of the queue
        Node pop();
        // checks if the queue contains the given element
        bool contains(Node element);
        // insert queue_element into queue
        void insert(Node element);
        // returns the top element of the queue
        Node top();
        // return the number of elements in queue
        int size();
};

class ShortestPath {
    private:

    public:
        // list of vertices in G(V,E)
        std::vector<Node> vertices(Graph G);
        // find shortest path between u-w and returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w
        std::vector<Node> path(Node u, Node w);
        // return the path cost associated with the shortest path
        int path_size(Node u, Node w);

};