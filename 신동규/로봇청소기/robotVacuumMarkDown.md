# 로봇 청소기 - 시뮬레이션문제

문제 후 판단:  로봇 청소기의 위치와 방향을 가지고 다음 위치를 판별하고 그곳이 벽이아니고, 청소가 필요로하는곳이면 청소를 하는 로직  

판단을 해야할것들

* 현재 청소기의 방향 
* 네 방면의 위치 이동에 관련된 int 할당
* DFS 개념으로 4가지의 방향에 대해서 순차적으로 탐색해야함
* 재귀의 방법으로 지속적으로 다음 청소 자리를 탐색해야함 



그리고 세로 값과 가로 값을 생각하는데 주의해야함 우리는 통상적으로 (x,y)좌표를 생각하지만

여기서 feild y x 이다 

# 코드

```swift
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

```

