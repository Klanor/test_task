#include "matrix.h"
#include <iostream>

int main(){

    size_t val1 , val2, val3, val4;

    std::cout<<"Enter frame_width and frame_height(ex. \'20 12\')"<<std::endl;
    std::cin>>val1>>val2;
    matrix matrix(val1, val2);

    std::cout<<"Enter pic_width, pic_height, pic_x, pic_y (ex. \'8 10 3 1\')"<<std::endl;
    std::cin>>val1>>val2>>val3>>val4;

    std::cout<<"Matrix before moving"<<std::endl;
    matrix.setUsefulRange(val1, val2, val3, val4);
    matrix.printMatrix();

    std::cout<<std::endl<<"Matrix after moving"<<std::endl;
    matrix.moveUsefulRange();
    matrix.printMatrix();

    return 0;
}

