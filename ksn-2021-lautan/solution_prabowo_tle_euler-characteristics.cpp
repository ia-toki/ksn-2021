#include <bits/stdc++.h>

std::vector<std::vector<int>> prefNode, prefHori, prefVert;

void init(int N, int M) {
  prefNode.assign(N, std::vector<int>(M, 0));
  prefHori = prefVert = prefNode;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      prefNode[i][j] = (i & j) == 0;
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 1; j < M; ++j) {
      prefHori[i][j] = prefNode[i][j] && prefNode[i][j - 1];
      prefHori[i][j] += prefHori[i][j - 1];
      if (i > 0) prefHori[i][j] += prefHori[i - 1][j] - prefHori[i - 1][j - 1];
    }
  }

  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      prefVert[i][j] = prefNode[i][j] && prefNode[i - 1][j];
      prefVert[i][j] += prefVert[i - 1][j];
      if (j > 0) prefVert[i][j] += prefVert[i][j - 1] - prefVert[i - 1][j - 1];
    }
  }

  for (int i = 1; i < N; ++i) prefNode[i][0] += prefNode[i - 1][0];
  for (int j = 1; j < M; ++j) prefNode[0][j] += prefNode[0][j - 1];
  for (int i = 1; i < N; ++i) for (int j = 1; j < M; ++j) {
    prefNode[i][j] += prefNode[i - 1][j] + prefNode[i][j - 1] - prefNode[i - 1][j - 1];
  }
}

int countCc(int A, int B, int C, int D) {
  int V = prefNode[C][D];
  if (A > 0) V -= prefNode[A - 1][D];
  if (B > 0) V -= prefNode[C][B - 1];
  if (A > 0 && B > 0) V += prefNode[A - 1][B - 1];

  int E = prefHori[C][D] - prefHori[C][B];
  if (A > 0) E -= prefHori[A - 1][D] - prefHori[A - 1][B];

  E += prefVert[C][D] - prefVert[A][D];
  if (B > 0) E -= prefVert[C][B - 1] - prefVert[A][B - 1];

  return V - E;
}

void solve() {
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);
  init(N, M);
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
