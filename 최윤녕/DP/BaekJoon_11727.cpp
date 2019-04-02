/*
2*n 타일링 (2)
-> 2*1 , 1*2, 2*2가 가능하다. 차례대로 그려보면서 규칙을 찾아보기 
*/
#include <iostream>

using namespace std;
int memo[1001];
int main(){
    int n;
    cin >> n;
    memo[1] = 1;
    memo[2] = 3;
    for(int  i = 3; i <= n; i++){
        memo[i] = 2 * memo[i-2] + memo[i-1];
        memo[i] = memo[i] % 10007;
    }
    cout << memo[n];
    return 0;
}
