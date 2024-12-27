#include<bits/stdc++.h>
using namespace std;

class Expense{
    string createdOn;
    string createdBy;
    double amount;
    string title;
    public:
    Expense(string createdon, string n, double amt,string t):createdOn(createdon),createdBy(n),amount(amt),title(t){}
    void showExpense(){
        cout<<"---"<<title<<"---"<<endl;
        cout<<"Amout : "<<amount<<endl;
        cout<<"Date : "<<createdOn<<endl;
        cout<<"Created by : "<<createdBy<<endl;

    }
};

class User{
    string name;
    double totalBalance = 0;
    vector<string>timeline;
    vector<Expense>expenseList;
    unordered_map<User*,double>userMap; 
    public:
    User(string nn):name(nn),totalBalance(0.0){}
    string getUserName(){return name;}
    double getAmount(){return totalBalance;}
    void updateTimeline(string str){timeline.push_back(str);}
    void printTimeline(){
        for(const auto &str:timeline){
            cout<<str<<endl;
        }
    }
    void updateExpense(Expense &e){expenseList.push_back(e);}
    void updateUserMap(User *uu,double amt){
        totalBalance+=amt;
        userMap[uu]+=amt;
    }
    void showDashboard(){
        cout<<"-----"<<name<<"------"<<endl;
        cout<<"\tTotal balance : "<<totalBalance<<endl;
        for(const auto&[user,amt]:userMap){
            if(amt<0){
                cout<<"You owe "<<user->getUserName()<<" amount : "<<-amt<<endl;
            }else{
                cout<<user->getUserName()<<" owes you amount : "<<amt<<endl;
            }
        }
        cout<<endl;
    }
    void showExpenseList(){
        cout<<"Expense list for "<<name<<"------"<<endl;
        
        for(auto exp:expenseList){
            exp.showExpense();
        }
        cout<<endl;
    }
};


class ExpenseManager{
    public:
    std::string getCurrentDate() {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        
        std::ostringstream oss;
        oss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
    void addExpense(User &u1,string title,double amt,vector<User*>userlist){
        Expense exp(getCurrentDate(), u1.getUserName(),amt,title);
        int n = userlist.size();
        double splitPrice = amt/(n+1);
        for(User *u:userlist){
            u1.updateUserMap(u,splitPrice);
            u->updateUserMap(&u1,-splitPrice);
            std::ostringstream oss;
            oss << u1.getUserName() << " added " << title << " for amount " << splitPrice;
            string tl = oss.str();

            u->updateTimeline(tl);
            u->updateExpense(exp);
            //u.printTimeline();
        }
        //u1.updateTimeline("You added "+title+" for amount : "+to_string(amt));
        //u1.printTimeline();
    }
    void showUserDashboard(vector<User*>arr){
        for(auto user:arr){
            user->showDashboard();
        }
    }
    void showExpenseList(vector<User*>arr){
        for(auto user:arr){
            user->showExpenseList();
        }
    }
};

int main()
{
    ExpenseManager expMgr;
    User u1("Becca");
    User u2("Arya");
    User u3("John");

    expMgr.addExpense(u1,"Groceries",100,{&u2,&u3});
    expMgr.addExpense(u2,"Electricity",1230,{&u1});
    expMgr.addExpense(u3,"Maid",3000,{&u1,&u2});
    vector<User*> users = {&u1, &u2, &u3};
    //expMgr.showUserDashboard(users);
    expMgr.showExpenseList(users);
}
