#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int A[MAXN];

int main () {
  cin>>T>>N>>Q;
  
  for (int i=1;i<=N;i++) {
    cout<<"? 1 "<<i<<endl;
    cin>>A[i];
  }
  
  cout<<"!";
  for (int i=1;i<=N;i++) {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
