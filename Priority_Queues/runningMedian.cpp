Running Median

You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.

Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.

Output Format :
Print the running median for every integer added to the running list in one line (space-separated).

Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec

Sample Input 1 :
6
6 2 1 3 7 5

Sample Output 1 :
6 4 2 2 3 4

Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

Sample Input 2 :
5
5 4 3 2 1

Sample Output 2 :
5 4 4 3 3

#include<queue>
#include<vector>
void findMedian(int *arr, int n)
{
    priority_queue<int> max;
    priority_queue<int ,vector<int>, greater<int>> min; // min priority queue

    int i=0;
   int num=0; // currently the stream is empty

    while(i<n) {

        if(i==0){
            max.push(arr[i]);
            cout << max.top() << " ";
            num++; // stream of integer equals to 1.
             i++;
            continue;
        }

        if(arr[i]<max.top()) {
            max.push(arr[i]);
            num++;
        } else {
            min.push(arr[i]);
            num++; // integer in the stream increases as we r pushing the value
        }

        if(num%2==0)  // stream is even
        {
            // if max.size() == min.size() then it means in even stream no. equally distributed.
            if(max.size() > min.size()) {
                int no=max.top();
                max.pop();
                min.push(no);
            }

            if(max.size() < min.size()) {
                 int no=min.top();
                min.pop();
                max.push(no);
            }
        }
     // if stream is even but no r not equally distributed then this will help to equal the no. in both the heaps

        // printing the median of running stream.
        if(max.size() == min.size())  // this case comes only when stream is even
        {
           int ans = (max.top() + min.top()) / 2;
            cout << ans << " ";
            } else if(max.size() < min.size()) {
                cout<<min.top()<<" ";
            } else {
                cout<<max.top()<<" ";
            }

        i++;
    }

}
