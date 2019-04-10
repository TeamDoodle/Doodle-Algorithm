/*
a, b, c, d에 대한 부분집합을 구하기 - 비트마스크 이용
출력값
a
b
ab
c
ac
bc
abc
d
ad
bd
abd
cd
acd
bcd
abcd
*/
#include <iostream>

using namespace std;

int main(){
    int i, j;
    char arr[4] = {'a' ,'b', 'c', 'd'};
    int n = 4;

    for(i = 0; i < ( 1<< (n)); i++){
        for(j = 0; j < n; j++){
            if( i & ( 1 << j))
                cout << arr[j];
        }
        cout  << "\n";
    }
    

    return 0;
}