#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, m;
    vector<pair<int, int>> v[1001];
    int dist[1001];

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        v[start].push_back({end, weight});
    }
    int start, end;
    cin >> start >> end;

    for (int i = 1; i <= n; i++) {
        dist[i] = 987654321;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 
    dist[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        int cost = q.top().first;
        int curnode = q.top().second;
        q.pop();

        if (cost > dist[curnode]) continue; 

        for (int i = 0; i < v[curnode].size(); i++) {
            int nextnode = v[curnode][i].first;
            int nextcost = cost + v[curnode][i].second; 

            if (dist[nextnode] > nextcost) {
                dist[nextnode] = nextcost;
                q.push({nextcost, nextnode});
            }
        }
    }

    cout << dist[end];
}
