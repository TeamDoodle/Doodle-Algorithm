//
//  main.cpp
//  makeToOne
//
//  Created by 신동규 on 4/2/19.
//  Copyright © 2019 AlgoStudy. All rights reserved.
//

#include <iostream>

using namespace std;
int d[1000000];

int cal(int n) {
    if (n == 1) {
        return 0;
    }
    
    if (d[n] > 0) {
        return d[n];
    }
    
    d[n] = cal(n-1) + 1;
    
    if (n%2 == 0) {
        int next = cal(n/2) + 1;
        if (d[n] > next) d[n] = next;
    }
    if (n%3 == 0) {
        int next = cal(n/3) + 1;
        if (d[n] > next) d[n] = next;
    }
    return d[n];
}

int main(int argc, const char * argv[]) {
   
    int a = 0;
    cin >> a;
    cout << cal(a);
    
    return 0;
}
