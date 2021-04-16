#include <iosfwd>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>


class MatrixVr {
public:
  MatrixVr(): n_row_(0), n_col_(0), data_({nullptr}){}
  MatrixVr(std::ptrdiff_t row_count, std::ptrdiff_t col_count) noexcept(false);
  MatrixVr(const MatrixVr& rhs) noexcept;
  ~MatrixVr();
  MatrixVr& operator=(const MatrixVr& rhs) noexcept;
  
  float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false);
  float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false);
  
  bool operator==(const MatrixVr& rhs) const noexcept;
  std::ptrdiff_t Count_row() const noexcept { return n_row_; }
  std::ptrdiff_t Count_col() const noexcept { return n_col_; }
  
  float* begin() noexcept { return data_; }
  float* begin() const noexcept { return data_; }
  float* end() noexcept { return data_ + n_col_ * n_row_; }
  float* end() const noexcept { return data_ + n_col_ * n_row_; }


  std::ostream& writeTo(std::ostream& out) const noexcept;

private:
  std::ptrdiff_t n_row_ {0};
  std::ptrdiff_t n_col_ {0};
  float* data_{nullptr};

};


MatrixVr::MatrixVr(std::ptrdiff_t row_count, std::ptrdiff_t col_count) noexcept(false){
  if(row_count < 0 || col_count < 0) throw std::out_of_range("ERROR");
  if((row_count != col_count) && (row_count == 0 || col_count == 0)) throw std::out_of_range("ERROR");
  if(row_count == 0 || col_count == 0) { return; }
  n_row_ = row_count;
  n_col_ = col_count;
  data_ = new float[row_count * col_count];
}



MatrixVr::~MatrixVr(){
  delete[] data_;
  data_ = nullptr;
}


MatrixVr& MatrixVr::operator=(const MatrixVr& rhs) noexcept {
  if((*this) == rhs) return (*this);
  delete[] data_;
  n_row_ = rhs.n_row_;
  n_col_ = rhs.n_col_;
  data_ = new float[rhs.n_col_ * rhs.n_row_];
  std::copy(rhs.begin(), rhs.end(), begin());
  return (*this);
}


bool MatrixVr::operator==(const MatrixVr &rhs) const noexcept{
    bool res = true;
    if(n_col_ != rhs.n_col_ || n_row_ != rhs.n_row_)
        res = false;
    for(std::ptrdiff_t i = 0; i < n_row_ * n_col_; ++i){
        if(data_[i] != rhs.data_[i]){
            res = false;
            break;
        }
    }
    return res;
}


std::ostream& MatrixVr::writeTo(std::ostream& out) const noexcept{
    size_t c = 0;
    for (const auto& x : (*this)) {
        out << x << " ";
        ++c;
        if (c % n_col_ == 0 && c != n_col_ * n_row_)
            out << std::endl;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const MatrixVr& matr) noexcept{
    matr.writeTo(out);
    return out;
}


float& MatrixVr::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false){
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[i_row * n_col_ + i_col];
}

float MatrixVr::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false) {
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[i_row * n_col_ + i_col];
}



int main(){
  MatrixVr matr(5, 5);
  for(int i = 0; i < 5; ++i){
    for(int j = 0; j < 5; ++j){
      matr.at(i,j) = 10;
    }
  }
  std::cout << matr;
  


  return 0;
}