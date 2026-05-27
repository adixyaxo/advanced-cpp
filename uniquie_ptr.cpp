#include <iostream>
#include <memory>

// smart pointers are are way to automate the process of freeing the memory after allocation ie after we use new we have to use delete and smartpointers automate that process

class entity
{
private:
public:
  entity(/* args */);
  ~entity();
  void print(void){
    std::cout << "Print function called\n";
  }
};

entity::entity(/* args */)
{
  std::cout<<"Entity Created\n";
}

entity::~entity()
{
  std::cout<<"Entity Destroyed\n";
}


int main()
{



  {

  // without any smart pointer

  entity *a = new entity();

  // std::unique_ptr<entity> e = new entity(); cant do this constructor doesnt allow this to happen
  std::unique_ptr<entity> e(new entity());
  e->print();

  // a better way to do this is
  std::unique_ptr<entity> e_better = std::make_unique<entity>(); // This is preffered due to exception saftey
  e_better->print();

  // IN UNIQUE POINTERS COPPYING IS NOT ALLOWED
  // std::unique_ptr<entity> copy = e;
  // function "std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp> &) [with _Tp=entity, _Dp=std::default_delete<entity>]" (declared at line 524 of "/usr/include/c++/15/bits/unique_ptr.h") cannot be referenced -- it is a deleted function



  }


  return 0;
}