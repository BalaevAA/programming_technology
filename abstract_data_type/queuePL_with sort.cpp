#include<iostream>

struct Node {
    std::pair<int, float> data{0,0.0f};
    Node* pNext = nullptr;
};

class queuePL {
public:
    queuePL() = default;
    queuePL(const queuePL& q);
    queuePL operator=(const queuePL& rhs);
    ~queuePL();
    void push_front(std::pair<int, float> value);
    void pop_back();
    bool empty() const noexcept;
    void sort();
    int getSize();
    void print();
    // std::pair<int, float> operator[](int index);
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int capacity = 0;
};

queuePL::queuePL(const queuePL& q) {
    if(q.empty()) {
        head = nullptr;
        return;
    }
    Node* cur = q.head;
    while(cur != nullptr) {
        this-> push_front(cur->data);
        cur = cur->pNext;
    }
}

queuePL queuePL::operator=(const queuePL& rhs) {
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

queuePL::~queuePL() {
    while(head != nullptr) {
        Node* temp = head->pNext;
        delete head;
        head = temp;
    }
}

void queuePL::push_front(std::pair<int, float> value) {
    if(head == nullptr) {
        head = new Node{value, nullptr};
        tail = head;
    } else {
        head = new Node{value, head};
    }
    capacity++;
    sort();
}

void queuePL::pop_back() {
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

bool queuePL::empty() const noexcept {
    return head == nullptr;
}

// std::pair<int, float> queuePL::operator[](int index) {
//     int counter = 0;
//     Node* cur = head;
//     while(cur != nullptr) {
//         if(index == counter) {
//             return cur->data;
//         }
//         cur = cur->pNext;
//         counter++;
//     }
// }


void queuePL::sort(){
  Node* cur1 = head;
  Node* cur2 = head;
  for (int i = 0; i < getSize(); ++i) {
    for (int j = 0; j < getSize() - 1; ++j) {
      if (cur1->data.first > cur2->data.first) {
        std::pair<int, float> temp = cur1->data;
        cur1->data = cur2->data;
        cur2->data = temp;
      }
      cur2 = cur2->pNext;
    }
    cur2 = head;
    cur1 = head->pNext;
    for (int k = 0; k < i; ++k) {
      cur1 = cur1->pNext;
    }
  }
}

void queuePL::print() {
    if(empty()) return;
    Node* cur = head;
    while (cur != nullptr) {
      std::cout << cur->data.first << " " << cur->data.second << "\n";
      cur = cur->pNext;
    }
    std::cout << std::endl;
}

int queuePL::getSize() {
  return capacity;
}

int main() {
    queuePL a;
    a.push_front({1,2});
    a.push_front({7,9});
    a.push_front({11,42});
    a.print();
    a.pop_back();
    a.print();
    a.push_front({1, 5});
    a.print();
    a.push_front({4, 5});
    a.print();
    return 0;
}
