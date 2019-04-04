#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case, N, M, importance;
    queue<pair<int, bool>> q;
    vector<int> v;

    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int doc_index = 0;
        cin >> N >> M;
        for (int j = 0; j < N; j++) {
            cin >> importance;
            q.push(make_pair(importance, j == M));
            v.push_back(importance);
        }

        sort(v.begin(), v.end());

        while (!q.empty()) {
            if (q.front().first == v[v.size() - 1]) {
                v.pop_back();
                doc_index++;
                if (q.front().second)
                    cout << doc_index << endl;
                q.pop();
            } else {
                q.push(make_pair(q.front().first, q.front().second));
                q.pop();
            }
        }
    }

    return 0;
}