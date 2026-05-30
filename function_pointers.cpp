#include <iostream>
using namespace std;

void HelloWorld(){ cout << "Hello World" << endl;}

int function(int a, int b){ return a + b;}
int pointer_func(int x, int(p)(int,int)){return p(x,x);}
int main() {

  cout << pointer_func(10,function)<< endl;

  // auto hello_func = &HelloWorld;
  // or you can just do this
  auto hello_func = HelloWorld;
  // void(hello_func*)() this is the type of the hello function
  void(*hello_func_2)() = HelloWorld;
  // or we can do is
  void(*hello_func_3)() = &HelloWorld;
  // cpu is telling in the executable lets  find the hello world function and get the memory address of the instructions of the hello world function


  hello_func();
  hello_func_2();
  hello_func_3();


  return 0;
}