#include <iosfwd>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class MatrixVs {
public:
	MatrixVs() = default;
	MatrixVs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false);
	MatrixVs(const MatrixVs&) = default;
	~MatrixVs() = default;
	MatrixVs& operator=(const MatrixVs& rhs) = default;

	bool operator==(const MatrixVs& rhs) const noexcept;
	MatrixVs& multiply(const MatrixVs& rhs) noexcept(false);
	size_t rowCount() const noexcept { return n_row_;  }
	size_t colCount() const noexcept { return n_col_;  }
	float& at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false);
	float at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false);
	MatrixVs& transpose() noexcept;
    void swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
    void swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false);
	std::ostream& writeTo(std::ostream& out) const noexcept;
private:
	std::ptrdiff_t n_row_{0};
	std::ptrdiff_t n_col_{0};
	std::vector<float> data_;
};


std::ostream& operator<<(std::ostream& out, const MatrixVs& matr) noexcept;


MatrixVs::MatrixVs(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) noexcept(false){
    if(row_count < 0 || col_count < 0) throw std::out_of_range("Index of element was out of range!");
    if((col_count != row_count)&&(col_count == 0 || row_count == 0)) throw std::invalid_argument("columns or rows were equal to zero");
    n_row_ = row_count;
    n_col_ = col_count;
	data_.resize(n_row_ * n_col_);
}

float& MatrixVs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) noexcept(false){
	if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
	return data_[i_row * n_col_ + i_col];
}

float MatrixVs::at(const std::ptrdiff_t i_row, const std::ptrdiff_t i_col) const noexcept(false){
	if (i_row >= n_row_ || i_col >= n_col_ || i_row < 0 || i_col < 0) throw std::out_of_range("Index of element was out of range!");
	return data_[i_row * n_col_ + i_col];
}

std::ostream& MatrixVs::writeTo(std::ostream& out) const noexcept{
	size_t c = 0;
	for (const auto& x : data_) {
		out << x << " ";
		++c;
		if (c % n_col_ == 0 && c != data_.size())
			out << std::endl;
	}
	return out;
}


std::ostream& operator<<(std::ostream& out, const MatrixVs& matr) noexcept{
	return matr.writeTo(out);
}

bool MatrixVs::operator==(const MatrixVs& rhs) const noexcept {
    return (data_ == rhs.data_ && n_col_ == rhs.n_col_ && n_row_ == rhs.n_row_);
}

MatrixVs& MatrixVs::multiply(const MatrixVs& rhs) noexcept(false) {
    if(n_col_ != rhs.n_row_) throw std::invalid_argument("Cannot multiply matrices with these parameters");
    MatrixVs res(rhs.colCount(), this->rowCount());
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

MatrixVs& MatrixVs::transpose() noexcept {
    MatrixVs res(n_row_, n_col_);
    for(std::ptrdiff_t i = 0; i < n_row_; ++i){
        for(std::ptrdiff_t j = 0; j < n_col_; ++j){
            res.at(j, i) = this->at(i, j);
        }
    }
    (*this) = res;
    return (*this);
}

void MatrixVs::swapRows(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_row_ || i_second >= n_row_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    auto it1 = data_.begin() + i_first * n_col_;
    auto it2 = data_.begin() + i_second * n_col_;
    std::swap_ranges(it1, it1 + n_col_, it2);
}

void MatrixVs::swapColumns(const std::ptrdiff_t i_first, const std::ptrdiff_t i_second) noexcept(false) {
    if(i_first >= n_col_ || i_second >= n_col_ || i_first < 0 || i_second < 0) throw std::out_of_range("Index of element was out of range!");
    if(i_first == i_second) return;
    std::vector<float> temp;
    temp.reserve(n_row_);
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


int main(){
  MatrixVs matr(5, 5);
  for(int i = 0; i < 5; ++i){
    for(int j = 0; j < 5; ++j){
      matr.at(i,j) = 10;
    }
  }
  std::cout << matr;
  return 0;
}