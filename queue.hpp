#include<cstdlib>

using namespace std;


/*Circulated Queue (one-side)*/
class Queue{
public:
    Queue(unsigned int maxSize);
    ~Queue();
    bool isEmpty();
    bool isFull();
    bool push(int data);
    void pop();
    int& front();
    unsigned int size();

private:
    unsigned int _head, _tail, _size;
    unsigned int _maxSize;
    int *_data;
};




