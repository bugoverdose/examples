#include <iostream>
#include <windows.h>

using namespace std;
typedef unsigned long long uint64

int buffer[10000][10000];

int main()
{
    memset(buffer, 0, sizeof(buffer));
    { // (1) 특정 배열 내 전체 순회하는 작업을 10000번 반복
        uint64 start = GetTickCount64();

        int sum = 0;
        for (int i = 0; i < 10000; i++)
            for (int j = 0; j < 10000; j++)
                sum += buffer[i][j];

        uint64 end = GetTickCount64();
        cout << "Elapsed Tick " << (end - start) << endl; // 109
    }
    { // (2) index별로 각 배열들 순회
        uint64 start = GetTickCount64();

        int sum = 0;
        for (int i = 0; i < 10000; i++)
            for (int j = 0; j < 10000; j++)
                sum += buffer[j][i];

        uint64 end = GetTickCount64();
        cout << "Elapsed Tick " << (end - start) << endl; // 313
    }
    // Q. 이차원 배열을 전체 순회는 두 가지 방법 중 (1)이 왜 (2)보다 3배나 더 빠른가?
    // A. RAM에서 특정 데이터가 필요할 때, 해당 데이터 하나만 가져오는게 아니라 인접된 블록 단위로 조회하여 캐쉬에 저장함!
    // (1)은 이차원 배열 [][][][], [][][][], [][][][], [][][][]을 쭉 순회함
    // buffer[0][0] 조회 후 buffer[0][1]을 조회할 때 이미 캐쉬에 존재할 확률이 높음! => Cache Hit!
    // (2)은 buffer[0][0] 조회 후 인접하지 않은 buffer[1][0]을 조회! => Cache Miss!
}
