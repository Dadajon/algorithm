#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt;
int map[25][25];
bool visit[25][25];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<int> v;

void dfs(int y, int x) {
    visit[y][x] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (0 <= new_x && new_x < N && 0 <= new_y && new_y < N)
            if (map[new_y][new_x] == 1 && !visit[new_y][new_x])
                dfs(new_y, new_x);
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d", &map[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[i][j] == 1 && !visit[i][j]) {
                cnt = 0;
                dfs(i, j);
                if (cnt != 0) v.push_back(cnt);
            }

    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i : v)
        cout << i << endl;
    return 0;
}