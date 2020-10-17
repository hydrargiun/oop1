#include <iostream>
#include "Matrix.h"
using namespace oop1;

int main() {
    struct Node *arr = nullptr;
    int *res = nullptr;
    int m, n;

    arr = Create_Matrix(m, n);
    if (!arr) {
        std::cout << "Incorrect data detected!" << std::endl;
        return 1;
    }
    Print_Matrix("Sourced matrix:", arr, m, n);

     res = Fix_matrix(arr, m, n);
    // std::cout << m <<std::endl;
    if (!res) {
        std::cout << "Error in allocating memory!" << std::endl;
        return 1;
    }
    Print_Matrix("Changed matrix:", arr, m, n);

    Erase_Matrix(arr);
    delete[] res;
    return 0;
}
