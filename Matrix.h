#ifndef OOP1_MATRIX_H
#define OOP1_MATRIX_H
#endif //OOP1_MATRIX_H
namespace oop1{
    struct Node {
        float value;
        int row_position;
        int column_position;
        struct Node *next;
    };
    template <class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good()) {
            return -1;
        }
        return 1;
    }

    void Create_Node(struct Node **, int, int, int);
    struct Node *Create_Matrix(int &, int &);
    float Retrieve_Coordinates(struct Node *, int, int);
    void Print_Matrix(const char *, struct Node *, int, int);
    void Print_Vector(const char *, int [], int);
    struct Node *Erase_Matrix(struct Node *);
    int *Fix_matrix(struct Node *, int, int);
    float Min_for_i(struct Node *tmp, int i);
    float Max_for_i(struct Node *tmp, int i);
    void Change_matrix(struct Node *tmp,int i, float min, float max);



}