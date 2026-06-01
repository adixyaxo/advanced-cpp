#include <iostream>
#include <string>
#include <memory>
#include <cstring>
using namespace std;

class s
{

  char* m_Data;
  u_int32_t m_Size;

public:
  s() =default;
  s(const char* str){
    printf("Created\n");
    m_Size = strlen(str);
    m_Data = new char[m_Size];
    memcpy(m_Data,str,m_Size);
  }

  s(const s& other){
    printf("Copied\n");
    m_Size = other.m_Size;
    m_Data = new char[m_Size];
    memcpy(m_Data,other.m_Data,m_Size);
  }

  void Print(){
    cout << m_Data << endl;
  }


  ~s(){
    delete m_Data;
  };



  // writing a move constructor
  s(s&& other)
  {
    printf("Moved\n");
    m_Size = other.m_Size;
    m_Data = other.m_Data;
    other.m_Size = 0;
    other.m_Data = nullptr;
  }
};

class Enitity{
  public:
  Enitity(const s& name) : m_Name(name){

  }

  void print_name(){
    m_Name.Print();
  }
  // move semantic r value constructor
  Enitity(s&& name) : m_Name((s&&)name){}

  private:
  s m_Name;
};


int main() {

  Enitity entity(s("Aditya"));
  entity.print_name();
  Enitity semantic_entity("Aditya");
  semantic_entity.print_name();

  return 0;
}