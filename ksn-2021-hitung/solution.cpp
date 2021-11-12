#include <iostream>
using namespace std;

int n, x, prv;

int main() {
  cin >> n;
  prv = 0;
  for(int i = 0; i < n; i++) {
    cin >> x;
    if(prv + 1 == x) {
      cout << "BENAR" << endl;
      prv++;
    } else {
      cout << "SALAH" << endl;
      prv = 0;
    }
  }
  return 0;
}
