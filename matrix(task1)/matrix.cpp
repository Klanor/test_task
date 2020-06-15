#include <cstdlib>
#include "matrix.h"

matrix::matrix(size_t _frame_width, size_t _frame_height, size_t max_value) {

    frame_width = _frame_width;
    frame_height = _frame_height;

    _matrix.resize(frame_height);
    for(auto &i: _matrix){
        i.resize(frame_width);

        for (auto &j: i){
           j = new std::pair<int, bool>(std::rand() % max_value, false);
        }
    }
}

void matrix::printMatrix() {
    for(const auto &i:_matrix){
        for(const auto &j:i){
            if(j != nullptr){
                if(j->first < 10){
                    if(j->second){
                        std::cout<<" $"<<j->first<<" ";
                    }else{

                        std::cout<<"  "<<j->first<<" ";
                    }
                }else{
                    if(j->second){
                        std::cout<<"$"<<j->first<<" ";
                    }else{

                        std::cout<<" "<<j->first<<" ";
                    }
                }
            }else{
                std::cout<<"  0 ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void matrix::setUsefulRange(size_t _pic_width, size_t _pic_height, size_t _pic_x, size_t _pic_y) {
    pic_width = _pic_width;
    pic_height = _pic_height;
    pic_x = _pic_x;
    pic_y = _pic_y;

    if((pic_x + pic_width > frame_width) || (pic_y + pic_height > frame_height)){
        throw std::invalid_argument("Uncorrect argument value");
    }

    for(size_t y = 0; y < pic_height; ++y){
        for(size_t x = 0; x < pic_width; ++x){
            _matrix.at(y+pic_y).at(x+pic_x)->second = true;
        }
    }
}

void matrix::moveUsefulRange() {

    for(size_t y = 0; y < pic_height; ++y){
        for(size_t x = 0; x < pic_width; ++x){
            delete _matrix.at(y).at(x);
            _matrix.at(y).at(x) = _matrix.at(y+pic_y).at(x+pic_x);
            _matrix.at(y+pic_y).at(x+pic_x) = nullptr;
        }
    }
}

matrix::~matrix() {
    for(auto &i:_matrix){
        for(auto &j : i){
            delete j;
        }
    }
}

