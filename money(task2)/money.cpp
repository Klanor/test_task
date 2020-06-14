#include <stdexcept>
#include "money.h"

const char *money::one[9]{
        "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "
};

const char *money::teen[10]{
        "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ",
        "nineteen "
};

const char *money::dec[8]{
        "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

const char *money::nm[3]{
        "billion ", "million ", "thousand "
};

std::string money::getSum(std::string str) {
    std::string before_point(str.begin(), str.begin() + str.find('.')),
            after_point(str.begin() + str.find('.') + 1, str.end());

    str.erase();

    while (static_cast<int>(before_point.size()) % 3 != 0) {
        before_point.insert(before_point.begin(), ' ');
    }

    size_t count = 3;
    for (size_t i = before_point.size(); i > 0; i -= 3) {
        if (count < 0) {
            throw std::invalid_argument("Limit is exceeded");
        }
        str.insert(0, parse(std::string(before_point.begin() + i - 3, before_point.begin() + i), count));
        --count;
    }

    if (str == "one ") {
        str += "dollar ";
    } else {
        str += "dollars ";
    }

    if (after_point[0] != '0' || after_point[1] != '0') {
        if (after_point.size() > 2) {
            throw std::invalid_argument("Uncorrect cents");
        }

        while (after_point.size() < 3) {
            after_point.insert(after_point.begin(), ' ');
        }

        str += parse(after_point) + "cents";
    }

    return str;
}

std::string money::parse(const std::string &str, size_t count) {
    std::string res;

    if (str[0] != '0' || str[1] != '0' || str[2] != '0') {
        if (str[0] != ' ' && str[0] != '0') {
            res = one[str[0] - '1'];
            res += "hundred ";
        }
        if (str[1] != '0' && str[1] != ' ') {
            if (str[1] == '1') {
                res += teen[str[2] - '0'];
            } else {
                res += dec[str[1] - '2'];
                if (str[2] != '0') {
                    res += '-';
                } else {
                    res += ' ';
                }
            }
        }
        if (str[2] != '0') {
            res += one[str[2] - '1'];
        }

        if (count <= 2) {
            res += nm[count];
        }
    }

    return res;
}