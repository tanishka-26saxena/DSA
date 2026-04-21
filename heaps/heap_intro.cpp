#include <iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

// heaps are complete binary trees with heap order property
// two kinds of heaps are : min heap and max heap
// in a min heap all the child nodes will have a value greater than parent node
// in a max heap all the child nodes will have a value smaller than parent node

class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // when indexing is 1-based , if root node is at i-th index then,
    // left child will always be at 2*i index
    // right child will always be at (2*i+1) index
    // parent will be always at i/2th index if any child is at i-th index

    //when indexing is 0-based, if root node is at i-th index then,
    // left child will always be at (2*i +1) index
    // right child will always be at (2*i+2) index

    // insertion 2 steps m hoga
    // step 1: phle end m us value ko store kra lo
    // step 2: dusre step m values swap krao parent node ke sath conditions check krke ki agar
    // min heap h too check kro ki uska parent node usse chhota h ya nhi aur agar nhi h to usse bas swap kra do
    // similarly max heap ke liye check kro ki uska parent node usse badha h ya nhi h agar nhi h to usse swap kra do
    
    void insert(int val)
    {
        size+=1;
        int index = size;
        arr[index] = val;

        while(index > 1)
        {
            int parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }

    void print()
    {
        int n = 0;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
            if (i == pow(2, n + 1) - 1)
            {
                cout << endl;
                n++;
            }
        }
        cout<<endl;
    }

    // deletion ke liye
    // step 1: put value of last node in place of the node to be deleted
    // step 2: delete the node that has to be deleted
    // step 3 : take the swapped value to its right position

    void delete_from_heap()
    {
        
        if (size == 0)
        {
            cout << "no node to delete" << endl;
            return;
        }
        //step 1: putting last element to its correct position
        arr[1] = arr[size];

        //step 2: removing the last node 
        size--;

        //step 3:  taking root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = (2 * i) + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
                
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

};
    //HEAPIFY ALGORITHM:
    //ek complete binary tree mai leaf nodes ((n/2)+1) index se n-index tak hoti haii
    //heapify algorithm har index ki node ko check kia jata hai ki wo heap(min or max) haii ya nhi
    //agar koi node heap nhi hoti hai to use uski shi position par le kar jate hai ....this is only called heapify algorithm
    //hence taking a node to its correct position is what is called heapify
    //so in a complete binary tree check ((n/2)+1) se n-th node tak process krne ki zarurat hi nhi hoti h

    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left <= n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if(right <= n && arr[largest] < arr[right])
        {
            largest = right;
        }

        if(largest != i)
        {
            swap(arr[largest] , arr[i]);
            heapify(arr, n, largest);
        }
    }


    //HEAP SORT
    //for maxheap:
    //last element jo bhi hoga usko first element se swap kr do aur array ka size 1 kam kr do ..
    //in short swapping ke baad last element ko hta do
    // aur swapped element ko uski shi position par le aao
    //e.g.-> arr={70, 60, 55, 45, 50}
    //after swapping, moving it to its correct place, and removing last node:
    //arr= {60, 50, 55, 45} aur sorted array bna kar store krte jao use sorted_arr = {70}
    //yhi steps repeat krenge to 
    //arr = {55,50,45} and sorted_arr = {60, 70}
    //arr = {50,45} and sorted_arr = {55, 60, 70}
    //arr = {45} and sorted_arr = {50, 55, 60, 70}
    //arr = {} and sorted_arr = {45, 50, 55, 60, 70}

    //algo:
    //step ->1 : swap a[i],a[n]
    //step-> 2: move a[i] to its correct position by heapifying it
    //step-> 3: remove the last node and add it to a new array that will be sorted


    //heap sort time complexity : O(n log n) 
    void heapSort(int arr[] , int n)
    {
        int t = n;

        while(t > 1)
        {
            //step 1: swap
            swap(arr[t], arr[1]);

            //step 3: removal
            t--;

            //step 2:heapifying it 
            heapify(arr, t, 1);
        }
    }


int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(49);
    h.insert(56);
    h.insert(58);
    h.print();

    cout<<"deleted node"<<endl;
    h.delete_from_heap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};

    int n=5;
    for(int i=n/2; i>0 ; i--)
    {
        heapify(arr, n, i);
    }

    cout<<"printing the array after heapifying it"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr , n);

    cout<<"printing the array after heap sort"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    //PRIORITY QUEUE----- 
    //directly priority queue se bhi bna skte hain

    cout<<"using priority queue here"<<endl;

    //max heap :
    priority_queue<int> max_pq;

    max_pq.push(4);
    max_pq.push(5);
    max_pq.push(2);
    max_pq.push(3);

    cout<<"element at top is : "<<max_pq.top()<<endl;
    cout<<"size of maax heap is: "<<max_pq.size()<<endl;

    //min heap
    priority_queue<int , vector<int>, greater<int>> min_pq;

    min_pq.push(4);
    min_pq.push(5);
    min_pq.push(2);
    min_pq.push(3);

    cout<<"element at top is : "<<min_pq.top()<<endl;
    cout<<"size of maax heap is: "<<min_pq.size()<<endl;

    return 0;
}
