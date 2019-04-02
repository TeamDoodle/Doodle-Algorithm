#include <iostream>
using namespace std;
int d[11];
int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    int ans[t];
    int maxNum = 0;
    for (int i=0; i<t; i++) {
        cin >> ans[i];
        maxNum = maxNum < ans[i] ? ans[i] : maxNum;
    }
    d[1] = 1; d[2] = 2; d[3] = 4;
    for (int i=4; i<=maxNum; i++)
        d[i] = d[i-1] + d[i-2] + d[i-3];
    for (int i=0; i<t; i++)
        cout << d[ans[i]] <<'\n';
    return 0;
}
