Code : Remove Min

Implement the function RemoveMin for the min priority queue class.

For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.

Note : main function is given for your reference which we are using internally to test the code.

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        if(pq.size() == 0) {
            return -1;
        }
        
        int removed = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        
        int pi = 0;
      while(pi< pq.size())   // if 6 element then total idx is 0 -> 5
      {  
        int lci= (2 * pi) + 1;
        int rci= (2 * pi) + 2;
        int minIdx = 0;
        
        if(lci >= pq.size())  // if 6 element then total idx is 0 -> 5 
        {
            break;
        } else {
            if(rci>=pq.size()) {
                minIdx=lci;
            } 
        }
        
        if(pq[lci] > pq[rci]) {
            minIdx = rci;
        } else {
            minIdx = lci; 
        }
        
        if(pq[pi] > pq[minIdx]) {
            pq[pi] =pq[pi]^pq[minIdx];
            pq[minIdx] =pq[pi]^pq[minIdx];
            pq[pi] =pq[pi]^pq[minIdx]; 
        } else {
            break;
        }
        
        pi=minIdx;
    }
        return removed;
    }
};

