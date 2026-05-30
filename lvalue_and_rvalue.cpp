#include <iostream>
using namespace std;
#include <string>

int func(int a, int b) { return a + b; }

int &ref(int a, int b)
{
  static int x;
  x = a + b;
  return x;
}

int stvalue(int &a) { return a; }

int constref(const int &a) { return a; }

void print_l_value(string &s) { cout << s << endl; } // only takes l values

void print_r_value(string&& s){cout << s << endl;} // only takes r value

void print_r_and_l_value(string s) { cout << s << endl; } // takes both r and l value without refrence

void print_r_and_l_value_as_refrence(const string &s) { cout << s << endl; } // takes both r and l value with refrence as a const

int main()
{
  int i = 10;
  // here i is the l value and 10 is an r value

  int a = i;
  // here both i and a are l values

  int x = func(10, 11);
  // here x is the l value and func is the r value

  // we cant assign r value to something we will get an error if we try to do so
  // func(101,111) = 11; expression must be a modifiable lvalue

  ref(101, 11) = 1001;

  // you cannot take l value refrence from an r value
  // stvalue(10);initial value of reference to non-const must be an lvalue
  // int&a = 10; initial value of reference to non-const must be an lvalue
  // but here we have a work arount
  const int &a_const = 10;
  // because what under the hood happens is int temp = 10 and then const int &a = temp

  // NOTE a const l value refrence can accept both l value and r value
  constref(10);
  // and
  constref(i);
  // both are valid

  // case of strings

  std::string firstname = "yan";
  std::string secondname = "ban";
  std::string fullname = firstname + secondname;
  // here firstname + secondname is a r value

  print_l_value(firstname);
  // print_l_value(firstname+secondname);initial value of reference to non-const must be an lvalue
  // print_r_value(firstname); an rvalue reference cannot be bound to an lvalue
  print_r_value(firstname+secondname);
  print_r_and_l_value(firstname);
  print_r_and_l_value(firstname + secondname);
  print_r_and_l_value_as_refrence(firstname);
  print_r_and_l_value_as_refrence(firstname+secondname);
  return 0;
}