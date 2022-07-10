#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <list>

// helper data structure used to track list of nodes with current
//  shortest path to source node
class PriorityQueue {
private:
    // linked list of pairs of IDs associated with each node and the
    //  priority values associated with each node (current cost from
    //  source)
    std::list<std::pair<int, int>> id_priority_pairs;
    int size;

    // private methods

    std::list<std::pair<int, int>>::iterator find(int identity);

public:
    // constructors/destructor

    PriorityQueue() : id_priority_pairs(), size(0) {}
    PriorityQueue(int identity, int priority);
    ~PriorityQueue() = default;

    // checks if the queue contains the given element
    bool contains(int identity);
    // changes the priority (node value) of queue element
    void change_priority(int identity, int priority);
    // insert queue_element into queue
    void insert(int identity, int priority);
    // returns the top element of the queue
    std::pair<int, int> top();
    // removes the top element of the queue
    std::pair<int, int> pop();
    // return the number of elements in queue
    int get_size();
    // check if empty
    bool is_empty();
};

#endif // PRIORITY_QUEUE_H