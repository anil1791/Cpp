#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void findSum(int start, int end)
{
    long long sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += i;
    }
    cout << sum << endl;
}
class Base{
    public:
    void print(int x){
        while(x>0){
            cout<<x<<" ";
            x--;
        }
    }
};

class Car{
    public:
    static void drive(int speed){
        int x = 0;  cout<<"Accelerating from to "<<speed<<endl;
        while(x<speed){
            cout<<x<<" ";
            x++;
        }
    }
};

int main()
{
    //THREAD using static member function

    std::thread t1(&Car::drive,40);
    if(t1.joinable())
        t1.join();


    /*
    //THREAD using non-static member function

    Base b;
    std::thread t1(&Base::print,&b,5);
    t1.join();
    */
    /*
    // THREAD using LAMBDA function
    auto function = [](int x)
    {
        while (x > 0)
        {
            cout << x << " ";
            x--;
        }
    };*/
    /*
    auto startTime = high_resolution_clock::now();
    std::thread t1(findSum, 1, 100909099);
    std::thread t2(findSum, 1, 100909099);
    t1.join();
    t2.join();
    // findSum(1, 100909099);
    // findSum(1, 100909099);
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime);
    cout << "Time in microseconds :- " << (duration.count()) << endl;
    */
}
