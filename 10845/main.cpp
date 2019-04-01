//#include <cstdio>
//
//int q[10001], N, f, r, k;
//
//void push(int x) {
//    q[r++] = x;
//}
//
//void pop() {
//    if (r - f != 0) {
//        printf("%d\n", q[f]);
//        f++;
//    } else
//        printf("%d\n", -1);
//}
//
//void size() {
//    printf("%d\n", r - f);
//}
//
//void empty() {
//    if (r - f == 0)
//        printf("%d\n", 1);
//    else
//        printf("%d\n", 0);
//}
//
//void front() {
//    if (r - f != 0)
//        printf("%d\n", q[f]);
//    else
//        printf("%d\n", -1);
//}
//
//void back() {
//    if (r - f != 0)
//        printf("%d\n", q[r - 1]);
//    else
//        printf("%d\n", -1);
//}
//
//int main() {
//    char order[6];
//
//    scanf("%d", &N);
//
//    f = r = 0;
//
//    for (int i = 0; i < N; ++i) {
//        scanf("%s", order);
//        if (order[0] == 'p' && order[1] == 'u') {
//            scanf("%d", &k);
//            push(k);
//        } else if (order[0] == 'p' && order[1] == 'o') pop();
//        else if (order[0] == 's') size();
//        else if (order[0] == 'e') empty();
//        else if (order[0] == 'f') front();
//        else if (order[0] == 'b') back();
//    }
//
//    return 0;
//}


#include <iostream>
#include <queue>

using namespace std;

int N, k;
queue <int> q;

void pop() {
    if (!q.empty()) {
        printf("%d\n", q.front());
        q.pop();
    } else
        printf("%d\n", -1);
}

void empty() {
    if (!q.empty()) printf("%d\n", 0);
    else printf("%d\n", 1);
}

void front() {
    if (!q.empty()) printf("%d\n", q.front());
    else printf("%d\n",-1);
}

void back() {
    if (!q.empty()) printf("%d\n", q.back());
    else printf("%d\n",-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char order[6];

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%s", order);
        if (order[0] == 'p' && order[1] == 'u') {
            scanf("%d", &k);
            q.push(k);
        } else if (order[0] == 'p' && order[1] == 'o') pop();
        else if (order[0] == 's') printf("%lu\n", q.size());
        else if (order[0] == 'e') empty();
        else if (order[0] == 'f') front();
        else if (order[0] == 'b') back();
    }

    return 0;
}