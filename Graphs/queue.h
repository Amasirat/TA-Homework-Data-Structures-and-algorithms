#ifndef QUEUE_H
#define QUEUE_H
template <typename T>
class Queue
{
public:
//Default Constructor
    Queue(int size);
//copy constructor
    Queue(const Queue& new_queue);
//Default Destructor
    ~Queue();
//Add item to Queue, returns 0 for success and -1 for failure
    void add(const T& element);
//free queue
    T free();
//see first element in Queue, returns reference to element
    T& top();
//see last element in Queue, returns reference to element
    T& end();
//returns amount of existing items in Queue
    int current_count() const;
//returns true if queue is empty
    bool is_empty() const;
//returns true if queue is full
    bool is_full() const;
private:
    T* m_queue{};
    int m_size{};
    int m_front{};
    int m_rear{};
};
#include "queue.inl"
#endif