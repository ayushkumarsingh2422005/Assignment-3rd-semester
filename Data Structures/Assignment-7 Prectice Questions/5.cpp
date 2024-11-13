#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row, col, val;
};

vector<Element> multiplySparseMatrices(const vector<Element>& A, const vector<Element>& B, int rowsA, int colsA, int colsB) {
    vector<Element> result;
    for (const auto& a : A) {
        for (const auto& b : B) {
            if (a.col == b.row) {
                int resRow = a.row, resCol = b.col, resVal = a.val * b.val;
                bool found = false;
                for (auto& res : result) {
                    if (res.row == resRow && res.col == resCol) {
                        res.val += resVal;
                        found = true;
                        break;
                    }
                }
                if (!found) result.push_back({resRow, resCol, resVal});
            }
        }
    }
    return result;
}

void displaySparseMatrix(const vector<Element>& matrix, int rows, int cols) {
    int pos = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pos < matrix.size() && matrix[pos].row == i && matrix[pos].col == j)
                cout << matrix[pos++].val << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int rowsA, colsA, termsA, rowsB, colsB, termsB;
    cout << "Enter rows, columns, and non-zero terms of matrix A: ";
    cin >> rowsA >> colsA >> termsA;
    vector<Element> A(termsA);
    cout << "Enter non-zero elements (row col value):\n";
    for (auto& elem : A) cin >> elem.row >> elem.col >> elem.val;

    cout << "Enter rows, columns, and non-zero terms of matrix B: ";
    cin >> rowsB >> colsB >> termsB;
    vector<Element> B(termsB);
    cout << "Enter non-zero elements (row col value):\n";
    for (auto& elem : B) cin >> elem.row >> elem.col >> elem.val;

    if (colsA != rowsB) {
        cout << "Matrix multiplication not possible.\n";
        return 0;
    }

    vector<Element> result = multiplySparseMatrices(A, B, rowsA, colsA, colsB);
    cout << "Resultant Matrix:\n";
    displaySparseMatrix(result, rowsA, colsB);

    return 0;
}
