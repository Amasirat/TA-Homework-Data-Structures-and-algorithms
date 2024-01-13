#include <iostream>
#include <vector>
// this MaxHeap Data Structure is implemented using the Dynamic Array Data Structure
class MaxHeap
{
public:
//default Constructor
    MaxHeap(int root_data) {m_array.push_back(root_data);}
// Default Destructor
    ~MaxHeap() = default;
// Insert into MaxHeap
    void insert(int data);
// delete maximum from MaxHeap and return it
    int extract_max();
// return max without deletion
    int max() const;
// if a number is in heap
    bool is_in_heap(int num) const;
private:
    std::vector<int> m_array{};
// standard swap algorithm for integers
    void swap(int& x, int& y)
    {
        x = x + y;
        y = x - y;
        x = x - y;
    }
    // return index containing maximum number
    int max(int index1, int index2)
    {
        if(m_array[index1] > m_array[index2])
            return index1;
        else
            return index2;
    }
// recursive method to reheap downwards the MaxHeap structure
    void heap_down(int index)
    {
        int left_child{ 2 * index + 1};
        int right_child{ 2 * index + 2};
        int max = index;

        if(left_child < m_array.size() && m_array.at(left_child) > m_array.at(max))
        {
            max = left_child;
        }
        
        if(right_child < m_array.size() && m_array.at(right_child) > m_array.at(max))
        {
            max = right_child;
        }

        if(max != index)
        {
            swap(m_array.at(max), m_array.at(index));
            heap_down(max);
        }
    }
// recursive method to reheap upwards the MaxHeap structure
    void heap_up(int index)
    {
        if(index <= 0) return;
        int p_index{(index - 1) / 2};
        if(m_array.at(index) > m_array.at(p_index))
        {
            swap(m_array.at(index), m_array.at(p_index));
            heap_up(p_index);
        }
    }
};