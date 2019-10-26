#include <iostream>
#include <string>

class Matrix {
    private: 
        float* data;
    public:
        int height;
        int width;
        Matrix(int height_inp, int width_inp) {
            // constructor 
            height = height_inp;
            width = width_inp;
            int data_size = height * width;
            data = new float[data_size];
        }
        void set_value (int x, int y, float value) {
            data[y * width + x] = value;
        }
        
        Matrix(const Matrix &matrix_old)
        {
            // copy constructor
            height = matrix_old.height;
            width = matrix_old.width;
            for(int offset = 0; offset < matrix_old.height * matrix_old.width; offset ++) {
                data[offset]  = matrix_old.data[offset];
            }
        }
        
        Matrix& operator = (const Matrix &matrix_right) 
        { 
            //Assignment operator
            height = matrix_right.height;
            width = matrix_right.width;
            for(int offset = 0; offset < matrix_right.height * matrix_right.width; offset ++) {
                data[offset]  = matrix_right.data[offset];
            }
            return *this; 
        }  

        void print() {
            int offset = 0;
            for(int row_count = 0; row_count < height; row_count++){
                std::cout << '|';
                for(int column_count = 0; column_count < width; column_count++){
                    std::cout << data[offset];
                    if(column_count < (width - 1)){
                        std::cout << "\t";
                    }
                    offset++;
                }
                std::cout << "|\n";
            }
        }
        
        
        ~Matrix() {
            delete [] data;
        }
        
    
    friend Matrix operator + (Matrix const &matrix_left, Matrix const &matrix_right);
    friend Matrix operator * (float const multiplier, Matrix const &matrix_right);
    friend Matrix operator * (Matrix const &matrix_left, float const multiplier);
};

Matrix operator + (Matrix const &matrix_left, Matrix const &matrix_right) {
    Matrix matrix_result(matrix_left.height, matrix_left.width);
    int offset = 0;
    for(int row_count = 0; row_count < matrix_left.height; row_count++){
        for(int column_count = 0; column_count < matrix_left.width; column_count++){
            matrix_result.data[offset] = matrix_left.data[offset] + matrix_right.data[offset];
            offset++;
        }
    }
    return matrix_result; 
}

Matrix operator * (float const multiplier, Matrix const &matrix_right) {
    Matrix matrix_result(matrix_right.height, matrix_right.width);
    for(int offset = 0; offset < matrix_right.height * matrix_right.width; offset ++) {
        matrix_result.data[offset]  = multiplier * matrix_right.data[offset];
    }
    return matrix_result;
}

Matrix operator * (Matrix const &matrix_left, float const multiplier) {
    Matrix matrix_result(matrix_left.height, matrix_left.width);
    for(int offset = 0; offset < matrix_left.height * matrix_left.width; offset ++) {
        matrix_result.data[offset]  = multiplier * matrix_left.data[offset];
    }
    return matrix_result;
}


int main()
{
  
  Matrix A_matrix(3, 4);
  Matrix B_matrix(3, 4);
  Matrix C_matrix(3, 4);
  
  A_matrix.set_value(1, 2, 1.2f);
  
  B_matrix.set_value(2, 2, 2.2f);
  
  C_matrix = 1.2f * A_matrix + B_matrix * 2.4f;
  
  C_matrix.print();
  return 0;
}
