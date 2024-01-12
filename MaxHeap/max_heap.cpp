#include <iostream>
#include <vector>
#include "max_heap.h"
// Insert into MaxHeap
    void MaxHeap::insert(int data)
    {
        m_array.push_back(data);
        re_heap();
    }
// delete maximum from MaxHeap and return it
    int MaxHeap::extract_max()
    {
        int max{m_array.at(0)};
    
        int index{0};
        int child{2};
        //this loop is for swapping the root key with one of the right subtree's leaf
        while(child >= m_array.size())
        {
            swap(m_array[child], m_array[index]);         
            index = child;
            child = 2*index;
        //if there is no right child
            if(child + 2 == m_array.size())
            {
                child += 1;//rightmost left child
            }
            else
            {
                child += 2;//rightmost right child
            }
        }
        // Now we get the root key to the right most leaf
        for(int i{index}; i < m_array.size() - 1; ++i)
        {
            swap(m_array.at(i), m_array.at(i + 1));
        }
//now we delete the last leaf containing prior root key safely and re_heap
        m_array.pop_back();
        re_heap();
        return max;
    }
// return max without deletion
    int MaxHeap::max() const
    {
        return m_array.at(0);
    }
// sort the MaxHeap
    void MaxHeap::re_heap()
    {
        int p_index{};//index of parent in MaxHeap
        int i{m_array.size() - 1};
        while(i > 0)
        {
            p_index = (i - 1) / 2;
            if(m_array.at(i) > m_array.at(p_index))
            {
                swap(m_array.at(i), m_array.at(p_index));
                i = p_index;
            }
            else 
            {
                i--;
            }
        }
    }


int main()
{
    MaxHeap nums{10};
    nums.insert(5);
    return 0;
}