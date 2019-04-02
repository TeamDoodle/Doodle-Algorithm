/*
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램
*/
#include <iostream>

using namespace std;
//경우의 수를 구해줄 함수 
int memo[11];

int solve(int n){
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    if(n<=3)
        return memo[n];
    for(int i = 4; i <= n; i++ ){
        memo[i]= memo[i-3] + memo[i-2] + memo[i-1];
    }
    return memo[n];
}
int main(){
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}