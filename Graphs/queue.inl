#include "queue.h"
template <typename T>
//default constructor
Queue<T>::Queue(int size) : 
m_size{size}, m_front{-1}, m_rear{-1}
{
    m_queue = new T[size];
}
template <typename T>
//copy constructor
Queue<T>::Queue(const Queue<T>& new_queue) : 
m_front{new_queue.m_front}, 
m_rear{new_queue.m_rear},
m_size{new_queue.m_size}
{
    m_queue = new T[m_size];
    if(!(new_queue.is_empty()))
    {
        for(int i{m_front}; i % m_size != m_rear + 1; ++i)
        {
            int index{i % m_size};
            m_queue[index] = new_queue.m_queue[index];
        }
    }
}
template <typename T>
//Default Destructor
Queue<T>::~Queue()
{
    delete[] m_queue;
}
//Add item to Queue, !!can throw int exception!!
template <typename T>
void Queue<T>::add(const T& element)
{
    if(is_empty())
    {
        m_front = 0;
        m_rear = 0;
    }
    else if(is_full())
    {
        throw -1;
    }
    else
    {
        m_rear = (m_rear + 1) % m_size;
    }

    m_queue[m_rear] = element;
}
template <typename T>
//free first item in queue
T Queue<T>::free()
{
    if(is_empty())
        throw "queue is empty";

    if(m_front == m_rear)
    {
        T returning_element{m_queue[m_front]};
        m_front = -1;
        m_rear = -1;
        return returning_element;
    }
    else
    {
        T returning_element { m_queue[m_front] };
        m_front = (++m_front) % m_size;
        return returning_element;
    }
}
template <typename T>
//see first element in Queue
T* Queue<T>::top()
{
    if(is_empty())
        return nullptr;

    return &m_queue[m_front]; 
}
template <typename T>
//see last element in Queue
T* Queue<T>::end()
{
    if(is_empty())
        return nullptr;
    
    return &m_queue[m_rear]; 
}
template <typename T>
//returns amount of existing items in Queue
int Queue<T>::current_count() const
{
    int count{};
    if(is_empty())
        count = 0;
    else if(is_full())
        count = m_size;
    else
        count = 0;
    //m_rear + 1 is for counting the element inside m_rear as well
        for(int i{m_front}; i % m_size != (m_rear + 1); ++i)
            ++count;
                 
    return count;
}
template <typename T>
//returns true if queue is empty
bool Queue<T>::is_empty() const
{ return m_front == -1 && m_rear == -1; }
template <typename T>
//returns true if queue is full
bool Queue<T>::is_full() const
{ return (m_rear + 1) % m_size == m_front; }