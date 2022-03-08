#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class MaxHeap {
private:
    std::vector<T> data;
public:
    void push(const T& item);
    // Removes the largest element in the heap
    void pop();
    // Returns the largest element in the heap (but does not remove it)
    T const& top() const;
    std::size_t size() const;
};

template <typename T>
void MaxHeap<T>::push(const T& item) {
    data.push_back(item);
    std::size_t index = data.size() - 1;
    while (index != 0) {
        std::size_t parent_index = (index - 1) / 2;
        T& current = data[index];
        T& parent = data[parent_index];
        if (current <= parent) {
            break;
        }
        std::swap(current, parent);
        index = parent_index;
    }
}

template <typename T>
void MaxHeap<T>::pop() {
    if (data.empty()) {
        throw std::out_of_range("heap is empty");
    }

    // TO BE COMPLETETED

    T& itemRef = data[0];
    T& endRef = data[data.size() - 1];
    std::swap(itemRef, endRef);
    data.pop_back();

    size_t ind = 0;
    while (ind != data.size() - 1)
    {
        T& curr = data[ind];
        int left = (2 * ind) + 1;
        int right = (2 * ind) + 2;
        int next = -1;

        if (left < data.size() && right < data.size())
        {
            next = data[left] >= data[right] ? left : right; 
        }
        else if (left < data.size())
        {
            next = left;
        }
        else if (right < data.size()) 
        {
            next = right;
        }
        
        if (next == -1)
            break; 
        else if (curr > data[next])
            break;

   
        std::swap(curr, data[next]);
        ind = next;
    }
}

template <typename T>
T const& MaxHeap<T>::top() const {
    if (data.empty()) {
        throw std::out_of_range("heap is empty");
    }
    return data[0];
}

template <typename T>
std::size_t MaxHeap<T>::size() const {
    return data.size();
}
