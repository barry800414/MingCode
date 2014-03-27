#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> myqueue;
    int maxNum = 10, i;
    for(i = 0;i < 5; i++){
        myqueue.push(i);
        cout << "Now size:" << myqueue.size() << endl;
    }

    for(i = 0; i< 7; i++){
        if(myqueue.empty()){
            cout << "empty" << endl;
            continue;
        }
        cout << "number:" << myqueue.front() << endl;
        myqueue.pop();
    }
    
}
