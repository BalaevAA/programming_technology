#include <iostream>
 
class QueueL{
public:
    QueueL() = default;
    QueueL(const QueueL& rhs){
        if(rhs.is_empty()) {head_ = nullptr; return; }
        auto rhs_ptr = rhs.head_;
        auto this_prt = new Node;
        head_ = this_prt;
        while (rhs_ptr != nullptr){
            this_prt->data = rhs_ptr->data;
            if(rhs_ptr->next != nullptr){
                this_prt->next = new Node;
                this_prt = this_prt->next;
            }
            rhs_ptr = rhs_ptr->next;
        }
    };
    QueueL operator=(const QueueL& rhs){
        if(rhs.is_empty()) { head_ = nullptr; return (*this); }
        QueueL rhs_copy(rhs);
        while(!this->is_empty()){
            this->pop();
        }
        auto rhs_ptr = rhs_copy.head_;
        auto this_ptr = new Node;
        head_ = this_ptr;
        while(rhs_ptr != nullptr){
            this_ptr->data = rhs_ptr->data;
            if(rhs_ptr->next != nullptr) {
                this_ptr->next = new Node;
                this_ptr = this_ptr->next;
            }
            rhs_ptr = rhs_ptr->next;
        }
        return (*this);
    }
    void push(std::pair<int, float> val){
        int prior = val.first;
        if(head_ == nullptr){
            head_ = new Node({val, nullptr});
        }else{
            while(prior <= head_->data.first && head_->next ){
                head_ = head_->next;
            }
            Node* tmp = new Node({val, head_});
            head_= tmp;
        }
    }
    void pop(){
        if (head_ != nullptr){
            auto new_head_ = head_->next;
            delete head_;
            head_ = new_head_;
        }
    }
    std::pair<int,float>& top(){
        if(head_ == nullptr) throw std::out_of_range("Stack is empty");
        return head_->data;
    }
    const std::pair<int,float>& top() const{
        if(head_ == nullptr) throw std::out_of_range("Stack is empty");
        return head_->data;
    }
    bool is_empty() const noexcept{
        return head_ == nullptr;
    }
    ~QueueL(){
        while(!this->is_empty()){
            this->pop();
        }
    }
private:
    struct Node{
        std::pair<int, float> data{0,0};
        Node* next = nullptr;
    };
    Node* head_ = nullptr;
};
 
 
 
int main() {
 
    QueueL a;
    std::pair<int, float> a1 {1,3.2};
    std::pair<int, float> a2 {2,3.2};
    std::pair<int, float> a3 {3,3.2};
    std::pair<int, float> a4 {4,3.2};
    std::pair<int, float> a5 {5,3.2};
    std::pair<int, float> a7 {5,4};
    std::pair<int, float> a6 {6,3.2};
    a.push(a1);
    std::cout << a.top().first << std::endl;
    a.push(a2);
    std::cout << a.top().first << std::endl;
    a.push(a3);
    std::cout << a.top().first << std::endl;
    a.push(a4);
    std::cout << a.top().first << std::endl;
    a.push(a5);
    std::cout << a.top().first << std::endl;
    a.pop();
    std::cout << a.top().first << std::endl;
    return 0;
}