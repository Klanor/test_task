#ifndef TEST_TASK_MONEY_H
#define TEST_TASK_MONEY_H

#include <string>

class money {
    static const char *one[];
    static const char *teen[];
    static const char *dec[];
    static const char *nm[];

    static std::string parse(const std::string &str, size_t count = 10);

public:
    static std::string getSum(std::string str);
};

#endif //TEST_TASK_MONEY_H
