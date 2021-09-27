#include<iostream>
#include<cassert>


class QueueA3 {
public:
    QueueA3();
    QueueA3(const QueueA3& q);
    QueueA3 operator=(const QueueA3& rhs);
    ~QueueA3();
    void push(const float value);
    void pop() noexcept;
    bool empty() const noexcept;
    float& top();
    std::ptrdiff_t i_head = -1;
    std::ptrdiff_t i_tail = -1;
    std::ptrdiff_t capacity = 0;
private:
    float* data = nullptr;
};

QueueA3::QueueA3(const QueueA3& q) {
    if(q.empty()) return;
    i_tail = q.i_tail;
    i_head = q.i_head;
    capacity = q.capacity;
    data = new float[capacity]{0};
    for(int i = 0; i < capacity; ++i) {
        data[i] = q.data[i];
    }
}

QueueA3 QueueA3::operator=(const QueueA3& rhs) {
    if(rhs.empty()) return *this;
    i_head = rhs.i_head;
    i_tail = rhs.i_tail;
    if(data != nullptr) delete[] data;
    capacity = rhs.capacity;
    data = new float[capacity]{0};
    for(int i = 0; i < capacity; ++i) {
        data[i] = rhs.data[i];
    }
    return *this;
}

QueueA3::~QueueA3() {
    delete[] data;
}

void QueueA3::push(const float value) {
    if(data == nullptr) {
        capacity = 2;
        i_head = 0;
        i_tail = 0;
        data = new float[capacity]{0};
    }
    if((i_tail < i_head && i_head - i_tail == 1) || (i_head == 0 || i_tail == capacity - 1)) {
        float* temp = new float[capacity]{0};
        int i = 0;
        while(!this->empty()) {
            temp[i] = this->top();
            this->pop();
            i++;
        }
        delete[] data;
        data = new float[capacity * 2]{0};
        for(int i = 1, j = 0; j < capacity; ++i, ++j) {
            data[i] = temp[j];
        }
        i_head = 0;
        i_tail = capacity - 1;
        capacity *= 2;
    }
}

void QueueA3::pop() noexcept {
    assert(!this->empty());
    i_head = (i_head + 1) % capacity;
}

bool QueueA3::empty() const noexcept {
    return i_tail == i_head;
}

float& QueueA3::top() {
    assert(!this->empty());
    return data[(i_tail + 1) % capacity];

}


int main() {
    QueueA3 q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    std::cout << q1.top() << "\n";
    QueueA3 q2(q1);
    q2.push(4);
    q2.pop();
    q2.pop();
    q2.pop();
    std::cout << q2.top() << "\n";
    QueueA3 q3 = q1;
    q3.push(41924);
    q3.pop();
    q3.pop();
    q3.pop();
    return 0;
}
