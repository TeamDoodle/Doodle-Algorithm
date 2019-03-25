#include <iostream>
#include <tuple>
#include <queue>
#include <string>
#include <set>
#define max 1000000001
typedef long long ll;
using namespace std;
set<ll> check;
int main(int argc, const char * argv[]) {
    ll s, t;
    cin >> s >> t;
    queue<tuple<ll, string>> q;
    check.insert(s);
    q.push(make_tuple(s, ""));
    if (s == t) {
        cout << "0\n";
        return 0;
    }
    while(!q.empty()) {
        ll nowS; string nowStr;
        tie(nowS, nowStr) = q.front(); q.pop();
        if (nowS == t) {
            cout << nowStr << '\n';
            return 0;
        }
        if ((check.find(nowS * nowS) == check.end()) && nowS * nowS < max) {
            check.insert(nowS * nowS);
            q.push(make_tuple(nowS * nowS, nowStr + "*"));
        }
        if ((check.find(nowS + nowS) == check.end()) && nowS + nowS < max) {
            check.insert(nowS + nowS);
            q.push(make_tuple(nowS + nowS, nowStr + "+"));
        }
        if ((check.find(nowS - nowS) == check.end()) && nowS - nowS > 0) {
            check.insert(nowS - nowS);
            q.push(make_tuple(nowS - nowS, nowStr + "-"));
        }
        if ((check.find(nowS / nowS) == check.end()) && nowS != 0) {
            check.insert(nowS / nowS);
            q.push(make_tuple(nowS / nowS, nowStr + "/"));
        }
    }
    cout << "-1\n";
    return 0;
}
