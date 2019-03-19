#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;
bool check[MAX];
int dist[MAX];
int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<int> q;
    check[s] = true;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if (x + u <= f && !check[x + u]) {
            q.push(x + u);
            check[x + u] = true;
            dist[x + u] = dist[x] + 1;
        }
        if (x - d > 0 && !check[x - d]) {
            q.push(x - d);
            check[x - d] = true;
            dist[x - d] = dist[x] + 1;
        }
    }
    if (check[g]) cout << dist[g] << '\n';
    else cout << "use the stairs\n";
    return 0;
}
