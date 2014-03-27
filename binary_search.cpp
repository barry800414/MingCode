#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<vector>


int binary_search(vector<int> &v, int value, int start, int end){
    int size = end - start + 1;
    
    if(size == 1){
        if(v[start] == value){ return start; }
        else{ return -1; }
    }
    else{
        int middle = start + size;
        if(v[middle] == value){
            return middle;
        }
        int r;
        r = binary_search(start, middle - 1);
        if(r != -1) { return r; }
        if(middle < end){
            r = binary_search(middle + 1, end);
        }
        return r;
    }
}

int main(){
    
    vector<int> v;
    int i, num = 99;

    for(i=1; i<=num; i++){
        v.push_back(i);
    }

    cout << "30:" << binary_search(v, 30, 0, v.size()) << endl;
    cout << "70:" << binary_search(v, 70, 0, v.size()) << endl;

}
