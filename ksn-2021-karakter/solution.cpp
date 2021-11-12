#include <bits/stdc++.h>
using namespace std;

const int HRF=26;

int N, C[HRF], L=-1;
string S, T;

bool isValid(int x) {
  int sum=0, maks=0;
  for (int i=0;i<HRF;i++) {
    sum+=C[i];
    if (i!=x&&C[i]>maks) {
      maks=C[i];
    }
  }
  return 2*maks<=sum;
}

int minChar() {
  for (int i=0;i<HRF;i++) {
    if (i!=L&&C[i]&&isValid(i)) {
      C[i]--;
      return L=i;
    }
  }
  return HRF;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>N>>S;
  for (char c : S) {
    C[c-'A']++;
  }
  for (int i=0;i<N;i++) {
    T+='A'+minChar();
  }
  cout<<T<<'\n';
}
