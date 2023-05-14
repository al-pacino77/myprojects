#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<double>> data;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, vector<double>(cols, 0.0));
    }

    void set(int i, int j, double value) {
        data[i][j] = value;
    }

    double get(int i, int j) const {
        return data[i][j];
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.set(j, i, data[i][j]);
            }
        }

        return result;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must have same dimensions for addition");
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.set(i, j, data[i][j] + other.data[i][j]);
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Number of columns in first matrix must match number of rows in second matrix for multiplication");
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                double sum = 0.0;
                for (int k = 0; k < cols; k++) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.set(i, j, sum);
            }
        }

        return result;
    }

    void print() const {
        cout << "[";
        for (int i = 0; i < rows; i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << "[";
            for (int j = 0; j < cols; j++) {
                cout << data[i][j];
                if (j < cols - 1) {
                    cout << ", ";
                }
            }
            cout << "]";
            if (i < rows - 1) {
                cout << endl;
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    int rows1, cols1, rows2, cols2;
    cout << "Enter dimensions of first matrix: ";
    cin >> rows1 >> cols1;
    Matrix matrix1(rows1, cols1);

    cout << "Enter dimensions of second matrix: ";
    cin >> rows2 >> cols2;
    Matrix matrix2(rows2, cols2);

    while (true) {
        cout << "Main Menu" << endl;
        cout << "1. Fill matrix" << endl;
        cout << "2. Operate on matrices" << endl;
        cout << "3. Exit program" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter matrix number (1 or 2): ";
            int matrixNum;
            cin >> matrixNum;

            Matrix& matrix = (matrixNum == 1 ? matrix1 : matrix2);

            cout << "Enter matrix values:" << endl;
            for (int i = 0; i < matrix.getRows(); i++) {
                for (int j = 0; j < matrix.getCols(); j++) {
                    double value;
                    cin >> value;
                    matrix.set(i, j, value);
                }
            }
        }
        else if (choice == 2) {
            cout << "Enter operation:" << endl;
            cout << "1. Transpose" << endl;
            cout << "2. Print matrix" << endl;
            cout << "3. Addition" << endl;
            cout << "4. Multiplication" << endl;

            int operation;
            cin >> operation;

            Matrix result;
            try {
                switch (operation) {
                case 1:
                    cout << "Enter matrix number (1 or 2): ";
                    int matrixNum;
                    cin >> matrixNum;

                    result = (matrixNum == 1 ? matrix1 : matrix2).transpose();
                    result.print();
                    break;
                case 2:
                    cout << "Enter matrix number (1 or 2): ";
                    cin >> matrixNum;

                    (matrixNum == 1 ? matrix1 : matrix2).print();
                    break;
                case 3:
                    result = matrix1 + matrix2;
                    result.print();
                    break;
                case 4:
                    result = matrix1 * matrix2;
                    result.print();
                    break;
                default:
                    cout << "Invalid operation" << endl;
                    break;
                }
            }
            catch (const invalid_argument& e) {
                cerr << e.what() << endl;
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}