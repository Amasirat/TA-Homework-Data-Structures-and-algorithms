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
// sort the MaxHeap
    void re_heap();

    void print()
    {
        for (auto element : m_array)
        {
            std::cout << element << " ";
        }
        std::cout << '\n';
    }
private:
    std::vector<int> m_array{};
// standard swap algorithm for integers
    void swap(int& x, int& y)
    {
        x = x + y;
        y = x - y;
        x = x - y;
    }
};