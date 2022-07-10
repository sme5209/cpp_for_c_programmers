#include "graph.h"
#include <random>
#include <stdexcept>

// node data structure methods

void Graph::Node::add_neighbor(Node *y, double v) {
    neighbors.insert(std::pair<Node*, double>(y, v));
}

void Graph::Node::remove_neighbor(Node *y) {
    neighbors.erase(y);
}

bool Graph::Node::has_neighbor(Node *y) const {
    return (neighbors.find(y) != neighbors.end());
}

//  NOTE: throws exception if edge is non-existent
double Graph::Node::get_edge(Node *y) const {
    auto y_it = neighbors.find(y);
    if (y_it != neighbors.end()) {
        return y_it->second;
    } else {
        throw std::invalid_argument("Nonexistent edge");
    }
}

//  NOTE: throws exception if edge is non-existent
void Graph::Node::set_edge(Node *y, double v) {
    auto y_it = neighbors.find(y);
    if (y_it != neighbors.end()) {
        y_it->second = v;
    } else {
        throw std::invalid_argument("Nonexistent edge");
    }
}

// TODO: figure out if returning "std::move" goes out of scope
std::vector<int> Graph::Node::list_neighbors() const {
    std::vector<int> neighbor_ids(neighbors.size());
    for (std::pair<Node*, double> neighbor : neighbors) {
        neighbor_ids.emplace_back(neighbor.first->id);
    }
    return std::move(neighbor_ids);
}

// graph data structure methods

void Graph::djikstra_algo(int w, PriorityQueue &min_heap, std::unordered_set<Node*> &closed_set, std::list<int> &output) {
    if (min_heap.is_empty()) {

    }
    Node &neighbor = vertices.at();
    for (auto &it : neighbor.neighbors) {
        // move to next node in sequence if node is in closed set
        if (closed_set.find(it.first) == closed_set.end()) {
            continue;
        }
        // otherwise, update node's path

    }
}

Graph::Graph(int total_vertices, double edge_density, double min_cost, double max_cost) :
        total_vertices(total_vertices) {
    // perform input validation
    if (total_vertices < 1 || edge_density < 0 || edge_density > 1 || min_cost < 0 || min_cost > max_cost) {
        throw std::invalid_argument("Invalid argument(s)");
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

int Graph::V() const {
    return total_vertices;
}

int Graph::E() const {
    return total_edges;
}

bool Graph::is_adjacent(int x, int y) {
    return vertices.at(x).has_neighbor(&vertices.at(y));
}

std::vector<int> Graph::list_neighbors(int x) const {
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

double Graph::get_edge_value(int x, int y) {
    return vertices.at(x).get_edge(&vertices.at(y));
}

void Graph::set_edge_value(int x, int y, double v) {
    vertices.at(x).set_edge(&vertices.at(y), v);
}

std::list<int> Graph::get_vertices() {

}

std::list<int> Graph::get_path(int u, int w) {
    // perform input validation
    if (u < 0 || u > total_vertices || w < 0 || w > total_vertices) {
        throw std::invalid_argument("Invalid argument(s)");
    }
    PriorityQueue min_heap = PriorityQueue();
    std::unordered_set<Node*> closed_set = std::unordered_set<Node*>();
    std::list<int> out_list = std::list<int>();

    // Recursively update path lengths to neighboring nodes using
    //  Djikstra's algo
    djikstra_algo(w, min_heap, closed_set, out_list);
}

int Graph::path_size(int u, int w) {

}




