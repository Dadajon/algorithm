#include <iostream>
#include <queue>

using namespace std;

int N, map[100][100];
bool visited[100][100];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
struct point {
    int y, x;
};
queue<point> q;

void BFS(int y, int x) {
    int ty, tx;
    visited[y][x] = true;
    q.push({y, x});

    while (true) {
        point t = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            ty = t.y + dy[i];
            tx = t.x + dx[i];

            if (ty >= 0 && ty < N && tx >= 0 && tx < N)
                if (!visited[ty][tx]) {
                    visited[ty][tx] = true;
                    q.push({ty, tx});
                }
        }
        if (q.empty()) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = -1, ch = 0, max = 0, before = 0;

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];

    while (true) {
        cnt++;
        before = 0;

        if (ch == 1) break;
        ch = 1;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (map[i][j] <= cnt)
                    visited[i][j] = true;
                else {
                    visited[i][j] = false;
                    ch = 0;
                }

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (!visited[i][j]) {
                    before++;
                    BFS(i, j);
                }

        if (before >= max) max = before;
    }

    cout << max << endl;
    return 0;
}