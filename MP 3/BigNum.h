#include<string>

class BigNum {
    private:
        std::string num;
        bool isItValid(const std::string &str);
    public:
        BigNum();
        BigNum(std::string str);
        std::string getNum();
        BigNum add(BigNum &other) const;
};

BigNum fibonacci(unsigned int n);