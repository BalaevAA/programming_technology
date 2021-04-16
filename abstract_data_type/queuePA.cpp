#include<iostream>
#include<stdexcept>

class QueuePA {
public:
  QueuePA() = default;
  QueuePA(const QueuePA& q);
  QueuePA operator=(const QueuePA& rhs);
  ~QueuePA();
  void push(std::pair<int, float> elem);
  void pop() noexcept;
  float& top();
  bool is_empty() const noexcept;
  void print();
private:
  std::pair<int, float>* qp = nullptr;
  int capacity = 0;
};

QueuePA::QueuePA(const QueuePA& q){
  if(q.is_empty()){
    return;
  }
  capacity = q.capacity;
  qp = new std::pair<int, float>[capacity];
  for(std::ptrdiff_t i = 0; i < capacity; ++i){
    qp[i] = q.qp[i];
  }
}

QueuePA QueuePA::operator=(const QueuePA& rhs){
  if(rhs.is_empty()){
    qp = nullptr;
    return (*this);
  }
  auto new_capacity = rhs.capacity;
  auto new_qp = new std::pair<int, float>[new_capacity];
  for(std::ptrdiff_t i = 0; i < new_capacity; i++){
    new_qp[i] = rhs.qp[i];
  }
  capacity = new_capacity;
  delete[] qp;
  qp = new_qp;
  return (*this);
}

void QueuePA::push(std::pair<int, float> elem){
  std::pair<int, float>* temp = new std::pair<int, float>[capacity + 1];
  int pos = 0;
  if(is_empty()){
    pos = 0;
  } else {
      pos = 0;
      for(pos = 0; pos < capacity; ++pos){
        if(qp[pos].first <= elem.first){
          break;
        }
      }
  }
  for(std::ptrdiff_t i = 0; i < pos; ++i){
    temp[i] = qp[i];
  }
  temp[pos] = elem;
  for(std::ptrdiff_t i = pos + 1; i < capacity + 1; ++i){
    temp[i] = qp[i-1]; 
  }
  if(capacity > 0){
    delete[] qp;
  }
  qp = temp;
  capacity++;
}

void QueuePA::pop() noexcept {
  if(!is_empty()){
    std::pair<int, float>* temp = new std::pair<int, float>[capacity-1];
    std::ptrdiff_t c = 0;
    for(std::ptrdiff_t i = 1; i < capacity; ++i, ++c){
      temp[c] = qp[i];
    }
    if(capacity > 0){
      delete[] qp;
    }
    qp = temp;
    capacity -= 1;
  } 
}

bool QueuePA::is_empty() const noexcept {
  return capacity == 0;
}


QueuePA::~QueuePA(){
  while(!this->is_empty()){
    this->pop();
  }
}

float& QueuePA::top(){
  std::cout << "test method top\n";
  if(is_empty()) throw std::out_of_range("Queue is empty");
  return qp->second;
}

void QueuePA::print(){
  if(is_empty()){
    std::cout << "queue is empty\n";
  } else {
    std::cout << "test method print\n";
    for (int i = 0; i < capacity; ++i){
      std::cout << qp[i].first << " : " << qp[i].second << std::endl;
    }
  }
}

int main() {
  QueuePA a;

  std::cout << a.is_empty() << std::endl;
  a.push(std::make_pair(12, 14));
  std::cout << a.is_empty() << std::endl;
  a.push(std::make_pair(100, 12));
  a.push(std::make_pair(100, 13));
  a.push(std::make_pair(99, 12));
  a.print();
  std::cout << a.top() << std::endl;
  a.pop();
  std::cout << a.top() << std::endl;
  a.print();
  QueuePA b(a);
  QueuePA c = b;
  b.push(std::make_pair(121, 1));
  c.pop();
  b.print();
  c.print();
  c.pop();
  c.print();
  c.pop();
  c.print();
 
  return 0;
}