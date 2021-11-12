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
  if(cin >> s) {
    wa();
  }
}

string read() {
  string s;
  if(!(cin >> s)) {
    wa();
  }
  return s;
}

const int MAX_Q = 1e4+5;
int Q;
int A[MAX_Q];
int prv = 0;

int main(int argc, char* argv[]) {
  ifstream tc_in(argv[1]);
  tc_in >> Q;
  for(int i = 0; i < Q; i++) {
    tc_in >> A[i];
  }

  cout << Q << '\n';
  for(int i = 0; i < Q; i++) {
    cout << A[i] << endl;
    string S = read();
    string expect = (A[i] == prv+1) ? "BENAR" : "SALAH";
    if(S != expect) {
      wa();
    } else {
      if(expect == "BENAR") {
        prv++;
      } else {
        prv = 0;
      }
    }
  }
  eof();
  ac();
}
