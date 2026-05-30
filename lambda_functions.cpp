// It is a way to create a function without actually creating a function
// A quick disposable function
// whenever you have a function pointer you can use a lambda in c++
// lambdas are a way to create anonymous functions
#include <iostream>
using namespace std;

int function(int a,int(*func)(int,int)){
  return func(a,a);
}

int main() {

  cout << function(10,[](int value1,int value2){return value1*value2;})<<endl;

  // here lambda function can be made as

  auto lambda = [](int a,int b){return a*b;};
  cout << function(10,lambda)<<endl;
  return 0;
}