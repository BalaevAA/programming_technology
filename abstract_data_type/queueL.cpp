#include<iostream>
#include<stdexcept>

class QueueL {
public:
	QueueL() = default;
	QueueL(const QueueL& q);
	QueueL& operator=(const QueueL& rhs);
	~QueueL();
	bool is_empty() const noexcept;
	void push (const float data);
	void pop() noexcept;
	float& top();

private:
	struct Node {
		float data = 0.0f;
		Node *pNext = nullptr;
	};
private:
	Node* ptr_head = nullptr;
	Node* ptr_tail = nullptr;
};


QueueL::QueueL(const QueueL& q){
	if(q.is_empty()) {ptr_head = nullptr; return;}
	auto rhs_ptr = q.ptr_head;
	auto this_ptr = new Node;
	ptr_head = this_ptr;
	while(rhs_ptr != nullptr){
		this_ptr->data = rhs_ptr->data;
		if(rhs_ptr->pNext != nullptr){
			this_ptr->pNext = new Node;
			this_ptr = this_ptr->pNext;
		}
		rhs_ptr = rhs_ptr->pNext;
	}
}

QueueL& QueueL::operator=(const QueueL& rhs) {
	if(rhs.is_empty()){
		ptr_head = nullptr;
		return (*this);
	}
	QueueL rhs_copy(rhs);
	while(!this->is_empty()){
		this->pop();
	}
	auto rhs_ptr = rhs_copy.ptr_head;
	auto this_ptr = new Node;
	ptr_head = this_ptr;
	while(rhs_ptr != nullptr){
		this_ptr->data = rhs_ptr->data;
		if(rhs_ptr->pNext != nullptr){
			this_ptr->pNext = new Node{0, nullptr};
			this_ptr = this_ptr->pNext;
		}
		rhs_ptr = rhs_ptr->pNext;
	}
	return (*this);
}

QueueL::~QueueL() {
	while(!this->is_empty()){
		this->pop();
	}
}

bool QueueL::is_empty() const noexcept {
	return ptr_head == nullptr;
}


void QueueL::push(const float value) {
	Node* temp = new Node;
	temp->data = value;
	temp->pNext = nullptr;
	if(ptr_head != nullptr){
		ptr_tail->pNext = temp;
		ptr_tail = temp;
	} else {
			ptr_head = ptr_tail = temp;
	}
}


void QueueL::pop() noexcept {
	if(!is_empty()){
		auto new_head = ptr_head->pNext;
		delete ptr_head;
		ptr_head = new_head;
	}
}



float& QueueL::top() {
	if (ptr_head == nullptr) throw std::out_of_range("Queue is empty");
	return ptr_head->data;
}



int main()
{
	QueueL a;
	a.push(1);
	a.push(3);
	std::cout << a.top() << std::endl;
	a.pop();
	std::cout << a.top() << std::endl;
	a.push(4);
	a.push(5);
	a.push(6);
	QueueL b(a);
	QueueL c = b;
	c.pop();
	std::cout << "c top element is "<< c.top() << std::endl;
	std::cout << "b top element is "<<b.top() << std::endl;
}
