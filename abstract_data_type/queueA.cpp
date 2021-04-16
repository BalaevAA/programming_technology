#include<iostream>
#include<stdexcept>


class QueueA{
public:
  QueueA() = default;
  QueueA(const QueueA& q);
  QueueA& operator=(const QueueA& rhs);
  ~QueueA();
  bool is_empty() const noexcept;
  void push(float value);
  void pop() noexcept;
  float& top();
private:
  std::ptrdiff_t capacity_ = 0;
  std::ptrdiff_t i_head_ = -1;
  std::ptrdiff_t i_tail_ = -1;
  float* data_ = nullptr;
};

QueueA::QueueA(const QueueA& q){
  if(q.is_empty()) return;
  capacity_ = q.capacity_;
  data_ = new float[capacity_]{0};
  std::ptrdiff_t c = 0;
  for(std::ptrdiff_t i = q.i_head_ % q.capacity_; i != q.i_tail_; i = (i + 1) % q.capacity_ ,++c){
    data_[c] = q.data_[i];
  }
  data_[i_tail_] = q.data_[q.i_tail_];

  if(q.i_tail_ < q.i_head_){
    i_tail_ = q.capacity_ - q.i_head_ + i_tail_;
  } else {
      i_tail_ = q.i_tail_ - q.i_head_;
  }
  i_head_ = 0;

}

QueueA& QueueA::operator=(const QueueA& rhs){
  if(rhs.data_ == nullptr){
    delete[] data_;
    i_head_ = -1;
    i_tail_ = -1;
    data_ = nullptr;
    return (*this);
  }
  std::ptrdiff_t new_capacity = rhs.capacity_;
  auto new_data_ = new float[new_capacity]{0};
  std::ptrdiff_t c = 0;
  for(std::ptrdiff_t i = rhs.i_head_ % rhs.capacity_; i != rhs.i_tail_; i = (i + 1) % rhs.capacity_, ++c){
    new_data_[c] = rhs.data_[i];
  }
  new_data_[c] = rhs.data_[rhs.i_tail_];
  capacity_ = new_capacity;
  delete[] data_;
  data_ = new_data_;
  if(rhs.i_tail_ < rhs.i_head_){
    i_tail_ = rhs.capacity_  - rhs.i_head_ + rhs.i_tail_;
  } else {
      i_tail_ = rhs.i_tail_ - rhs.i_head_;
  }
  i_head_ = 0;
  return (*this);
}

// Деструктор
QueueA::~QueueA() {
  delete[] data_;
}

void QueueA::push(const float value){
  if(is_empty()){
    capacity_ = 2;
    data_ = new float[capacity_]{0};
    i_head_ = 0;
    i_tail_ = 0;
    data_[i_head_] = value;
    return;
  }
  std::ptrdiff_t new_i_tail_ = (i_tail_ + 1) % capacity_;
  if(new_i_tail_ == i_head_){
    auto new_capacity = capacity_ * 2;
    auto new_data_ = new float[new_capacity]{0};
    std::ptrdiff_t c = 0;
    for(std::ptrdiff_t i = i_head_ % capacity_; i != i_tail_; i = (i + 1) % capacity_, ++c){
      new_data_[c] = data_[i];
    }
    new_data_[c] = data_[i_tail_];
    ++c;
    new_data_[c] = value;
    capacity_ = new_capacity;
    delete[] data_;
    data_ = new_data_;
    i_head_ = 0;
    i_tail_ = c;
  } else {
      i_tail_ = new_i_tail_;
      data_[i_tail_] = value;
  }
}

void QueueA::pop() noexcept {
  if(!is_empty()){
    if(i_tail_ == i_head_){
      i_head_ = -1;
      i_tail_ = -1;
    } else {
        i_head_ = (i_head_ + 1) % capacity_;
    }
  }
}

float& QueueA::top(){
  if(is_empty()) throw std::out_of_range("Queue is empty");
  return data_[i_head_];
}

bool QueueA::is_empty() const noexcept {
  return i_head_ == -1;
}


int main(){
  QueueA q;

  std::cout << q.is_empty() << "\n";
  
  q.push(10);

  std::cout << q.is_empty() << "\n";

  q.push(11);

  std::cout << q.top() << "\n";

  q.push(12);

  q.pop();
  q.pop();
  q.pop();

  std::cout << q.top() << "\n";

  return 0;
}

