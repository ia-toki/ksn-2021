#include <bits/stdc++.h>
using namespace std;

const int HRF=100;

int N, C[HRF];
char L;
string S, T;

bool isValid(char x) {
  int sum=0, maks=0;
  for (char i=0;i<HRF;i++) {
    sum+=C[i];
    if (i!=x&&C[i]>maks) {
      maks=C[i];
    }
  }
  return 2*maks<=sum;
}

char minChar() {
  char ret='_';
  for (char c : S) {
    if (c!=L&&c<ret&&isValid(c)) {
      ret=c;
    }
  }
  C[ret]--;
  S.erase(S.find(ret),1);
  return L=ret;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>N>>S;
  for (char c : S) {
    C[c]++;
  }
  for (int i=0;i<N;i++) {
    T+=minChar();
  }
  cout<<T<<'\n';
}
