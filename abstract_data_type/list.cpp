#include<iostream>

struct Node {
    int data = 0;
    Node* pNext = nullptr;
};

class List {
public:
    List() = default;
    List(const List& li);
    List operator=(const List& rhs);
    ~List();
    int get_size();
    void pushBack(int val);
    void print();
    bool isEmpty() const noexcept;
private:
    Node* head = nullptr;
    int size;
};



List::List(const List& li) {
    if(li.isEmpty()) {
        head = nullptr;
        return;
    }
    Node* cur = li.head;
    while(cur != nullptr) {
        this->pushBack(cur->data);
        cur = cur->pNext;
    }
}


List List::operator=(const List& rhs) {
    if(rhs.isEmpty()){
        head == nullptr;
        return *this;
    }
    Node* cur = rhs.head;
    while(cur != nullptr) {
        this->pushBack(cur->data);
        cur = cur->pNext;
    }
    return *this;
}


List::~List() {
    while(head != nullptr) {
        Node* temp = head->pNext;
        delete head;
        head = temp;
    }
}

void List::pushBack(int val) {
    if(head == nullptr) {
        head = new Node{val, nullptr};
    } else {
        Node* cur = head;
        while(cur->pNext != nullptr) {
            cur = cur->pNext;
        }
        cur->pNext = new Node{val, nullptr};
    }
    size++;
}

bool List::isEmpty() const noexcept {
    return head == nullptr;
}

void List::print() {
    Node* cur = head;
    while(cur != nullptr) {
        std::cout << cur->data << " ";
        cur = cur->pNext;
    }
}




int main() {
    List l1;
    l1.pushBack(1);
    l1.pushBack(2);
    List l2(l1);
    l2.pushBack(3);
    l1.print();
    std::cout << "\n";
    l2.print();
    List l3 = l1;
    std::cout << "\n";
    l3.pushBack(123);
    l3.print();
    return 0;
}
