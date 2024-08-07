#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void taskA()
{
    for(int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "TaskA : " << i << endl;
        fflush(stdout);
    }
}

void taskB()
{
    for(int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "TaskB : " << i << endl;
        fflush(stdout);
    }
}

int main()
{
    std::thread t1(taskA);
    std::thread t2(taskB);

    t1.join();
    t2.join();
    
    return 0;
}
