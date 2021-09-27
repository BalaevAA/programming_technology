#include<iostream>

struct Node {
    float* data = 0.0f;
    Node* pNext = nullptr;
};

class queueL {
public:
    queueL() = default;
    queueL(const queueL& li);
    queueL operator=(const queueL& rhs);
    ~queueL();
    void push_front(const float value);
    void pop_back();
    bool empty() const noexcept;
    void print();
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int capacity = 0;
};

queueL::queueL(const queueL& li) {
    if(li.empty()) {
        head = nullptr;
        return;
    }
    Node* cur = li.head;
    while(cur != nullptr) {
        this-> push_front(cur->data);
        cur = cur->pNext;
    }
}

queueL queueL::operator=(const queueL& rhs) {
    if(rhs.empty()) {
        head = nullptr;
        return *this;
    }
    Node* cur = rhs.head;
    while(cur != nullptr) {
        this-> push_front(cur->data);
        cur = cur->pNext;
    }
    return *this;
}

queueL::~queueL() {
    while(head != nullptr) {
        Node* temp = head->pNext;
        delete head;
        head = temp;
    }
}

void queueL::push_front(const float value) {
    if(head == nullptr) {
        head = new Node{value, nullptr};
        tail = head;
    } else {
        head = new Node{value, head};
    }
    capacity++;
}

void queueL::pop_back() {
    if (empty()) return;
    if (head == tail) {
        head = nullptr;

        return;
    }
    Node* cur = head;
    while(cur->pNext != tail) cur = cur->pNext;
    cur->pNext = nullptr;
    delete tail;
    tail = cur;
    capacity--;
}

bool queueL::empty() const noexcept {
    return head == nullptr;
}

void queueL::print() {
    if(empty()) return;
    Node* cur = head;
    while (cur != nullptr) {
      std::cout << cur->data << " ";
      cur = cur->pNext;
    }
    std::cout << std::endl;
}

int main() {
    queuaL q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.print();
    std::cout << q.top() <<"\n";
    q.pop();
    q.print();
    std::cout << q.top() <<"\n";
    q.print();
    return 0;
}
