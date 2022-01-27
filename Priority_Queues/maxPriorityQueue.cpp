Code : Max Priority Queue

Implement the class for Max Priority Queue which includes following functions -

1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.

2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.

3. insert -
Given an element, insert that element in the priority queue at the correct position.

4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.

5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.

Note : main function is given for your reference which we are using internally to test th
e class.



#include<vector>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        
        int ci=pq.size()-1;
      while(ci > 0) {  
        int pi=(ci-1) / 2;
        
        if(pq[pi] < pq[ci]) {
            pq[pi]= pq[pi] ^ pq[ci];
            pq[ci]= pq[pi] ^ pq[ci];
            pq[pi] =pq[pi] ^ pq[ci];
        } else // heap order property satifies
        {
            break;
        }
        
        ci = pi;
    }
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size() == 0) {
            return 0;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        if(pq.size() == 0) {
            return -1;
        }
        
        int removed=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        
        int pi=0;
        
        while(pi < pq.size()) // if 6 element then idx 0 -> 5
        {
        int lci=(2*pi) + 1;
        int rci=(2*pi) + 2;
        int minI = 0;
        
        if(lci>=pq.size())  // if 6 element then idx 0 -> 5
        {
            break;
        } else {
            if(rci>=pq.size()) {
                minI=lci;
            }
        }
      
        if(pq[lci] > pq[rci]) {
            minI = lci;
        } else {
            minI = rci;
        }
        
        if(pq[pi] < pq[minI]) {
            pq[pi]=pq[pi]^pq[minI];
            pq[minI]=pq[pi]^pq[minI];
            pq[pi]=pq[pi]^pq[minI];
        } else // heap order property satisfies
        {
            break;
        }
        
        pi=minI;
    }
    return removed;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};


