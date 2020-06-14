#ifndef TEST_TASK_MATRIX_H
#define TEST_TASK_MATRIX_H

#include <vector>
#include <iostream>

class matrix{

    std::vector<std::vector<std::pair<int, bool>*>> _matrix;
    size_t frame_width, frame_height, pic_width = 0, pic_height = 0, pic_x = 0, pic_y = 0;

public:

    matrix(size_t _frame_width, size_t _frame_height, size_t max_value = 50);

    void setUsefulRange(size_t _pic_width, size_t _pic_height, size_t _pic_x, size_t _pic_y);

    void moveUsefulRange();

    void printMatrix();

    ~matrix();
};

#endif //TEST_TASK_MATRIX_H
