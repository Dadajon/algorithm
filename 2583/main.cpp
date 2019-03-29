#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N, K, result;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool map[100][100];
vector <int> stk;

void dfs(int cur_x, int cur_y){
    if (!map[cur_x][cur_y]) {
        map[cur_x][cur_y] = true;
        result++;
        for (int i = 0; i < 4; i++) {
            int new_x = cur_x + dx[i];
            int new_y = cur_y + dy[i];
            if (0 <= new_x && new_x < M && 0 <= new_y && new_y < N)
                dfs(new_x, new_y);
        }
    }
}

int main(){
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int start_x, end_x, start_y, end_y;
        cin >> start_y >> start_x >> end_y >> end_x;

        for (int j = start_x; j < end_x; j++)
            for (int k = start_y; k < end_y; k++)
                map[j][k] = true;
    }

    for (int l = 0; l < M; l++) {
        for (int m = 0; m < N; m++) {
            result = 0;
            dfs(l, m);
            if (result != 0){
                stk.push_back(result);
            }
        }
    }

    sort(stk.begin(),stk.end());
    cout << stk.size() << endl;
    for (int i : stk)
        cout<< i <<" ";
    cout<<endl;

    return 0;
}