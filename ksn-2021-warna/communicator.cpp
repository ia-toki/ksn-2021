#include <bits/stdc++.h>
using namespace std;

void ac() {
  cerr << "AC\n";
  exit(0);
}

void wa() {
  cerr << "WA\n";
  exit(0);
}

void eof() {
  string s;
  if (cin >> s) {
    wa();
  }
}

string read() {
  string s;
  if (!(cin >> s)) {
    wa();
  }
  return s;
}

int readInt() {
  string s = read();
  if (s.length() > 4) {
    wa();
  }
  int t = 0;
  for (char c:s) {
    if (c < '0' || c > '9') wa();
    t = t * 10 + c - '0';
  }
  return t;
}

const int MAXN=1e3+5;

int T, N, Q;
int A[MAXN], B[MAXN][MAXN], C[MAXN];

void init() {
  for (int i=1;i<=N;i++) {
    for (int j=i;j<=N;j++) {
      B[i][j]=B[i][j-1];
      if (!C[A[j]]++) {
        B[i][j]++;
      }
    }
    for (int j=1;j<=N;j++) {
      C[j]=0;
    }
  }
}

void ask() {
  if (!Q--) {
    wa();
  }
  
  int L = readInt(), R = readInt();
  
  if (1 <= L && L <= R && R <= N) {
    cout << B[L][R] << endl;
  }
  else {
    wa();
  }
}

void answer() {
  for (int i = 1; i <= N; i++) {
    C[i] = readInt();
    if (C[i] < 1 || C[i] > N) {
      wa();
    }
    for (int j = 1; j < i; j++) {
      if ((C[i] == C[j])^(A[i] == A[j])) {
        wa();
      }
    }
  }
  
  eof();
  ac();
}

int main(int argc, char* argv[]) {
  ifstream tc_in(argv[1]);
  tc_in >> T >> N >> Q;
  for (int i = 1; i <= N; i++) {
    tc_in >> A[i];
  }
  
  init();
  cout << T << '\n';
  cout << N << ' ' << Q << endl;
  while (true) {
    string S = read();
    
    if (S == "?") {
      ask();
    }
    else if (S == "!") {
      answer();
    }
    else {
      wa();
    }
  }
}
