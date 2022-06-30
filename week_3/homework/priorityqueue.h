#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <list>

// helper data structure used to track list of nodes with current
//  shortest path to source node
// TODO: add any necessary additional data members
// TODO: implement constructor and destructor
// TODO: implement remaining methods
class PriorityQueue {
private:
    // linked list of the IDs associated with each node
    std::list<int> vertices_indexes;

public:
    // constructors/destructor

    PriorityQueue() {}
    ~PriorityQueue();

    // changes the priority (node value) of queue element
    void change_priority(int priority);
    // removes the top element of the queue
    int pop();
    // checks if the queue contains the given element
    bool contains(int element);
    // insert queue_element into queue
    void insert(int element);
    // returns the top element of the queue
    int top();
    // return the number of elements in queue
    int size();
};

#endif // PRIORITYQUEUE_H