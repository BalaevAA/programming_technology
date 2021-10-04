#include <iosfwd>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class MatrixDs {
public:
    MatrixDs() = default;
    MatrixDs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false);
    MatrixDs(const MatrixDs&) = default;
    ~MatrixDs() = default;
    MatrixDs& operator=(const MatrixDs& rhs) = default;

    bool operator==(const MatrixDs& rhs) const noexcept;
    MatrixDs& multiply(MatrixDs rhs) noexcept(false);
    size_t rowCount() const noexcept { return n_row_;  }
    size_t colCount() const noexcept { return n_col_;  }
    float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false);
    float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false);
    MatrixDs& transpose() noexcept;
    void swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
    void swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
    std::ostream& writeTo(std::ostream& out) const noexcept;
private:
    std::ptrdiff_t n_row_{0};
    std::ptrdiff_t n_col_{0};
    std::vector<std::vector<float>> data_;
};


std::ostream& operator<<(std::ostream& out, const MatrixDs& matr) noexcept;


MatrixDs::MatrixDs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false){
    if (row_count < 0 || col_count < 0) throw std::out_of_range("Index of element was out of range!");
    if((col_count != row_count)&&(col_count == 0 || row_count == 0)) throw std::invalid_argument("columns or rows were equal to zero");
    n_row_ = row_count;
    n_col_ = col_count;
    data_.resize(row_count, std::vector<float>(col_count));
}

bool MatrixDs::operator==(const MatrixDs &rhs) const noexcept {
    return (data_ == rhs.data_ && n_col_ == rhs.n_col_ && n_row_ == rhs.n_row_);
}

MatrixDs& MatrixDs::multiply(MatrixDs rhs) noexcept(false) {
    if(n_col_ != rhs.n_row_) throw std::invalid_argument("Cannot multiply matrices with these parameters");
    MatrixDs res(rhs.colCount(), this->rowCount());
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

float& MatrixDs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false) {
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[i_row][i_col];
}

float MatrixDs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false) {
    if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
    return data_[i_row][i_col];
}

MatrixDs &MatrixDs::transpose() noexcept {
    MatrixDs res(n_row_, n_col_);
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            res.at(j, i) = this->at(i, j);
        }
    }
    (*this) = res;
    return (*this);
}

std::ostream &MatrixDs::writeTo(std::ostream &out) const noexcept {
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            out << data_[i][j];
            if(j != n_col_ - 1) out << " ";
        }
        if(i != n_row_ - 1) out << std::endl;
    }
    return out;
}

void MatrixDs::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_row_ || i_second >= n_row_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    auto it1 = (data_.begin() + i_first);
    auto it2 = (data_.begin() + i_second);
    std::swap(*it1, *it2);
}

void MatrixDs::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_col_ || i_second >= n_col_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    std::vector<float> temp(n_row_);
    for(auto& row : data_){
        std::swap(row[i_first], row[i_second]);
    }
}

std::ostream& operator<<(std::ostream& out, const MatrixDs& matr) noexcept{
    matr.writeTo(out);
    return out;
}

int main() {

    return 0;
}