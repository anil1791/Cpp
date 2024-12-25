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

int main()
{
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
}
