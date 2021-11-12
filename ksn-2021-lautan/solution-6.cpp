#include <cstdio>

const int kMaxLog = 30;

int isGood(int x, int y) {
  if (x < 0 || y < 0) return 0;
  return (x & y) == 0;
}

// Count number of cc in submatrix (R, 0) - (R, C - 1)
int countCcRow(int R, int C) {
  if (C <= 0) return 0;
  return (C - 1) / (R * 2) + 1;
}

// Count number of cc in submatrix (R, A) - (R, B)
int countCc(int A, int B, int C, int D) {
  return countCcRow(A, D + 1) - countCcRow(A, B) +
         (isGood(A, B - 1) && isGood(A, B));
}

void solve() {
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);
  for (int i = 0; i < Q; ++i) {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("%d\n", countCc(A, B, C, D));
  }
}

int main() {
  solve();
  return 0;
}
