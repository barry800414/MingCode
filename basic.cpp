#include"basic.hpp"
#include<assert.h>

using namespace std;

Queue::Queue(unsigned int maxSize){
    assert(maxSize >= 0);
    _data = (int *)malloc(sizeof(int)*maxSize);
    _size = 0, _head = 0, _tail = 0;
    _maxSize = maxSize;
}

int Queue::push(int data){
    if(isFull()){
        return -1;
    }
    else{
        
    }
}

