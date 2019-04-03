/*
#include <iostream>
#include <algorithm>

using namespace std;
int t[1500000];
int p[1500000];

int main(){
    int n;
    cin >> n;
    //입력
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> p[i];
    }
    //최종 결과 값
    int final_max  = 0;
    // i = n일때를 고려해야함.
    for(int i = 1; i <n; i++){    
        //시작값
        int days = i;
        int sum = 0;
        while(days <= n){
            days += t[days];
            if(days >= n) continue;
            sum += p[days];
        }
        if(final_max < sum) final_max= sum;
    }

    cout << final_max;
    return 0;
}

*/

#include <iostream>
#include <algorithm>
using namespace std;

int T[1500002];
int P[1500002];
int dp[1500002];
 
int main(void){
    int n, i;
    cin >> n;
    //입력받기 
    for (i = 1; i <= n; i++){
        cin >> T[i] >> P[i];
    }
    // 뒤에서 부터 차례 대로 top-down방식
    for (i = n; i >= 1; i--){
        // i+T[i] 가 n+1을 넘어가면 그 앞의 값 그대로 -> 그 일은 포함할 수 없음. 
        if (i + T[i] > n + 1){
            dp[i] = dp[i + 1];
        }
        //넘지 않는다면, 
        else{
            dp[i] = max(dp[i+1], P[i]+dp[i+T[i]]);
        }
    }
    cout << dp[1];
    return 0;
}