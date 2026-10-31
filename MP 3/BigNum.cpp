/*
HONOR CODE:

I declare, upon my honor, that I did this machine problem assignment by myself
using references from the lecture notes and MPs.

*/

#include "BigNum.h"
#include <iostream>
#include <algorithm>
bool BigNum::isItValid(const std::string &str) {
    if(str.empty()) {
        return false;
    }
    // i dont know how to check if the string is really in BASE10
    return true;
}
    
BigNum::BigNum(): num("0") {}

BigNum::BigNum(std::string str) {
    // should CHECK WHETHER THAT CERTAIN STRING IS VALID
    // firststartzero
    if(isItValid(str)) {
        if(str[0] == '+') {
            str=str.substr(1);
        }
        num=str;
    }
    else {
        num="0";
    }
}

BigNum BigNum::add(BigNum &other) const {
    std::string str1=this->num;
    std::string str2=other.num;
    std::string res="";
    int k=0,str1_length = 0;
    while(str1[k++] != '\0') {
        str1_length++;
    }
    int l=0,str2_length = 0;
    while(str2[l++] != '\0') { 
        str2_length++;
    }
    
    int i=str1_length-1;
    int j=str2_length-1;
    int carrycarry=0;
    
    while(i>=0 || j>=0 || carrycarry>0) {
        int sum = carrycarry;
        
        if(i>=0) {
            sum += str1[i]-'0';
            i--;
        }
        if(j>=0) {
            sum += str2[j]-'0';
            j--;
        }
        carrycarry=sum/10;
        // conv to string
        res += std::to_string(sum%10);
        
    }
    std::reverse(res.begin(), res.end());
    return BigNum(res);
}

std::string BigNum::getNum() {
    return num;
}

BigNum fibonacci(unsigned int n) {
    BigNum prev("0");
    BigNum curr("1");
    
    if(n==0) return prev;
    if(n==1) return curr;    
    
    for(unsigned int i=2; i<=n; ++i) {
        BigNum next = prev.add(curr);
        prev = curr;
        curr=next;
    }
    return curr;
}