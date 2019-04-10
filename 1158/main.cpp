#include <iostream>
#include <queue>

using namespace std;
int N, K;
queue<int> q;

void josephus() {
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        for (int i = 1; i <= K; i++) {
            int eleminated_position = q.front();
            q.pop();

            if (i == K) {
                cout << eleminated_position << (!q.empty() ? ", " : "");
                break;
            }
            q.push(eleminated_position);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    if (N == 1)
        cout << "<1>";
    else {
        cout << "<";
        josephus();
        cout << ">\n";
    }

    return 0;
}