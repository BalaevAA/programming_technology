
#include<iostream>
#include<vector>



class JaggedArray {
public:
    JaggedArray() = default;
    //void pushArrayD(int* a);
    int** InitArray2D(int row);
    int* get_col();
    int get_row();
    void print(int** a);
private:
    int** jag;
    int n_col = 0;
    int n_row = 0;
    int* pRow;
};

int** JaggedArray::InitArray2D(int row) {
    n_row = row;
    pRow = new int[n_row];
    jag = new int*[n_row];
    for(int i = 0; i < row; ++i) {
        std::cout << "which size of " << i << " row : \n";
        int temp_size = 0;
        std::cin >> temp_size;
        pRow[i] = temp_size;
        jag[i] = new int[pRow[i]];
    }
    return jag;
}


void JaggedArray::print(int** a) {
    for(int i = 0; i < n_row; ++i) {
        for(int j = 0; j < pRow[i]; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int* JaggedArray::get_col() {
    return pRow;
}

int JaggedArray::get_row() {
    return n_row;
}


int main() {
    int** b;
    int* s;
    JaggedArray a;
    b = a.InitArray2D(3);
    s = a.get_col();
    int row = a.get_row();
    for(int i = 0; i < a.get_row(); ++i) {
        for(int j = 0; j < s[i]; ++j) {
            std::cin >> b[i][j];
        }
    }
    a.print(b);

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < s[i]; ++j) {
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
