#include "stones.h"
#include "max_heap.h"

int lastStoneWeight(std::vector<int>& stones) {
    MaxHeap<int> heap;
    int maxStone; 

    if (stones.size() < 1)
        return 0;
    
    // TO BE COMPLETED
    for(int i = 0; i < stones.size(); i++)
    {
        heap.push(stones[i]);
    }

    while(heap.size() > 1)
    {
        int x = heap.top();
        if(heap.size() < 2)
            break;

        heap.pop();
        int y = heap.top();

        if( x != y )
        {
            x -= y;

            heap.pop();
            heap.push(x);
        } 
        else {
            if (heap.size() < 2)
                return x - y;
            heap.pop();
        }
    }
    return heap.top();
}
