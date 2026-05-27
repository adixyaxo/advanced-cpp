#include <iostream>
#include <memory>

// smart pointers are are way to automate the process of freeing the memory after allocation ie after we use new we have to use delete and smartpointers automate that process

class entity
{
private:
public:
  entity(/* args */);
  ~entity();
  void print(void)
  {
    std::cout << "Print function called\n";
  }
};

entity::entity(/* args */)
{
  std::cout << "Entity Created\n";
}

entity::~entity()
{
  std::cout << "Entity Destroyed\n";
}

int main()
{

  {

    // without any smart pointer

    entity *a = new entity();

    // SHARED POINTERS USES REFRENCE COUNTING AS A BASIC
    // std::shared_ptr<entity> e = *(std::shared_ptr<entity>*)(new entity()); // man at this point instead of doing this just quit
    // std::shared_ptr<entity> e = new entity(); cant do this constructor doesnt allow this to happen
    std::shared_ptr<entity> e(new entity());
    e->print();

    // a better way to do this is
    std::shared_ptr<entity> e_better = std::make_shared<entity>(); // This now in shared pointer become exceptionally important because in the shared pointer it has to allocate another block of memory to the control block where it stores that refrence count and if you create a new entity and pass it to the shared constructor that is two allocations you are creating the entity first and shared pointer then has to constructor its control block where else if you use the bellow you construct them together which is lot more efficient

    e_better->print();

    // IN SHARED POINTERS COPPYING IS ALLOWED
    std::shared_ptr<entity> copy = e;

    std::weak_ptr<entity> weakcopy = copy; // weak pointer is same as shared pointer but weak pointer doesnt increase the ref count of the shared entity
    // its great is you dont want to take the ownership of the entity like a list of entities where you dont matter if they are valid or not you just want to stored the refrences or so
    //   A weak_ptr:

    // does NOT own the object
    // does NOT increase ref count
    // can outlive the object
    // becomes expired when all shared_ptr owners are gone

    // The weak pointer object itself follows normal scope rules.

    //     If all shared_ptrs disappear:

    // e.reset();
    // copy.reset();

    // then:

    // entity is destroyed
    // weakcopy still exists
    // but it points to nothing valid anymore

    // You must check it safely using:

    // if(auto temp = weakcopy.lock())
    // {
    //     temp->print();
    // }

    // lock() converts weak_ptr → shared_ptr if object still exists.
  }

  return 0;
}