#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
int check[1000][1000][2];
int map[1000][1000];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    queue<tuple<int, int, int>> q;
    check[0][0][0] = 1;
    q.push(make_tuple(0,0,0));
    while(!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front(); q.pop();
        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] == 0 && check[nx][ny][z] == 0) {
                check[nx][ny][z] = check[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z));
            }
            if (z == 0 && map[nx][ny] == 1 && check[nx][ny][z+1] == 0) {
                check[nx][ny][z+1] = check[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z+1));
            }
        }
    }
    if (check[n-1][m-1][0] != 0 && check[n-1][m-1][1] != 0) {
        cout << min(check[n-1][m-1][0], check[n-1][m-1][1]);
    } else if (check[n-1][m-1][0] != 0) {
        cout << check[n-1][m-1][0];
    } else if (check[n-1][m-1][1] != 0) {
        cout << check[n-1][m-1][1];
    } else {
        cout << -1;
    }
    cout << '\n';
    return 0;
}

