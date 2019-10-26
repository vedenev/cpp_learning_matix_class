#include <iostream>
#include <string>

class Matrix {
    private: 
        float* data;
    public:
        int height;
        int width;
        Matrix(int height_inp, int width_inp) {
            height = height_inp;
            width = width_inp;
            int data_size = height * width;
            data = new float[data_size];
        }
        void set_value (int x, int y, float value) {
            data[y * width + x] = value;
        }
    Matrix operator + (const Matrix &matrix_right) {
        Matrix matrix_result(height, width);
        int offset = 0;
        for(int row_count = 0; row_count < height; row_count++){
            for(int column_count = 0; column_count < width; column_count++){
                matrix_result.data[offset] = data[offset] + matrix_right.data[offset];
                offset++;
            }
        }
        return matrix_result; 
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
};


int main()
{
  
  Matrix A_matrix(3, 4);
  Matrix B_matrix(3, 4);
  Matrix C_matrix(3, 4);
  
  A_matrix.set_value(1, 2, 1.2f);
  B_matrix.set_value(2, 2, 2.2f);
  
  C_matrix = A_matrix + B_matrix;
  
  C_matrix.print();
  
}