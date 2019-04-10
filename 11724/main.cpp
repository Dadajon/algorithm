#include <iostream>
#include <vector>

using namespace std;

int N, M, u, v;
int map[1001];
vector<int> pVector[1001];

void input() {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        pVector[u].push_back(v);
        pVector[v].push_back(u);
    }
}

void connect(int point) {
    map[point] = 1;
    for (int i : pVector[point]) {
        if (map[i] == 0)
            connect(i);
    }
}

void make_result() {
    int result = 0;
    for (int i = 1; i <= N; ++i) {
        if (map[i] == 0) {
            result++;
            connect(i);
        }
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    make_result();

    return 0;
}