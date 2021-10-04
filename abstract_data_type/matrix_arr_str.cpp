#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class MatrixLr{
public:
    MatrixLr() : n_row_(0), n_col_(0), data_(nullptr), rows_(nullptr), cols_(nullptr){}
    MatrixLr(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false);
    MatrixLr(const MatrixLr& rhs) noexcept;
    ~MatrixLr() noexcept;
    MatrixLr& operator=(const MatrixLr& rhs) noexcept;
    size_t rowCount() const noexcept { return n_row_;  }
    size_t colCount() const noexcept { return n_col_;  }
    float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false);
    float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false);
    std::ostream& writeTo(std::ostream& out) const noexcept;

    
    bool operator==(const MatrixLr& rhs) const noexcept;
    MatrixLr& multiply(MatrixLr rhs) noexcept(false);
    MatrixLr& transpose() noexcept;
    void swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
    void swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
private:
    std::ptrdiff_t n_row_{0};
    std::ptrdiff_t n_col_{0};
    float* data_{nullptr};
    std::ptrdiff_t* rows_{nullptr};
    std::ptrdiff_t* cols_{nullptr};
};

std::ostream& operator<<(std::ostream& out, const MatrixLr& matr) noexcept;

MatrixLr::MatrixLr(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false) {
    if(row_count < 0 || col_count < 0) throw std::out_of_range("Index of element was out of range!");
    if((col_count != row_count)&&(col_count == 0 || row_count == 0)) throw std::invalid_argument("columns or rows were equal to zero");
    if(col_count == 0 || row_count == 0) { return; }
    n_row_ = row_count;
    n_col_ = col_count;
    data_ = new float[n_col_ * n_row_]{0};
    rows_ = new std::ptrdiff_t[n_row_]{0};
    cols_ = new std::ptrdiff_t[n_col_]{0};
    std::ptrdiff_t c = 0;
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        rows_[i] = c;
        c += n_col_;
    }
    c = 0;
    for(std::ptrdiff_t i = 0; i < n_col_; ++i){
        cols_[i] = c;
        ++c;
    }
}

MatrixLr::~MatrixLr() noexcept {
    delete[] data_;
    delete[] rows_;
    delete[] cols_;
}

MatrixLr::MatrixLr(const MatrixLr &rhs) noexcept
    : n_row_(rhs.n_row_), n_col_(rhs.n_col_), data_(new float[rhs.n_col_ * rhs.n_row_])
    , rows_(new std::ptrdiff_t[rhs.n_row_]), cols_(new std::ptrdiff_t[rhs.n_col_]){
    std::copy(rhs.data_, rhs.data_ + n_col_*n_row_, data_);
    std::copy(rhs.rows_, rhs.rows_ + n_row_, rows_);
    std::copy(rhs.cols_, rhs.cols_ + n_col_, cols_);
}

MatrixLr& MatrixLr::operator=(const MatrixLr &rhs) noexcept {
    if((*this) == rhs) return (*this);
    delete[] data_;
    delete[] rows_;
    delete[] cols_;
    n_row_ = rhs.n_row_;
    n_col_ = rhs.n_col_;
    data_ = new float[n_col_*n_row_];
    rows_ = new std::ptrdiff_t[n_row_];
    cols_ = new std::ptrdiff_t[n_col_];
    std::copy(rhs.data_, rhs.data_ + n_col_*n_row_, data_);
    std::copy(rhs.rows_, rhs.rows_ + n_row_, rows_);
    std::copy(rhs.cols_, rhs.cols_ + n_col_, cols_);
    return (*this);
}

bool MatrixLr::operator==(const MatrixLr &rhs) const noexcept {
    bool res = true;
    if(n_row_ != rhs.n_row_ || n_col_ != rhs.n_col_) res = false;
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        if(!res) break;
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            if(this->at(i, j) != rhs.at(i, j)){
                res = false;
                break;
            }
        }
    }
    return res;
}

float& MatrixLr::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false) {
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[rows_[i_row] + cols_[i_col]];
}

float MatrixLr::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false) {
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[rows_[i_row] + cols_[i_col]];
}

MatrixLr& MatrixLr::multiply(MatrixLr rhs) noexcept(false) {
    if(n_col_ != rhs.n_row_) throw std::invalid_argument("Cannot multiply matrices with these parameters");
    MatrixLr res(rhs.colCount(), this->rowCount());
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

MatrixLr& MatrixLr::transpose() noexcept {
    MatrixLr res(n_row_, n_col_);
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            res.at(j, i) = this->at(i, j);
        }
    }
    (*this) = res;
    return (*this);
}

std::ostream& MatrixLr::writeTo(std::ostream &out) const noexcept {
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            out << this->at(i, j);
            if(j != n_col_ - 1) out << " ";
        }
        if(i != n_row_ - 1) out << std::endl;
    }
    return out;
}

void MatrixLr::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_row_ || i_second >= n_row_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    std::swap(rows_[i_first], rows_[i_second]);
}

void MatrixLr::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_col_ || i_second >= n_col_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    std::swap(cols_[i_first], cols_[i_second]);
}

std::ostream &operator<<(std::ostream &out, const MatrixLr &matr) noexcept {
    return matr.writeTo(out);
}

int main() {

  return 0;
}