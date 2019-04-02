/*
1로 만들기 위해 필요한 연산의 최소의 횟수
*/
#include <iostream>
#include <algorithm>

using namespace std;
//memo 방법을 사용
int dp[1000000];

int main(){
    int n;
    cin >> n;
    
    dp[1] = 0;
    for(int i = 2; i <=n; i++){
        // 1을 빼준것...
        dp[i] = dp[i-1] + 1;
        // 조건이 하나 더 추가 되어야 한다. why? 최소 횟수를 출력해야하니까
        if(i%2==0 && dp[i] > (dp[i/2]+1))
            dp[i] = dp[i/2] + 1;
        if(i%3==0 && dp[i] > (dp[i/3]+1))
            dp[i] = dp[i/3] + 1;
    }

    cout << dp[n];
    

    return 0;
}