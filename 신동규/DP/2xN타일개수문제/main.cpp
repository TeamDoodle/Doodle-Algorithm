//
//  main.cpp
//  2xntiling
//
//  Created by 신동규 on 4/2/19.
//  Copyright © 2019 AlgoStudy. All rights reserved.
//

#include <iostream>
using namespace std;
int tileCount[1001];
int tiling(int a)
{
    tileCount[0] = 1;
    tileCount[1] = 1;
    
    for (int i = 2; i<=a; i++) {
        tileCount[i] = tileCount[i-1] + tileCount[i-2];
        tileCount[i] %= 10007;
    }
    return tileCount[a];
    

}


int main(int argc, const char * argv[]) {

    int n;
    cin >> n;
    cout << tiling(n)%10007;
    return 0;
}
