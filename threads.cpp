#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std::chrono;

static std::atomic<bool> s_finished = false;

void do_work()
{
    int i = 0;

    while (!s_finished)
    {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(1s);
        i++;
    }
}

int main()
{

    std::thread worker(do_work);
    std::thread worker2(do_work);
    std::cin.get();
    s_finished = true;

    worker.join();
    worker2.join();
    return 0;
}