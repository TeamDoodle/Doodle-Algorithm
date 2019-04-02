/*
2*n 타일을 채우는 방법의 수를 10,007로 나눈 나머지를 출력 -> 경우의 수는 대부분 dp문제 
*/
#include <iostream>

using namespace std;

int memo[1001];

int main(){
    int n;
    cin >> n;
    memo[1] = 1;
    memo[2] = 2;
    for(int i = 3; i <= n; i++){
        memo[i] = memo[i-1] + memo[i-2];
        // 답이 왜 차이가 나는지
        memo[i] = memo[i] % 10007;
    }
    // 10007로 나눈 나머지
    cout << memo[n];

    return 0;
}