#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
int cnt = 0;
bool first_visit = true;
int fasted_time = 987654321;

int main(void) {
    int n, k;
    cin >> n >> k;

    fill(visited, visited + 100001, false);
    visited[n] = 0; // 시작 위치의 시간 초기화
    queue<pair<int, int>> q;

    q.push({n, visited[n]});

    while (!q.empty()) {
        int next = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[next] = true;
      
        if (next == k) {
            if(fasted_time == 987654321 && first_visit){
                fasted_time = time;
                first_visit = false;
                cnt++;
            }
            else if(fasted_time != 987654321 && fasted_time == time && !first_visit){
                cnt++;
            }
            
        }

        if (next - 1 >= 0 && !visited[next - 1]) {
            q.push({next - 1, time + 1});
        }
        if (next + 1 <= 100000 && !visited[next + 1]) {
            q.push({next + 1, time + 1});
        }
        if (next * 2 <= 100000 && !visited[next * 2]) {
            q.push({next * 2, time + 1});
        }
    }

    cout << fasted_time << '\n'; 
    cout << cnt << '\n'; 
}