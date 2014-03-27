#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>

using namespace std;

void printMap(map<int, float>& m){
    cout << "Now size:" << m.size() << "    Data:"; 
    for(map<int, float>::iterator it = m.begin(); it != m.end(); it++){
        cout << " " << it->first << ":" << it->second << "  ";
    }
    cout << endl;
}

void eraseKey(map<int, float>& m, int key){
    int cnt = 0;
    map<int, float>::iterator it = m.find(key);
    if(it != m.end()){
        m.erase(it);
    }
    return;
}

/*
 * Time complexity
 * O(1): push_back, front, back, pop_back
 * O(n): insert(given iterator), erase(given iterator)
 * */

int main(){
    map<int, float> m;
    int num = 5, i;
    for(i = 0;i < num; i++){
        m.insert( pair<int, float> (i, (float)i));
        printMap(m);
    }
    
    for(i = 0;i < num; i++){
        m.insert( pair<int, float> (i + num, (float)i + num));
        printMap(m);
    }

    for(i = 0; i< num + 2; i++){
        if(i < m.size()){
            eraseKey(m,i);
            printMap(m);
        }
    }

    return 0;
}
