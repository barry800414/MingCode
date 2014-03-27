#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<list>

using namespace std;

void printList(list<int> mylist){
    cout << "Now size:" << mylist.size() << "    Data:"; 
    for(list<int>::iterator it = mylist.begin(); it != mylist.end(); it++){
        cout << " " << *it;
    }
    cout << endl;
}

/*
 * Time complexity
 * O(1): push_front, push_back, front, back, pop_front, pop_backinsert(given iterator), erase(given iterator)
 * O(n): insert(given index), erase(given index)
 * 
 * */

int main(){
    list<int> mylist;
    int num = 5, i;
    for(i = 0;i < num; i++){
        mylist.push_front(i);
        printList(mylist);
    }
    for(i = 0;i < num; i++){
        mylist.push_back(i);
        printList(mylist);
    }

    for(i = 0; i< num + 2; i++){
        if(mylist.empty()){
            cout << "empty" << endl;
            continue;
        }
        cout << "data:" << mylist.front() << endl;
        mylist.pop_front();
    }
    for(i = 0; i< num + 2; i++){
        if(mylist.empty()){
            cout << "empty" << endl;
            continue;
        }
        cout << "data:" << mylist.back() << endl;
        mylist.pop_back();
    }
    return 0;
}
