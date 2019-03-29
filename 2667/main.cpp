#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt, danji_su = 0;
int map[25][25], danji[625], visit[25][25];

void DFS(int y, int x) {
    cnt++;
    visit[y][x] = 1;


    if (y + 1 >= 0 && y + 1 < n && x >= 0 && x < n)
        if (map[y + 1][x] == 1 && visit[y + 1][x] == 0)
            DFS(y + 1, x);

    if (y - 1 >= 0 && y - 1 < n && x >= 0 && x < n)
        if (map[y - 1][x] == 1 && visit[y - 1][x] == 0)
            DFS(y - 1, x);

    if (y >= 0 && y < n && x + 1 >= 0 && x + 1 < n)
        if (map[y][x + 1] == 1 && visit[y][x + 1] == 0)
            DFS(y, x + 1);

    if (y >= 0 && y < n && x - 1 >= 0 && x - 1 < n)
        if (map[y][x - 1] == 1 && visit[y][x - 1] == 0)
            DFS(y, x - 1);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%1d", &map[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (map[i][j] == 1 && visit[i][j] == 0) {
                cnt = 0;
                DFS(i, j);
                danji[danji_su] = cnt;
                danji_su++;
            }

    sort(danji, danji + danji_su);

    printf("%d\n", danji_su);

    for (int i = 0; i < danji_su; i++)
        printf("%d\n", danji[i]);

    return 0;
}


