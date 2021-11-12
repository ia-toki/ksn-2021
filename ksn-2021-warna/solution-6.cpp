#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int A[MAXN];
int B[MAXN][MAXN];

int main () {
  cin>>T>>N>>Q;
  
  for (int i=1;i<=N;i++) {
    for (int j=i;j<=N;j++) {
      cout<<"? "<<i<<" "<<j<<endl;
      cin>>B[i][j];
    }
  }
  
  for (int i=1;i<=N;i++) {
    A[i]=B[1][i];
    for (int j=i-1;j>=1;j--) {
      if (B[j][i]==B[j][i-1]) {
        A[i]=A[j];
        break;
      }
    }
  }
  
  cout<<"!";
  for (int i=1;i<=N;i++) {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
