/*
14395 : 4연산
s = t -> 0
바꿀 수 없는 경우 -> -1출력
output :  최소 연산의 횟수
*/
#include <iostream>
#include <tuple>
#include <queue>
#include <string>
#include <set>
using namespace std;
const long long limit = 1000000000LL;
int main() {
    //s를 t로 
    long long s, t;
    cin >> s >> t;
    //set은 중복을 허용하지 않음 
    set<long long> check;
    //queue에는 숫자와 연산을 넣을 것. 
    queue<pair<long long,string>> q;
    //q에 s와 ""를 넣는다. 초기에는 어떤 연산도 진행되지 않았으므로 ""을 추가 
    q.push(make_pair(s,""));
    check.insert(s);
    while (!q.empty()) {
        long long x;
        //가능한 연산을 저장할 변수 
        string str;
        tie(x, str) = q.front(); q.pop();
        //x 가 t이면
        if (x == t) {
            if (str.length() == 0) {
                str = "0";
            }
            cout << str << '\n';
            return 0;
        }
        //x가 t가 아니라면 *, +, -, / 를 차례대로 계산 
        if (0 <= x*x && x*x <= limit && check.count(x*x) == 0) {
            q.push(make_pair(x*x, str+"*"));
            check.insert(x*x);
        }
        if (0 <= x+x && x+x <= limit && check.count(x+x) == 0) {
            q.push(make_pair(x+x, str+"+"));
            check.insert(x+x);
        }
        if (0 <= x-x && x-x <= limit && check.count(x-x) == 0) {
            q.push(make_pair(x-x, str+"-"));
            check.insert(x-x);
        }
        if (x != 0 && 0 <= x/x && x/x <= limit && check.count(x/x) == 0) {
            q.push(make_pair(x/x, str+"/"));
            check.insert(x/x);
        }
    }
    //어느연산으로도 s -> t가 안된다면, -1을 반환 
    cout << -1 << '\n';
    return 0;
}
