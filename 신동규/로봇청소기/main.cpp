//
//  main.cpp
//  algorithm_roboatVacuum
//
//  Created by 신동규 on 3/12/19.
//  Copyright © 2019 AlgoStudy. All rights reserved.
//

#include <iostream>
using namespace std;
// (북, 동, 남, 서)

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
// 후진 (남, 서, 북, 동)
int back_dx[4] = { 0,-1,0,1 };//좌우 움직임
int back_dy[4] = { 1,0,-1,0 };//상하 움직임

int feild[51][51];
int N,M,x,y,robotDir;
int cleanCount = 0;

void cleanSearch(int x, int y, int direction)
{
    // 벽이면 끝
    if (feild[y][x] == 1) return;
    
    // 빈 칸이면 청소한다.
    if (feild[y][x] == 0)
    {
        feild[y][x] = 2;
        cleanCount++;
    }
    
    // 네 방향 검사
    for (int k = 0; k < 4; k++)
    {
        int nextDirection = direction - 1 < 0 ? 3 : direction-1;
        
        int nextX = x + dx[nextDirection], nextY = y + dy[nextDirection];
        
        // 빈 칸이면 청소
        if (feild[nextY][nextX] == 0)
        {
            cleanSearch(nextX, nextY, nextDirection);
            
            // 다음 칸으로 넘어간 경우에 더 이상 나머지 방향을 검사하지 않는다.
            return;
        }
        // 청소했거나 벽이면 방향만 바꿔준다.
        else
        {
            direction = nextDirection;
        }
    }
    
    //후진후진
    int nextX = x + back_dx[direction], nextY = y + back_dy[direction];
    
    cleanSearch(nextX, nextY, direction);
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    cin >> y >> x >> robotDir;
    
    for (int i = 0; i < N; i++) {
        
        for (int j = 0; j < M; j++) {
            cin >> feild[i][j];
        }
    }
    cleanSearch(x, y, robotDir);
    
    cout << cleanCount << "\n";

    
    
    
    return 0;
}
