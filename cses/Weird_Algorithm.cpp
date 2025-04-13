#include <iostream>
using namespace std;

unsigned long oper(unsigned long n){
  cout << n << " ";
  if(n == 1){
    return 0;
  }
  if(n % 2 == 0){
    return oper(n/2);
  }
  else{
    return oper(3*n+1);
  }
}

int main(){
  unsigned long  n;
  cin >> n;
  oper(n);
}