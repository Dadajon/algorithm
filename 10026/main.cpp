#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, result;
vector<int> v;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char color[] = {'R', 'G', 'B'};
char map[100][100];


void dfs(int cur_x, int cur_y) {
    for (int i : color) {
        if (map[cur_x][cur_y] == color[i]) {
            result++;
            for (int j = 0; j < 4; j++) {
                int new_x, new_y;
                new_x = cur_x + dx[j];
                new_y = cur_y + dy[j];
                if (0 <= new_x && new_x < N && 0 <= new_y && new_y < N) {
                    dfs(new_x, new_y);
                }
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }

    for (int l = 0; l < N; l++) {
        for (int m = 0; m < N; m++) {
            result = 0;
            dfs(l, m);
            if (result != 0){
                v.push_back(result);
            }
        }
    }


    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i:v)
        cout << i <<" ";
    cout << endl;

    return 0;
}