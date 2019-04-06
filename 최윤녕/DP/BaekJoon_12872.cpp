// 플레이리스트 
#include <iostream>
#include <cstring>

using namespace std;
// d[p][x] -> x는 이미 선택한 그룹 
long long d[101][101];
long long mod = 1000000007;
int n, m, p;
//n개 중 p개를 고를 함수
long long go(int final, int x){
    //y는 아직 추가되지 않은 노래의 그룹
    int y = n - x;
    if(final==p){
        // y 안에 음악들이 다 들어갔다면, 
        if(y==0) return 1; else return 0;
    }
    long long &ans = d[final][x];
    
    if(ans != -1) return ans;

    ans = 0;
    // 2가지 경우를 나누어 생각
    // 1. 새로 선택할 때
    if(y > 0){
        ans += go(final+1, x+1) * y;
    }
    //2.이미 추가된 노래를 또 추가하고자 할 때
    if(x > m){
        ans += go(final+1, x) * (x-m);
    }
    ans %= mod;
    return ans;
}
int main(){
    cin >> n >> m >> p;

    memset(d, -1, sizeof(d));
    cout << go(0,0) << '\n';
    return 0;
}