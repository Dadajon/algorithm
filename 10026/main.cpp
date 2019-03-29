#include <iostream>
#include <algorithm>
using namespace std;

int N, normal = 0, color_blind = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char color[] = {'R', 'G', 'B'};
char map[100][100];
bool visited[100][100];

void dfs(int cur_x, int cur_y, char col) {
    visited[cur_x][cur_y] = true;
    for (int j = 0; j < 4; j++) {
        int new_x, new_y;
        new_x = cur_x + dx[j];
        new_y = cur_y + dy[j];
        if (0 <= new_x && new_x < N && 0 <= new_y && new_y < N)
            if (!visited[new_x][new_y] && map[new_x][new_y] == col)
                dfs(new_x, new_y, col);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];

    for (char i : color)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (!visited[j][k] && map[j][k] == i) {
                    dfs(j, k, i);
                    normal++;
                }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'G') map[i][j] = 'R';
            visited[i][j] = false;
        }

    for (char i : color)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (!visited[j][k] && map[j][k] == i) {
                    dfs(j, k, i);
                    color_blind++;
                }

    cout << normal << " " << color_blind << endl;

    return 0;
}