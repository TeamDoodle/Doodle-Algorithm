/*
연산자 끼워넣기
*/


#include <iostream>
#include <algorithm>

using namespace std;

int n;
int f_max = -1000000005;
int f_min = 1000000005;
int num[11];
int op[4];

void dfs(int id , int result){
    if(id==n){
        f_max = max(f_max, result);
        f_min = min(f_min, result);
    }
    // +, -, *, / 차례대로 계산
    if(op[0] > 0){
        op[0]--;
        dfs(id+1, result + num[id]);
        op[0]++;
    }
    if(op[1] > 0){
        op[1]--;
        dfs(id+1, result - num[id]);
        op[1]++;
    }
    if(op[2] > 0){
        op[2]--;
        dfs(id+1, result * num[id]);
        op[2]++;
    }
    if(op[3] > 0){
        op[3]--;
        dfs(id+1, result / num[id]);
        op[3]++;
    }
}
int main(){
    cin >> n;
    for(int i =0 ; i <n; i++)
        cin >> num[i];
    for(int i =0; i <4; i++)
        cin >> op[i];
    
    dfs(1, num[0]);
    cout << f_max << '\n';
    cout << f_min << '\n';
    return 0;
}