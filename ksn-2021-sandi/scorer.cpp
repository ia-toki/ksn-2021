#include <bits/stdc++.h>
using namespace std;

int Q, K, C, P;

void wa() {
  cout << "WA\n";
  exit(0);
}

void ac() {
  cout << "AC\n";
  exit(0);
}

void eof(istream &is) {
  string s;
  if (is >> s) {
    wa();
  }
}

int readInt(istream &is) {
  int a;
  if (!(is >> a)) {
    wa();
  }
  return a;
}

int main(int argc, char* argv[]) {
  ifstream tc_in(argv[1]);
  ifstream tc_out(argv[2]);
  ifstream con_out(argv[3]);

  tc_in >> Q >> K;
  for (int i = 1; i <= Q; i++) {
    tc_in >> C;
    P = readInt(con_out);
    if ((K|C)==C) {
      if ((K|P)!=C) {
        wa();
      }
    }
    else {
      if (P!=-1) {
        wa();
      }
    }
  }
  
  eof(con_out);
  ac();
}
