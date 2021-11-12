#include <cstdio>

int countCc(int A, int B, int C, int D) {
  return 1;
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
