# 톱니 바퀴문제 2 - 시뮬레이션문제

문제 후 판단:  이문제는 큐에 대한 지식, 재귀함수에 대한 지식이 있어야 풀수있는 문제 ! 또한 Queue 보다 __deque 를 사용해야 인덱싱 판단을 로직에서 사용 할 수있다.__

처음 접근을 잘못했어서 바이너리서치 인줄 알았지만 .. 정렬되어서 방향성을 가지고 판단을 하는것이 아니라  __톱니가 돌 때 양쪽이 다 돌아야 함 !!__ (같은 극 일 경우 제외하고 돌리는 시도는 다해야한다.)

__일단 크게 세가지로 판단__ 

* 일단은 한칸씩 밀어내면서 시계방향, 반시계 방향으로 돌리는 로직 필요 
* 한번 돌기전에 왼쪽, 오른쪽 비교 포인트를  가지고 다음 혹은 이전 톱니바퀴의 비교포인트와 비교를 해서 돌릴지 말지 결정 해야함
* 재귀함수를 통해서 양쪽이 다돌경우 두번의 재귀가 생김 (처음 양쪽을 생각안하고 시계방향 반시계 방향만 생각해서 재귀를 돌려서 틀림 ㅠㅡㅠ)



이 세가지를 판단해서 시작함 ! 



# 코드

```swift
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
    //현재 기어의 오른쪽 기어 돌리기 시도
    if (bothSide == 1 || bothSide == 0) {
        
        if (gearNum != gearCount) {
            int nextGearLeftPoint = wholeGear[gearNum+1].at(6);
            
            if (rightPoint + nextGearLeftPoint == 1) {
                rotateGear(gearNum + 1, - direction, 1);
            }
        }
    }
    //현재 기어의 왼쪽 기어 돌리기 시도
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

```

