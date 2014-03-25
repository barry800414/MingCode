#include<cstdio>

using namespace std;

class Queue {
public:
    Queue(unsigned int maxSize);
    int push(int data);
    int pop();
    void reset();
    bool isEmpty();
    bool isFull();
private:
    unsigned int _size, _head, _tail;
    unsigned int _maxSize;
    unsigned int *_data;
}
    
