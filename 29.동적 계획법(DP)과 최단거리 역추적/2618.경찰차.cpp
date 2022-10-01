 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct grid {
    int x;
    int y;
}cod;
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}
cod Acc[1001];
cod CarA, CarB;
int DP[1001][1001];
int n,m;
int Find_Dist(cod A, cod B) {
    return abs(A.x - B.x) + abs(A.y - B.y);
}

int Total_Distance(int A, int B) {
    if (A == m || B == m) return 0;
    if (DP[A][B] != -1) return DP[A][B];

    int Next_Acc = max(A, B) + 1;
    int DistA, DistB;

    if (!A) DistA = Find_Dist({ 1,1 }, Acc[Next_Acc]);
    else DistA = Find_Dist(Acc[A], Acc[Next_Acc]);

    if (!B) DistB = Find_Dist({ n,n }, Acc[Next_Acc]);
    else DistB = Find_Dist(Acc[B], Acc[Next_Acc]);

    int ResultA = DistA + Total_Distance(Next_Acc, B);
    int ResultB = DistB + Total_Distance(A, Next_Acc);

    DP[A][B] = min(ResultA, ResultB);

    return DP[A][B];
}
void Route(int A, int B) {
    if (A == m || B == m) return;

    int Next_Acc = max(A, B) + 1;
    int DistA, DistB;

    if (!A) DistA = Find_Dist({ 1,1 }, Acc[Next_Acc]);
    else DistA = Find_Dist(Acc[A], Acc[Next_Acc]);

    if (!B) DistB = Find_Dist({ n,n }, Acc[Next_Acc]);
    else DistB = Find_Dist(Acc[B], Acc[Next_Acc]);

    if (DistA + DP[Next_Acc][B] < DistB + DP[A][Next_Acc]) {
        printf("1\n");
        Route(Next_Acc, B);
    }
    else {
        printf("2\n");
        Route(A, Next_Acc);
    }

}
int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &Acc[i].x, &Acc[i].y);
    }
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            DP[i][j] = -1;

    CarA = { 1,1 };
    CarB = { n,n };
    printf("%d\n",Total_Distance(0, 0));
    Route(0, 0);
    return 0;
}