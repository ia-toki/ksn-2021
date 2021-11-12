#include <cstdio>

const int kMaxLog = 30;

inline int min(int a, int b) {
  return a < b ? a : b;
}

int isGood(int x, int y) {
  if (x < 0 || y < 0) return 0;
  return (x & y) == 0;
}

// Count number of cc in submatrix (R, 0) - (R, C - 1)
int countCcRow(int R, int C) {
  if (C <= 0) return 0;

  int cc = 0, len = C;
  for (int bit = kMaxLog - 1; bit >= 0; --bit) {
    if (R >> bit & 1) {
      int period = 1 << (bit + 1);
      cc = (len - 1) / period;
      len = len / period * (1 << bit) + min(len % period, 1 << bit);
    }
  }
  return cc + 1;
}

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
