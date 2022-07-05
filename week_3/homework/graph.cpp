#include "graph.h"

// node data structure methods

// adds a neighboring node to object node's map
void Graph::Node::add_neighbor(Node *y, double v) {
    neighbors.insert(std::pair<Node*, double>(y, v));
}

// removes a neighboring node from object node's map
void Graph::Node::remove_neighbor(Node *y) {
    neighbors.erase(y);
}

// checks if object node has another node in its map
bool Graph::Node::has_neighbor(Node *y) const {
    return (neighbors.find(y) != neighbors.end());
}

// returns the cost associated with the edge between
//  object node and input node
//  NOTE: throws exception if edge is non-existent
double Graph::Node::get_edge(Node *y) const {
    auto y_it = neighbors.find(y);
    if (y_it != neighbors.end()) {
        return y_it->second;
    } else {
        throw EINVAL;
    }
}

// updates the cost associated with the edge between
//  object node and input node
//  NOTE: throws exception if edge is non-existent
void Graph::Node::set_edge(Node *y, double v) {
    auto y_it = neighbors.find(y);
    if (y_it != neighbors.end()) {
        y_it->second = v;
    } else {
        throw EINVAL;
    }
}

// returns a vector of neighbors to the current object node
// TODO: figure out if returning "std::move" goes out of scope
std::vector<int> Graph::Node::list_neighbors() const {
    std::vector<int> neighbor_ids(neighbors.size());
    for (std::pair<Node*, double> neighbor : neighbors) {
        neighbor_ids.emplace_back(neighbor.first->id);
    }
    return std::move(neighbor_ids);
}

// graph data structure methods

// graph object constructor
Graph::Graph(int total_vertices, double edge_density, double min_cost, double max_cost) :
        total_vertices(total_vertices) {
    // perform input validation
    if (total_vertices < 1 || edge_density < 0 || edge_density > 1 || min_cost < 0 || min_cost > max_cost) {
        throw EINVAL;
    }

    // preallocate space for vector (should improve performance)
    vertices.reserve(total_vertices);

    // uniform distribution setup
    std::random_device rand;
    std::default_random_engine generator(rand());
    std::uniform_real_distribution<double> density_dist;
    std::uniform_real_distribution<double> edge_dist(min_cost, max_cost);

    int expected_neighbors = static_cast<int>(round(total_vertices * edge_density));

    // first fill vector with vertices
    for (int i = 0; i < total_vertices; i++) {
        vertices.emplace_back(i, expected_neighbors);
    }
    // then loop back through vector and add edges
    int count = 0;
    for (int i = 0; i < total_vertices; i++) {
        for (int j = 0; j < total_vertices; j++) {
            if (i != j && density_dist(generator) < edge_density) {
                count += 1;
                double cost = edge_dist(generator);
                vertices[i].add_neighbor(&vertices[j], cost);
                vertices[j].add_neighbor(&vertices[i], cost);
            }
        }
    }
    total_edges = count;
}

// returns number of vertices in graph
int Graph::V() const {
    return total_vertices;
}

// returns number of edges in graph
int Graph::E() const {
    return total_edges;
}

// checks if node x is adjacent to node y
bool Graph::is_adjacent(int x, int y) {
    return vertices.at(x).has_neighbor(&vertices.at(y));
}

// lists all neighbors associated with node x
std::vector<int> Graph::list_neighbors(int x) const {
    return vertices.at(x).list_neighbors();
}

// adds an edged between nodes x and y
void Graph::add_edge(int x, int y, int v) {
    vertices.at(x).add_neighbor(&vertices.at(y), v);
    vertices.at(y).add_neighbor(&vertices.at(x), v);
}

// removes the edge between nodes x and y
void Graph::remove_edge(int x, int y) {
    vertices.at(x).remove_neighbor(&vertices.at(y));
    vertices.at(y).remove_neighbor(&vertices.at(x));
}

// gets the edge value between nodes x and y
double Graph::get_edge_value(int x, int y) {
    return vertices.at(x).get_edge(&vertices.at(y));
}

// updates the edge value between nodes x and y
void Graph::set_edge_value(int x, int y, double v) {
    vertices.at(x).set_edge(&vertices.at(y), v);
}




