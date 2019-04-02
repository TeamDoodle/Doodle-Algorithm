#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int R, C, ex, ey, ans;
char a[1500][1500];
bool wc[1500][1500], sc[1500][1500];
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
queue<pair<int, int>> wq1, wq2, sq1, sq2;

void water() {
    while (!wq1.empty()) {
        int x = wq1.front().first, y = wq1.front().second; wq1.pop();
        a[x][y] = '.';
        for (int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || wc[nx][ny]) continue;
            if (a[nx][ny] == '.') wq1.push(make_pair(nx, ny));
            else wq2.push(make_pair(nx, ny));
            wc[nx][ny] = true;
        }
    }
}

bool swan() {
    while (!sq1.empty()) {
        int x = sq1.front().first, y = sq1.front().second; sq1.pop();
        if (x == ex && y == ey) return true;
        for (int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || sc[nx][ny]) continue;
            if (a[nx][ny] == '.') sq1.push(make_pair(nx, ny));
            else sq2.push(make_pair(nx, ny));
            sc[nx][ny] = true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            scanf(" %1c", &a[i][j]);
            if (a[i][j] == 'L') {
                if (sq1.empty()) {
                    sq1.push(make_pair(i, j));
                    sc[i][j] = true;
                } else ex = i, ey = j;
                a[i][j] = '.';
            }
            if (a[i][j] == '.') {
                wq1.push(make_pair(i, j));
                wc[i][j] = true;
            }
        }
    }
    while (true) {
        water();
        if (swan()) break;
        wq1 = wq2;
        sq1 = sq2;
        wq2 = queue<pair<int, int>>();
        sq2 = queue<pair<int, int>>();
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}


