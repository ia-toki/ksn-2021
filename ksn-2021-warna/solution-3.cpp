#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int X, Y;
int A[MAXN];

int main () {
  cin>>T>>N>>Q;
  
  A[1]=1;
  for (int i=2;i<=N;i++) {
    cout<<"? "<<i-1<<" "<<i<<endl;
    cin>>X;
    if (X==1) {
      A[i]=A[i-1];
      continue;
    }
    if (Y==0) {
      A[i]=2;
    }
    else {
      cout<<"? "<<Y<<" "<<i<<endl;
      cin>>X;
      if (X==2) {
        A[i]=A[Y];
      }
      else {
        A[i]=A[i-1]^A[Y];
      }
    }
    Y=i-1;
  }
  
  cout<<"!";
  for (int i=1;i<=N;i++) {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
