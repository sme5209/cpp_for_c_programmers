#include <iostream>

/// TODO: figure out why calling a List::print function won't
//  work inside of the overloaded operator<< friend function

// ************** ADT declarations **************

struct list_element {
    list_element(int n=0, list_element *ptr=nullptr) : d(n), next(ptr) {}
    list_element(const list_element &ele);
    int d;
    list_element *next; 
};

class List {
    private:
        list_element *head;
        list_element *cursor;
    
    public:
        List() : head(nullptr), cursor(nullptr) {}
        List(const int *arr, int n);
        List(const List &lst);
        ~List();

        void prepend(int num);
        friend std::ostream &operator<<(std::ostream &out, List const &L);         
};

// ************** ADT implementations **************

// list node alternate copy constructor
list_element::list_element(const list_element &ele) {
    d = ele.d;
    next = ele.next;
}

// list copy constructor
List::List(const List &lst) {
    if (lst.head == nullptr) {
        head = nullptr;
        cursor = nullptr;
    } else {
        // iterate over input list, copy element-by-element
        /// NOTE: need to store previous and current node to make link
        list_element *prev = new list_element(lst.head->d, nullptr);
        head = prev;
        for (cursor = lst.head->next; cursor != nullptr; cursor = cursor->next) {
            list_element *curr = new list_element(cursor->d, nullptr);
            prev->next = curr;
            prev = curr;
        }
    }
}

// list destructor
List::~List() {
    std::cout << "List destructor called!" << std::endl;
    if (head != nullptr) {
        for (cursor = head; cursor != nullptr;) {
            cursor = head->next;
            delete head;
            head = cursor;
        }
    }
}

// add new head node to list
void List::prepend(int num) {
    head = new list_element(num, head);
}

// overloaded stream insertion operator for List object
std::ostream &operator<<(std::ostream &out, List const &L) {
    for (list_element *tmp = L.head; tmp != nullptr; tmp = tmp->next) {
        out << tmp->d << " ### ";
    }
    out << std::endl;
    return out;
}  

// ************** driver functions **************

// dynamic allocation
/*
int main() {
    List *lst = new List(); 
    for (int i = 0; i < 10; i++) {
        lst->prepend(i);
    }
    std::cout << *lst;
    List *lst_cpy = new List(*lst);
    delete(lst);

    std::cout << *lst_cpy;
    delete(lst_cpy);

    return 0;
}
*/

// static allocation
int main() {
    List lst;
    for (int i = 0; i < 10; i++) {
        lst.prepend(i);
    }
    std::cout << lst;

    List lst_cpy = lst;
    std::cout << lst_cpy;

    return 0;
}