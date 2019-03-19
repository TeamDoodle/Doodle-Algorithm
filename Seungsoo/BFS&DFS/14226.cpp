#include <iostream>
#include <queue>
using namespace std;
bool check[2002][2002];
int dist[2002][2002];
int ans = 10000000;
int main() {
    int s;
    cin >> s;
    queue<pair<int, int>> q;
    check[1][0] = true;
    dist[1][0] = 0;
    q.push(make_pair(1, 0));
    while(!q.empty()) {
        int nowX = q.front().first, nowY = q.front().second; q.pop();
        if (!check[nowX][nowX]) {
            check[nowX][nowX] = true;
            dist[nowX][nowX] = dist[nowX][nowY] + 1;
            if (nowX == s) ans = min(ans, dist[nowX][nowX]);
            q.push(make_pair(nowX, nowX));
        }
        if (!check[nowX + nowY][nowY] && (nowX + nowY <= 1000)) {
            check[nowX + nowY][nowY] = true;
            dist[nowX + nowY][nowY] = dist[nowX][nowY] + 1;
            if (nowX + nowY == s) ans = min(ans, dist[nowX + nowY][nowY]);
            q.push(make_pair(nowX + nowY, nowY));
        }
        if (!check[nowX - 1][nowY] && (nowX - 1 > 0)) {
            check[nowX - 1][nowY] = true;
            dist[nowX - 1][nowY] = dist[nowX][nowY] + 1;
            if (nowX - 1 == s) ans = min(ans, dist[nowX - 1][nowY]);
            q.push(make_pair(nowX - 1, nowY));
        }
    }
    cout << ans << '\n';
    return 0;
}
