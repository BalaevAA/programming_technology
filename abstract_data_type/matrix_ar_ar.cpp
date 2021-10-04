#include <iosfwd>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class MatrixDr {
public:
    MatrixDr() : n_row_(0), n_col_(0), data_(nullptr){}
    MatrixDr(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false);
    MatrixDr(const MatrixDr& rhs) noexcept;
    ~MatrixDr() noexcept;
    size_t rowCount() const noexcept { return n_row_;  }
    size_t colCount() const noexcept { return n_col_;  }
    float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false);
    float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false);
    std::ostream& writeTo(std::ostream& out) const noexcept;
    float* begin(std::ptrdiff_t i_row) noexcept(false);
    float* begin(std::ptrdiff_t i_row) const noexcept(false);
    float* end(std::ptrdiff_t i_row) noexcept(false);
    float* end(std::ptrdiff_t i_row) const noexcept(false);
    
    
    MatrixDr& operator=(const MatrixDr& rhs) noexcept;
    bool operator==(const MatrixDr& rhs) const noexcept;
    MatrixDr& multiply(MatrixDr rhs) noexcept(false);
    MatrixDr& transpose() noexcept;
    void swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
    void swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
private:
    std::ptrdiff_t n_row_{0};
    std::ptrdiff_t n_col_{0};
    float** data_{nullptr};
};


std::ostream& operator<<(std::ostream& out, const MatrixDr& matr) noexcept;

MatrixDr::MatrixDr(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false) {
    if (row_count < 0 || col_count < 0) throw std::out_of_range("Index of element was out of range!");
    if((col_count != row_count)&&(col_count == 0 || row_count == 0)) throw std::invalid_argument("columns or rows were equal to zero");
    if(row_count == 0 || col_count == 0){ return; }
    n_row_ = row_count;
    n_col_ = col_count;
    data_ = new float*[row_count];
    for(std::ptrdiff_t i = 0; i < row_count; ++i){
        data_[i] = new float[col_count]{0};
    }
}

MatrixDr::MatrixDr(const MatrixDr& rhs) noexcept
    : n_row_(rhs.n_row_), n_col_(rhs.n_col_){
    data_ = new float*[rhs.n_row_];
    if(n_row_ == 0) data_ = nullptr;
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        data_[i] = new float[n_col_]{0};
        std::copy(rhs.begin(i), rhs.end(i), begin(i));
    }
}

float* MatrixDr::begin(std::ptrdiff_t i_row) noexcept(false) {
    if(i_row < 0 || i_row >= n_row_) throw std::out_of_range("Index of element was out of range!");
    return *(data_ + i_row);
}

float* MatrixDr::begin(std::ptrdiff_t i_row) const noexcept(false) {
    if(i_row < 0 || i_row >= n_row_) throw std::out_of_range("Index of element was out of range!");
    return *(data_ + i_row);
}

float *MatrixDr::end(std::ptrdiff_t i_row) noexcept(false) {
    if(i_row < 0 || i_row >= n_row_) throw std::out_of_range("Index of element was out of range!");
    return *(data_ + i_row) + n_col_;
}

float* MatrixDr::end(std::ptrdiff_t i_row) const noexcept(false) {
    if(i_row < 0 || i_row >= n_row_) throw std::out_of_range("Index of element was out of range!");
    return *(data_ + i_row) + n_col_;
}

MatrixDr::~MatrixDr() noexcept{
    for(std::ptrdiff_t i = 0 ; i < n_row_; ++i){
        delete[] data_[i];
    }
    delete[] data_;
}


MatrixDr& MatrixDr::operator=(const MatrixDr& rhs) noexcept{
    if((*this) == rhs) return (*this);
    for(std::ptrdiff_t i = 0 ; i < n_row_; ++i){
        delete[] data_[i];
    }
    delete[] data_;
    n_row_ = rhs.n_row_;
    n_col_ = rhs.n_col_;
    data_ = new float*[n_row_];
    if(n_row_ == 0) data_ = nullptr;
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        data_[i] = new float[n_col_]{0};
        std::copy(rhs.begin(i), rhs.end(i), begin(i));
    }
    return (*this);
}

bool MatrixDr::operator==(const MatrixDr &rhs) const noexcept {
    bool res = true;
    if(n_col_ != rhs.n_col_ || n_row_ != rhs.n_row_) res = false;
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        if(!res) break;
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            if(data_[i][j] != rhs.data_[i][j]){
                res = false;
                break;
            }
        }
    }
    return res;
}

float& MatrixDr::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false) {
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[i_row][i_col];
}

float MatrixDr::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false) {
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[i_row][i_col];
}

std::ostream& MatrixDr::writeTo(std::ostream &out) const noexcept {
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            out << data_[i][j];
            if(j != n_col_ - 1) out << " ";
        }
        if(i != n_row_ - 1) out << std::endl;
    }
    return out;
}

MatrixDr& MatrixDr::multiply(MatrixDr rhs) noexcept(false) {
    if(n_col_ != rhs.n_row_) throw std::invalid_argument("Cannot multiply matrices with these parameters");
    MatrixDr res(rhs.colCount(), this->rowCount());
    for (std::ptrdiff_t i = 0; i < this->rowCount(); ++i){
        for (std::ptrdiff_t j = 0; j < rhs.colCount(); ++j){
            res.at(i, j) = 0;
            for (std::ptrdiff_t k = 0; k < rhs.rowCount(); ++k){
                res.at(i, j) += this->at(i, k) * rhs.at(k, j);
            }
        }
    }
    (*this) = res;
    return (*this);
}

MatrixDr& MatrixDr::transpose() noexcept {
    MatrixDr res(n_row_, n_col_);
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            res.at(j, i) = this->at(i, j);
        }
    }
    (*this) = res;
    return (*this);
}

void MatrixDr::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_row_ || i_second >= n_row_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    auto it1 = (this->begin(i_first));
    auto it2 = (this->begin(i_second));
    std::swap_ranges(it1, it1 + n_col_, it2);
}

void MatrixDr::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_col_ || i_second >= n_col_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    std::vector<float> temp(n_row_);
    for(std::ptrdiff_t i = 0 ; i < n_row_; ++i){
        std::swap(data_[i][i_first], data_[i][i_second]);
    }
}

std::ostream& operator<<(std::ostream& out, const MatrixDr& matr) noexcept{
    return matr.writeTo(out);
}

int main() {

  return 0;
}