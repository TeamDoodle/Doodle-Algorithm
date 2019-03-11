//
//  main.cpp
//  algorithm_gear2
//
//  Created by 신동규 on 3/11/19.
//  Copyright © 2019 AlgoStudy. All rights reserved.
//

#include <iostream>
#include "deque"
#include "string"
using namespace std;
int gearCount = 0;
int rotateCount = 0;
deque<int> wholeGear[1001];

void rotateGear(int gearNum, int direction, int bothSide)
{
    int rightPoint = wholeGear[gearNum].at(2);
    int leftPoint = wholeGear[gearNum].at(6);
    
    //시계방향 돌리기
    if (direction == 1) {
        int last = wholeGear[gearNum].at(7);
        wholeGear[gearNum].pop_back();
        wholeGear[gearNum].push_front(last);
    }
    //반시계방향 돌리기
    else {
        int last = wholeGear[gearNum].at(0);
        wholeGear[gearNum].pop_front();
        wholeGear[gearNum].push_back(last);
    }
    //오른쪽 기어
    if (bothSide == 1 || bothSide == 0) {
        
        if (gearNum != gearCount) {
            int nextGearLeftPoint = wholeGear[gearNum+1].at(6);
            
            if (rightPoint + nextGearLeftPoint == 1) {
                rotateGear(gearNum + 1, - direction, 1);
            }
        }
    }
    //왼쪽 기어
    if (bothSide == -1 || bothSide == 0) {
        
        if (gearNum != 1) {
            int nextGearRightPoint = wholeGear[gearNum-1].at(2);
            
            if (leftPoint + nextGearRightPoint == 1) {
                rotateGear(gearNum - 1, - direction, -1);
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int result = 0;
    cin >> gearCount;
    
    //deque에  string 값의 하나하나의 char 를 int 형으로 치환해서 push
    for (int i = 1; i <= gearCount; i++) {
        string gear;
        cin >> gear;
        
        for (int j = 0; j < gear.size(); j++ ) {
            wholeGear[i].push_back(gear.at(j)-'0');
        }
    }
    
    cin >> rotateCount;
    
    // 몇번째 기어를 어느방향으로 돌릴껀지 rotateGear함수 실행
    for (int i = 0; i < rotateCount; i++) {
        int gearNum = 0;
        int direction = 0;
        cin >> gearNum >> direction;
        rotateGear(gearNum, direction,0);
    }
    
    // 기어 돌리기가 끝난후 0번째 인덱스에 있는 값이 1인 수를 확인해서 출력
    for (int i = 1; i <= gearCount; i++) {
        
        if (wholeGear[i].at(0) == 1) {
            result++;
        }
    }
    
    cout << result << endl;
    
    return 0;

}
