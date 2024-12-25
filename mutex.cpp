#include<bits/stdc++.h>
using namespace std;

int myAmount = 0;
std::mutex m;

void addMoney(){
    cout<<__func__<<" : myAmount :- "<<myAmount<<endl;
    m.lock();
    ++myAmount;
    m.unlock();
}

int main(){
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();
    cout<<myAmount<<endl;
}
