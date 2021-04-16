#include<iostream>
#include<stdexcept>

class ArrayD{
public:
  ArrayD() = default;
  ArrayD(const ArrayD& a);
  ArrayD& operator=(const ArrayD& rhs);
  ~ArrayD();
  void push(float value);
  int get_capacity();
  bool is_empty() const noexcept;
  void print();
private:
  float* array = nullptr;
  int capacity = 0;
};

ArrayD::ArrayD(const ArrayD& a){
  if(a.is_empty()) return;
  capacity = a.capacity;
  array = new float[capacity]{0};
  for(int i = 0; i < capacity; ++i){
    array[i] = a.array[i];
  }
}

ArrayD& ArrayD::operator=(const ArrayD& rhs){
  if(rhs.is_empty()) return (*this);
  capacity = rhs.capacity;
  float* new_array = new float[capacity]{0};
  for(int i = 0; i < rhs.capacity; ++i){
    new_array[i] = rhs.array[i];
  }
  delete[] array;
  array = new_array;
  return (*this);
}

ArrayD::~ArrayD(){
  delete[] array;
}

void ArrayD::push(float value){
  float* a1 = new float[capacity + 1];
  if(capacity == 0){
      a1[0] = value;
  } else {
      for(int i = 0; i < capacity; ++i){
        a1[i] = array[i];
      } 
      a1[capacity] = value;
  }
  if(capacity > 0){
    delete[] array;
  }
  capacity++;
  array = a1;
}

int ArrayD::get_capacity(){
  return capacity;
}

bool ArrayD::is_empty() const noexcept{
  return capacity == 0;
}

void ArrayD::print(){
  for(int i = 0; i < capacity; ++i){
    std::cout << array[i] << " ";
  }
}

int main(){
  ArrayD a;

  std::cout << a.is_empty() << "\n";
  std::cout << a.get_capacity() << "\n";
  a.push(20);
  std::cout << a.is_empty() << "\n";
  std::cout << a.get_capacity() << "\n";
  a.push(10);
  a.push(12);
  a.push(8);
  std::cout << a.get_capacity() << "\n";
  a.print();
  return 0;
}

