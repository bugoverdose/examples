#include <iostream>

void Func(const int constVal, int val) {
    // constVal+=10; // [컴파일 에러]
    val += 1;
}
