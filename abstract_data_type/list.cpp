#include<iostream>

class List {
public:
  List() = default;
  List(const List& l);
  List operator=(const List& l);
  float& operator[](const int index);
  ~List();
  int get_size();
  void push_back(const float value);
  void push_front(const float value);
  void pop_front();
  void clear();
  bool is_empty();
private:
  struct Node {
    float value = 0.0f;
    Node *pNext = nullptr;
  };
private:
  Node* head_ = nullptr;
  int size = 0;
};

List::~List(){
  clear();
}

int List::get_size(){
  return size;
}

void List::push_back(const float value){
  if(head_ == nullptr){
      head_ = new Node{value, nullptr};
  } else {
      Node* current = this->head_;
      while(current->pNext != nullptr){
        current = current->pNext;
      }
      current->pNext = new Node{value, nullptr};
  }
  size++;
}

void List::push_front(const float value){
  head_ = new Node{value, head_};
  size++;
}


void List::pop_front(){
  Node* temp = new Node;
  temp = head_->pNext;
  delete head_;
  head_ = temp;
  size--;
}

void List::clear(){
  while(!this->is_empty()){
    this->pop_front();
  }
}

bool List::is_empty(){
  return head_ == nullptr;
}

float& List::operator[](const int index) {
	Node* current = this->head_;
	int k = 0;
	while (current != nullptr) {
		if (k == index) {
			return current->value;
		}
		current = current->pNext;
		k++;
	}
}


int main(){
  List li;
  li.push_back(12);
  li.push_back(11);

  for (int i = 0; i < li.get_size(); ++i) {
    std::cout << li[i] << " ";
  }
  std::cout << "\n";
  li.pop_front();

  for (int i = 0; i < li.get_size(); ++i) {
    std::cout << li[i] << " ";
  }
  
  li.push_back(42);
  li.push_back(84);
  std::cout << "\n";
  for (int i = 0; i < li.get_size(); ++i) {
    std::cout << li[i] << " ";
  }
  
  li.push_front(10000);
  std::cout << "\n";
  for (int i = 0; i < li.get_size(); ++i) {
    std::cout << li[i] << " ";
  }
  return 0;
}