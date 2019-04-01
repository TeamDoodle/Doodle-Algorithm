/*벽부수고 이동하기 
만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 
벽을 한 개 까지 부수고 이동하여도 된다.
*/
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

//입력받을 지도 
int map[1000][1000];
int check[1000][1000];
int main(){
    //  n, m을 입력 받음
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
                int k;
                cin >> k;
                map[i][j] = k;
                // cin >> map[i][j] = k 도 가능한지 확인해보기 
        } 
    }
    //큐 만들기
    //점을 넣어야하니까, make_pair을 이용해야함 
    queue<int> q;
    for(int i = 0; i< n; i++){
        for(int j =0; j <m; j++){
            if(map[i][j]== 0)
                q.push(map[])
        }
    }
    return 0;
}
