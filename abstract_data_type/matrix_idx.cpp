#include <iosfwd>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>


class MatrixVr {
public:
    MatrixVr() : n_row_(0), n_col_(0), data_(nullptr){}
    MatrixVr(const MatrixVr& rhs) noexcept;
    MatrixVr(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false);
    ~MatrixVr() noexcept;
    MatrixVr& operator=(const MatrixVr& rhs) noexcept;
    std::ptrdiff_t rowCount() const noexcept { return n_row_;}
    std::ptrdiff_t colCount() const noexcept { return n_col_;}
    float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false);
    float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false);
    float* begin() noexcept { return data_; }
    float* begin() const noexcept { return data_; }
    float* end() noexcept { return  data_ + n_col_*n_row_; }
    float* end() const noexcept { return  data_ + n_col_*n_row_; }


    bool operator==(const MatrixVr& rhs) const noexcept;
    MatrixVr& transpose() noexcept;
    MatrixVr& multiply(const MatrixVr& rhs) noexcept(false);
    void swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
    void swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
    std::ostream& writeTo(std::ostream& out) const noexcept;
private:
    std::ptrdiff_t n_row_{0};
    std::ptrdiff_t n_col_{0};
    float* data_{nullptr};

};

std::ostream& operator<<(std::ostream& out, const MatrixVr& matr) noexcept;

MatrixVr::MatrixVr(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false){
    if (row_count < 0 || col_count < 0) throw std::out_of_range("Index of element was out of range!");
    if((col_count != row_count)&&(col_count == 0 || row_count == 0)) throw std::invalid_argument("columns or rows were equal to zero");
    if(row_count == 0 || col_count == 0){ return; }
    n_row_ = row_count;
    n_col_ = col_count;
    data_ = new float[row_count*col_count]{0};
}

MatrixVr::~MatrixVr() noexcept{
    delete[] data_;
}

MatrixVr::MatrixVr(const MatrixVr &rhs) noexcept
    : n_row_(rhs.n_row_), n_col_(rhs.n_col_), data_(new float[rhs.n_row_ * rhs.n_col_]{0}) {
    std::copy(rhs.begin(), rhs.end(), begin());
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

float& MatrixVr::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false){
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[i_row * n_col_ + i_col];
}

float MatrixVr::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false) {
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[i_row * n_col_ + i_col];
}

MatrixVr& MatrixVr::transpose() noexcept {
    MatrixVr res(n_row_, n_col_);
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            res.at(j, i) = this->at(i, j);
        }
    }
    (*this) = res;
    return (*this);
}

MatrixVr& MatrixVr::multiply(const MatrixVr& rhs) noexcept(false) {
    if(n_col_ != rhs.n_row_) throw std::invalid_argument("Cannot multiply matrices with these parameters");
    MatrixVr res(rhs.colCount(), this->rowCount());
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

void MatrixVr::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_row_ || i_second >= n_row_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    auto it1 = begin() + i_first * n_col_;
    auto it2 = begin() + i_second * n_col_;
    std::swap_ranges(it1, it1 + n_col_, it2);
}

void MatrixVr::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_col_ || i_second >= n_col_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    std::vector<float> temp;
    for(std::ptrdiff_t i = i_first; i < n_col_ * n_row_; i += n_col_){
        temp.push_back(data_[i]);
    }
    for(std::ptrdiff_t i = i_second, j = i_first; i < n_col_ * n_row_; i += n_col_, j += n_col_){
        data_[j] = data_[i];
    }
    for(std::ptrdiff_t i = i_second, j = 0; i < n_col_ * n_row_; i += n_col_, j++){
        data_[i] = temp[j];
    }
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

int main() {


  return 0;
}