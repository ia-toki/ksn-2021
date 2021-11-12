#include <cstdio>

int isGood(int x, int y) {
  return (x & y) == 0;
}

int countCc(int A, int B, int C, int D) {
  int diff = 0;
  for (int j = B + 1; j <= D; ++j) {
    if (isGood(A, j - 1) != isGood(A, j)) diff++;
  }
  if (isGood(A, B)) return 1 + diff / 2;
  return (diff + 1) / 2;
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
