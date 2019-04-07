/*
연구소 문제 := 얻을 수 있는 안전영역의 최대크기 출력 
*/

#include <iostream>
#include <queue>
using namespace std;
int n, m;
int a[10][10];
//새로 옮겨서 계산
int b[10][10];
// 네가지 방향으로 탐색
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int bfs() {
    queue<pair<int, int>> q;
    // b배열로 옮겨준다.
    for(int i = 0; i <n; i++){
        for(int j=0; j <m; j++){
            // 바이러스면 큐에 넣어준다.
            b[i][j] = a[i][j];
            if(b[i][j]==2) q.push(make_pair(i, j));
        }
    }
    
    //바이러스 퍼뜨리기
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //상, 하, 좌, 우로 
        for(int d = 0; d <4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && ny >=0 && nx <n && ny <m){
                if(b[nx][ny]==0){
                    b[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    //감염되지 않은 안전영역 계산 0 인 부분을 count
    int cnt = 0;
    for(int i = 0; i <n; i++){
        for(int j=0; j <m; j++){
            if(b[i][j]==0) cnt += 1;
        }
    }
    return cnt;
}
int main() {
    cin >> n >> m;
    //입력
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    //최종 값
    int ans = 0;

    // 벽 3개를 모든경우를 따져서 설치
    for(int x1 = 0; x1 <n; x1++){
        for(int y1 =0; y1 <m; y1++){
            // 1번 벽
            if(a[x1][y1]!=0) continue;
            // 2번 벽
            for(int x2 = 0; x2 < n; x2++){
                for(int y2 =0; y2 <m; y2++){
                    if(a[x2][y2]!=0) continue;
                    //3번 벽
                    for(int x3 =0; x3 <n; x3++){
                        for(int y3 = 0; y3 <m; y3++){
                            if(a[x3][y3]!=0) continue;

                            // 1, 2, 3번 벽이 모두 같으면 안됌
                            if(x1==x2 && y1 == y2) continue;
                            if(x1==x3 && y1 == y3) continue;
                            if(x2==x3 && y2 == y3) continue;
                            
                            //벽을 세운다.
                            a[x1][y1] = 1;
                            a[x2][y2] = 1;
                            a[x3][y3] = 1;

                            // 바이러스 퍼뜨린다.
                            int cur = bfs();

                            if(ans < cur) ans = cur;
                            // 다시 원래 빈칸으로 바꿔준다.
                            a[x1][y1] = 0;
                            a[x2][y2] = 0;
                            a[x3][y3] = 0;
                        }
                    }

                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}