#include <iostream>
#define ll long long
using namespace std;
ll d[31][31];
ll pill(int w, int h) {
    if (w == 0) return 1;
    if (d[w][h] > 0) return d[w][h];
    if (w > 0 && h == 0) d[w][h] = pill(w - 1, h + 1);
    else d[w][h] = pill(w - 1, h + 1) + pill(w, h - 1);
    return d[w][h];
}
int main() {
    int n;
    while (cin >> n){
        if (n == 0) break;
        else
            cout << pill(n, 0) << endl;
    }
    return 0;
}
