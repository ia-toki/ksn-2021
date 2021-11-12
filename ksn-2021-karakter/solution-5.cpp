#include <bits/stdc++.h>
using namespace std;

int N;
string S;

bool valid() {
  for (int i=1;i<N;i++) {
    if (S[i-1]==S[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  cin>>N>>S;
  sort(S.begin(),S.end());
  do {
    if (valid()) {
      cout<<S<<'\n';
      break;
    }
  }
  while (next_permutation(S.begin(),S.end()));
}
