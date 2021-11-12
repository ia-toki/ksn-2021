#include <cstdio>

int isGood(int x, int y) {
  return (x & y) == 0;
}

int countCcRow(int R, int A, int B) {
  int diff = 0;
  for (int j = A + 1; j <= B; ++j) {
    if (isGood(R, j - 1) != isGood(R, j)) diff++;
  }
  if (isGood(R, A)) return 1 + diff / 2;
  return (diff + 1) / 2;
}

int countCc(int A, int B, int C, int D) {
  return countCcRow(A, B, D) + countCcRow(B, A, C) - isGood(A, B);
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
