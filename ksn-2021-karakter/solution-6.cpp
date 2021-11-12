#include <bits/stdc++.h>
using namespace std;

const int HRF=100;

int N, C[HRF];
char L;
string S, T;

bool isValid(char x) {
  int sum=0, maks=0;
  memset(C,0,sizeof(C));
  for (char c : S) {
    C[c]++;
    if (c!=x&&C[c]>maks) {
      maks=C[c];
    }
  }
  return 2*maks<=(int)S.length();
}

char minChar() {
  char ret='_';
  for (char c : S) {
    if (isValid(c)&&c!=L&&c<ret) {
      ret=c;
    }
  }
  S.erase(S.find(ret),1);
  return L=ret;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>N>>S;
  for (int i=0;i<N;i++) {
    T+=minChar();
  }
  cout<<T<<'\n';
}
