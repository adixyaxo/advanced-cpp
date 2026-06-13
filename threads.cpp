#include <iostream>
#include <thread>
using namespace std;
static bool s_finished = false;
void do_work(){
  int i = 0;
  while (!s_finished)
  {
    cout << i << endl;
    this_thread::sleep_for(1s);
    i++;
  }

}

int main() {
  thread worker(do_work);
  cin.get();
  s_finished= true;
  worker.join();
  return 0;
}