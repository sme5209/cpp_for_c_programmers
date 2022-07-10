#include "priorityqueue.h"
#include <stdexcept>
#include <algorithm>

PriorityQueue::PriorityQueue(int identity, int priority) : id_priority_pairs(), size(1) {
    id_priority_pairs.emplace_front(std::pair<int, int>(identity, priority));
}

// internal helper method to return a specific entry in queue
std::list<std::pair<int, int>>::iterator PriorityQueue::find(int identity) {
    // the STL find_if allows for a lambda function to serve as the predicate
    //  in determining when an entry is successfully found
    auto it = std::find_if(id_priority_pairs.begin(), id_priority_pairs.end(),
                           [&identity](const std::pair<int, int> entry) { return entry.first == identity; });
    return it;
}

// returns true if entry is found, false otherwise
bool PriorityQueue::contains(int identity) {
    auto it = find(identity);
    return (it != id_priority_pairs.end());
}

// changes listed entry priority (if it exists)
// TODO: update priority
void PriorityQueue::change_priority(int identity, int priority) {
    auto it = find(identity);
    if (it != id_priority_pairs.end()) {
        it->second = priority;
        id_priority_pairs.
    }
}

// iterates over queue, inserts new entry in front of first
//  entry with lower priority
//  NOTE: if new entry is lowest priority, it is inserted at back
//  TODO: confirm that this works correctly
void PriorityQueue::insert(int identity, int priority) {
    std::list<std::pair<int, int>>::iterator it;
    for (it = id_priority_pairs.begin(); it != id_priority_pairs.end(); it++) {
        if (priority >= it->second) {
            id_priority_pairs.insert(it, std::pair<int, int>(identity, priority));
            break;
        }
    }
    if (it == id_priority_pairs.end()) {
        id_priority_pairs.emplace_back(std::pair<int, int>(identity, priority));
    }
    size++;
}

std::pair<int, int> PriorityQueue::top() {
    if (id_priority_pairs.empty()) {
        throw std::range_error("Cannot operate on empty queue");
    }
    std::pair<int, int> high_priority = id_priority_pairs.front();
    return high_priority;
}

std::pair<int, int> PriorityQueue::pop() {
    std::pair<int, int> high_priority = top();
    id_priority_pairs.pop_front();
    size--;
    return high_priority;
}

int PriorityQueue::get_size() {
    return size;
}

bool PriorityQueue::is_empty() {
    return (size == 0);
}










