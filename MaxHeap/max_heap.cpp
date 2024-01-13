#include <iostream>
#include <vector>
#include "max_heap.h"
// Insert into MaxHeap
void MaxHeap::insert(int data)
{
    if(is_in_heap(data)) return;
    m_array.push_back(data);
    heap_up((int)m_array.size() - 1);
}
// delete root from MaxHeap and return it
int MaxHeap::extract_max()
{
    int max{m_array.at(0)};
    
    int index{0};
    int child{2};
//this loop is for swapping the root key with one of the right subtree's leaf
    while(child <= m_array.size())
    {
        swap(m_array[child], m_array[index]);         
        index = child;
        child = 2*index;
        //if there is no right child but there is a left child
        if(child + 2 == m_array.size())
        {
            child += 1;//rightmost left child
        }
        else if(child + 2 < m_array.size())
        {
            child += 2;//rightmost right child
        }
    }
//now we delete the last leaf containing prior root key safely and reheap from top to bottom
    m_array.pop_back();
    heap_down(0);
    return max;
}
// return max without deletion
int MaxHeap::max() const
{
    return m_array.at(0);
}

// if a number is in heap
bool MaxHeap::is_in_heap(int num) const
{

    for(auto num_in_array : m_array)
    {
        if(num == num_in_array)
            return true;
    }
    return false;
}

int main()
{
    MaxHeap nums{10};
    nums.insert(5);
    nums.insert(6);
    nums.insert(7);
    nums.insert(2);
    return 0;
}