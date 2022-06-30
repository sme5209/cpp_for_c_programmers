#include "graph.h"

// node data structure methods

void Graph::Node::add_neighbor(Node *y, double v) {
    neighbors.insert(std::pair<Node*, double>(y, v));
}

void Graph::Node::remove_neighbor(Node *y) {
    neighbors.erase(y);
}

bool Graph::Node::has_neighbor(Node *y) {
    return (neighbors.find(y) != neighbors.end());
}

int Graph::Node::get_edge(Node *y) {
}

void Graph::Node::set_edge(Node *y) {

}

std::vector<int> Graph::Node::list_neighbors() {
    std::vector<int> neighbor_ids(neighbors.size());
    for (std::pair<Node*, double> neighbor : neighbors) {
        neighbor_ids.emplace_back(neighbor.first->id);
    }
    // TODO: figure out if this works or goes out of scope
    return std::move(neighbor_ids);
}

// graph data structure methods

// TODO: perform input validation
Graph::Graph(int total_vertices, double edge_density, double min_cost, double max_cost) :
        total_vertices(total_vertices) {
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

int Graph::V() const {
    return total_vertices;
}

int Graph::E() const {
    return total_edges;
}

bool Graph::is_adjacent(int x, int y) {
    return vertices.at(x).has_neighbor(&vertices.at(y));
}

std::vector<int> Graph::list_neighbors(int x) {
    return vertices.at(x).list_neighbors();
}

void Graph::add_edge(int x, int y, int v) {
    vertices.at(x).add_neighbor(&vertices.at(y), v);
    vertices.at(y).add_neighbor(&vertices.at(x), v);
}

void Graph::remove_edge(int x, int y) {
    vertices.at(x).remove_neighbor(&vertices.at(y));
    vertices.at(y).remove_neighbor(&vertices.at(x));
}

int Graph::get_edge_value(int x, int y) {

}



