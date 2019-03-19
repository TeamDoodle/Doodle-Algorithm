#include <iostream>
#include <queue>
using namespace std;
int check[1000][1000];
int tomato[1000][1000];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main(int argc, const char * argv[]) {
    int n, m;
    cin >> m >> n;
    int maxDay = 0;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> tomato[i][j];
            check[i][j] = -1;
            if (tomato[i][j] == 1) {
                q.push(make_pair(i,j));
                check[i][j] = 0;
            }
        }
    }
    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (tomato[nx][ny] == 0 && check[nx][ny] == -1) {
                check[nx][ny] = check[x][y] + 1;
                maxDay = max(maxDay, check[nx][ny]);
                q.push(make_pair(nx,ny));
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (tomato[i][j] == 0 && check[i][j] == -1) {
                maxDay = -1;
            }
        }
    }
    cout << maxDay << '\n';
    return 0;
}
