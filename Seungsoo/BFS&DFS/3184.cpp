#include <queue>
#include <iostream>
#include <tuple>
#include <cstdio>
using namespace std;
char map[251][251];
int check[251][251];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    int o = 0, v = 0;
    int r, c;
    queue<tuple<int, int>> q;
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> map[i][j];
        }
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            int currentO = 0, currentV = 0;
            bool isOpen = 0;
            if (map[i][j] == '#' || check[i][j] == 1) continue;
            check[i][j] = 1;
            if (map[i][j] == 'o') {
                currentO += 1;
            } else if (map[i][j] == 'v') {
                currentV += 1;
            }
            q.push(make_tuple(i,j));
            while (!q.empty()) {
                int x, y;
                tie(x, y) = q.front(); q.pop();
                for(int k=0; k<4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (map[nx][ny] == '#') continue;
                    if ((nx == 0 || nx == r || ny == 0 || ny == c) && check[nx][ny]) isOpen = 1;
                    if (map[nx][ny] == 'o' && check[nx][ny] == 0) {
                        currentO += 1;
                        check[nx][ny] = 1;
                        q.push(make_tuple(nx, ny));
                    }
                    if (map[nx][ny] == 'v' && check[nx][ny] == 0) {
                        currentV += 1;
                        check[nx][ny] = 1;
                        q.push(make_tuple(nx, ny));
                    }
                    if (check[nx][ny] == 0) {
                        check[nx][ny] = 1;
                        q.push(make_tuple(nx, ny));
                    }
                }
            }
            if (isOpen == 0) {
                if (currentO > currentV) o += currentO;
                else v += currentV;
            }
        }
    }
    cout << o << " " << v << '\n';
    return 0;
}
