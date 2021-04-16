#include<iostream>

class StackA{
public:
  StackA() = default;
  StackA(const StackA& s);
  StackA operator=(const StackA& rhs);
  ~StackA();
  void push(const float value);
  void pop();
  float& top();
  bool is_empty() const noexcept;
private:
  float* st {nullptr};
  int capacity{0};
};

StackA::StackA(const StackA& s){
  if(s.is_empty()) return;
  capacity = s.capacity;
  st = new float[capacity]{0};
  for(int i = 0; i < capacity; ++i){
    st[i] = s.st[i]; 
  }
}

StackA StackA::operator=(const StackA& rhs){
  if(rhs.is_empty()) return (*this);
  capacity = rhs.capacity;
  float* new_st = new float[capacity]{0};
  for(int i = 0; i < rhs.capacity; ++i){
    new_st[i] = rhs.st[i];
  }
  delete[] st;
  st = new_st;
  return (*this);
}

StackA::~StackA(){
  delete[] st;
}

void StackA::push(const float value){
  float* st1 = new float[capacity + 1];
  if(capacity == 0){
      st1[0] = value;
  } else {
      for(int i = 0; i < capacity; ++i){
        st1[i] = st[i];
      } 
      st1[capacity] = value;
  }
  if(capacity > 0){
    delete[] st;
  }
  capacity++;
  st = st1;
}

void StackA::pop() {
  float* st1 = new float[capacity-1];
  if(this->is_empty()) {
    throw std::out_of_range("Stack is empty");
  }
  for(int i = 0; i < capacity - 1; ++i){
    st1[i] = st[i];
  }
  if(capacity > 0){
    delete[] st;
  }
  capacity -= 1;
  st = st1;
}

float& StackA::top(){
  if(this->is_empty()) {
    throw std::out_of_range("Stack is empty");
  }
  return st[capacity-1];
}

bool StackA::is_empty() const noexcept {
  return capacity == 0;
}


int main(){
  StackA st;
  std::cout << st.is_empty() << "\n";
  //std::cout << st.top() << "\n";
  st.push(12);
  std::cout << st.is_empty() << "\n";
  std::cout << st.top() << "\n";
  st.push(13);
  st.push(15);
  std::cout << st.is_empty() << "\n";
  st.pop();
  st.pop();
  st.pop();
  std::cout << st.is_empty() << "\n";
  st.push(199);
  std::cout << st.top() << "\n";
  st.push(11);
  std::cout << st.top() << "\n";
  return 0;
}


