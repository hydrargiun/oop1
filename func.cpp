#include <iostream>
#include "Matrix.h"


namespace oop1 {
    void Create_Node(struct Node **matrix, float non_zero_element, int row_index, int column_index) {
        struct Node *temp, *rows;
        temp = *matrix;

        if (!temp) {
            try {
                temp = new struct Node;
            }
            catch (std::bad_alloc &ba) {
                std::cout << "Error in allocating memory: " << ba.what() << std::endl;
                return;
            }
            temp->value = non_zero_element;
            temp->row_position = row_index;
            temp->column_position = column_index;
            temp->next = nullptr;
            *matrix = temp;
        }
        else {
            while (temp->next) {
                temp = temp->next;
            }
            try {
                rows = new struct Node;
            }
            catch (std::bad_alloc &ba) {
                std::cout << "Error in allocating memory: " << ba.what() << std::endl;
                return;
            }
            rows->value = non_zero_element;
            rows->row_position = row_index;
            rows->column_position = column_index;
            rows->next = nullptr;
            temp->next = rows;
        }
    }

    struct Node *Create_Matrix(int &rm, int &rn) {
        const char *pr = "";
        struct Node *matrix = nullptr;
        int m, n;
        float item;

        do {
            std::cout << pr;
            std::cout << "Enter the matrix size: ";
            pr = "Invalid input, please try again!\n";
            if (getNum(m) < 0 || getNum(n) < 0) {
                return nullptr;
            }
        } while (m < 1 || n < 1);

        for (int i = 0; i < m; i++) {
            std::cout << "Enter the items for matrix row #" << (i + 1) << ": ";
            for (int j = 0; j < n; j++) {
                if (getNum(item) < 0) {
                    Erase_Matrix(matrix);
                    return nullptr;
                }
                else if (!item) {
                    continue;
                }
                else {
                    Create_Node(&matrix, item, i, j);
                }
            }
        }

        rm = m;
        rn = n;
        return matrix;
    }

    float Retrieve_Coordinates(struct Node *matrix, int row_index, int column_index) {
        struct Node *temp = matrix;

        while (temp) {
            if (temp->row_position == row_index && temp->column_position == column_index) {
                return temp->value;
            }
            temp = temp->next;
        }
        return 0;
    }

    void Print_Matrix(const char *msg, struct Node *matrix, int m, int n) {
        std::cout << msg << std::endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << Retrieve_Coordinates(matrix, i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    void Print_Vector(const char *msg, int vector[], int m) {
        std::cout << msg << std::endl;
        for (int i = 0; i < m; i++) {
            std::cout << vector[i] << " ";
        }
        std::cout << std::endl;
    }

    struct Node *Erase_Matrix(struct Node *matrix) {
        struct Node *temp, *tmp;
        temp = matrix;

        while (temp) {
            tmp = temp;
            temp = temp->next;
            delete tmp;
        }
        return nullptr;
    }

    int *Fix_matrix(struct Node *matrix, int m, int n) {
        struct Node *temp = matrix;
        int *vector = nullptr;

        try {
            vector = new int[m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << ba.what() << std::endl;
            return nullptr;
        }

        for (int i = 0; i < m; i++) {
            temp = matrix;
            float min = 0;
            float max;
            //while (temp) {
               // temp = temp->next;
                 min = Min_for_i(matrix, i);
                 max = Max_for_i(matrix, i);


            //}
             Change_matrix(matrix,i,min,max);


        }
        return vector;
    }



    float Min_for_i(struct Node* matrix, int i){
        struct Node *tmp = matrix;
        float min =1000;
        while (tmp) {
            if (tmp->row_position == i) {
                if (tmp->value < min) {
                    min= tmp->value;
                }
            }
            tmp = tmp->next;
        }
        return min;
    }


    float Max_for_i(struct Node* matrix, int i){
        struct Node *tmp = matrix;
        float max =0;
        while (tmp) {
            if (tmp->row_position == i) {
                if (tmp->value >  max) {
                    max= tmp->value;
                }
            }
            tmp = tmp->next;
        }
        return max;
    }


    void Change_matrix(struct Node* matrix, int i, float min, float max){
        struct Node *tmp = matrix;
        while (tmp) {
            if (tmp->row_position == i) {
                if (tmp->value == max) {
                    tmp->value = min;
                }
                    else if (tmp->value == min) {
                        tmp->value = max;
                }
            }
            tmp = tmp->next;
        }
    }

}


