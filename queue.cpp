#include<iostream>
#include<cstdlib>
#include"Queue.hpp"

using namespace std;

Queue::Queue(unsigned int maxSize){
    _head = 0; _tail = 0; _size = 0;
    _maxSize = maxSize;
    _data = new int[_maxSize];
}

Queue::~Queue(){
    delete _data;
}

bool Queue::isEmpty(){
    return (_head == _tail);
}

bool Queue::isFull(){
    unsigned int pre = (_head - 1 < 0) ? (_maxSize-1) : (_head-1);
    return (pre == _tail);
}

bool Queue::push(int data){
    if(isFull()){
        return false;
    }
    else{
        _data[_tail] = data;
        _tail = (_tail + 1) % _maxSize;
        _size += 1;
        return true;
    }
}

void Queue::pop(){
    if(!isEmpty()){
        cout << "_head:" << _head; 
        _head = (_head + 1) % _maxSize;
        cout << " _head:" << _head << endl;
        _size -= 1;
    }
    return;
}

int& Queue::front(){
    return _data[_head];
}

unsigned int Queue::size(){
    return _size;
}



int main(){
    int i, maxSize = 100;
    Queue queue((unsigned int)maxSize);
    for(i=0; i< maxSize; i++){
        queue.push(i);
        
    }
    for(i=0; i< maxSize; i++){
        cout << queue.front() << " " ;
        queue.pop();
    }
    cout << endl;
    return 0;
}


