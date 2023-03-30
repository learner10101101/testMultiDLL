#include <iostream>
#include "addDLL.h"
#include "minusDLL.h"

int main()
{
    int addResult = add(2,3);
    int minusResult = minus(5,2);
    float minusResult2 = minus(5.5f, 2.2f);
    std::cout << "Hello World" << std::endl;
    std::cout << "add(2,3) == " << addResult << std::endl;
    std::cout << "minus(5,2) == " << minusResult << std::endl;
    std::cout << "minus(5.5f, 2.2f) " << minusResult2 << std::endl;
    return 0;
}