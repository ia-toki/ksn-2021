#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main() {
  cin>>N>>S;
  if (S[0]=='B'&&N%2==0) {
    reverse(S.begin(),S.end());
  }
  cout<<S<<'\n';
}
