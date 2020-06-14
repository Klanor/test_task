#include "money.h"
#include <iostream>
int main(){

    std::string str;
    std::cout<<"Enter sum (ex. \'100.50\')"<<std::endl;

    std::cin>>str;
    std::cout<<money::getSum(str)<<std::endl;

    return 0;
}