#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int> s;
    int maxNum = 10, i;
    for(i = 0;i < 5; i++){
        s.push(i);
        cout << "Now size:" << s.size() << endl;
    }

    for(i = 0; i< 7; i++){
        if(s.empty()){
            cout << "empty" << endl;
            continue;
        }
        cout << "number:" << s.top() << endl;
        s.pop();
    }
    
}
