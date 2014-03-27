#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>& v){
    cout << "Now size:" << v.size() << "    Data:"; 
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << " " << *it;
    }
    cout << endl;
}

void eraseElement(vector<int>& v, int index){
    int cnt = 0;
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end() && cnt < index; it++, cnt++){}
    v.erase(it);
    return;
}

void insertElement(vector<int>& v, int index, int data){
    int cnt = 0;
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end() && cnt < index; it++, cnt++){}
    v.insert(it, data);
    return;
}


/*
 * Time complexity
 * O(1): push_back, front, back, pop_back
 * O(n): insert(given iterator), erase(given iterator)
 * */

int main(){
    vector<int> v;
    int num = 5, i;
    for(i = 0;i < num; i++){
        v.push_back(i);
        printVector(v);
    }

    for(i = 0; i< num + 2; i++){
        if(i < v.size()){
            cout << "data: " << v[i] << endl;
        }
    }

    eraseElement(v, 3);
    printVector(v);
    insertElement(v, 2, 10);
    printVector(v);
    return 0;
}
