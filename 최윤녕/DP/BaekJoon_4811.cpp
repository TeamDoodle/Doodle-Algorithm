#include <iostream>
#include <cstring>

using namespace std;

long long dp[31][31];
// w : 알약 1개 , h : 알약 반개 
long long solution(int w, int h){
    //계산되있다면 그값을 출력
    if(dp[w][h] != -1) return dp[w][h];
    //알약이 한개만 들어있다면
    if(w==0)  return 1;
    //알약이 반개만 있다면
    if(h==0) return dp[w][h] = solution(w-1, h+1);
    //둘다 존재한다면, 나올 수 있는 두가지 경우의 수를 더해줌
    // 1. 한 조각을 꺼냈을 때 + 2. 반조각을 꺼냈을 때
    return dp[w][h] = solution(w-1, h+1) + solution(w, h-1);
}
int main(){
    memset(dp, -1, sizeof(dp));
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        // 알약이 n개 , 초기에는 아직 쪼갠 것이 없음. 
        cout << solution(n, 0) << '\n';
    }


    return 0;
}