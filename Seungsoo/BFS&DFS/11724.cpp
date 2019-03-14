#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check[1001];
vector<int> a[1001];
void dfs(int x){
    check[x] = true;
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(check[y] == false) {
            dfs(y);
        }
    }
}
int main() {
    int n, m, components = 0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        if(check[i] == false) {
            dfs(i);
            components += 1;
        }

    }
    cout << components << '\n';
    return 0;
}
