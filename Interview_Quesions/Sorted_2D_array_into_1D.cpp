
// Input: mat[][]  =  { {10, 20, 30, 40},
//                      {15, 25, 35, 45},
//                      {27, 29, 37, 48},
//                      {32, 33, 39, 50},
//                    };

// Output:
// Elements of matrix in sorted order
// 10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50
// // A C++ program to Print all elements in sorted order from row and
// // column wise sorted matrix


#include<iostream>
#include<climits>
using namespace std;
 
#define INF INT_MAX
#define N 4
 
// A utility function to youngify a Young Tableau.  This is different
// from standard youngify.  It assumes that the value at mat[0][0] is
// infinite.
void youngify(int mat[][N], int i, int j)
{
    // Find the values at down and right sides of mat[i][j]
    int downVal  = (i+1 < N)? mat[i+1][j]: INF;
    int rightVal = (j+1 < N)? mat[i][j+1]: INF;
 
    // If mat[i][j] is the down right corner element, return
    if (downVal==INF && rightVal==INF)
        return;
 
    // Move the smaller of two values (downVal and rightVal) to
    // mat[i][j] and recur for smaller value
    if (downVal < rightVal)
    {
        mat[i][j] = downVal;
        mat[i+1][j] = INF;
        youngify(mat, i+1, j);
    }
    else
    {
        mat[i][j] = rightVal;
        mat[i][j+1] = INF;
        youngify(mat, i, j+1);
    }
}
 
// A utility function to extract minimum element from Young tableau
int extractMin(int mat[][N])
{
    int ret = mat[0][0];
    mat[0][0] = INF;
    youngify(mat, 0, 0);
    return ret;
}
 
// This function uses extractMin() to print elements in sorted order
void printSorted(int mat[][N])
{
   cout << "Elements of matrix in sorted order n";
   for (int i=0; i<N*N; i++)
     cout << extractMin(mat) << " ";
}
 
// driver program to test above function
int main()
{
  int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
  return 0;
}

//Solutionn 2
// C++ program to merge k sorted arrays of size n each.
#include<iostream>
#include<climits>
using namespace std;
 
#define N 4
 
// A min heap node
struct MinHeapNode
{
    int element; // The element to be stored
    int i; // index of the row from which the element is taken
    int j; // index of the next element to be picked from row
};
 
// Prototype of a utility function to swap two min heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);
 
// A class for Min Heap
class MinHeap
{
    MinHeapNode *harr; // pointer to array of elements in heap
    int heap_size; // size of min heap
public:
    // Constructor: creates a min heap of given size
    MinHeap(MinHeapNode a[], int size);
 
    // to heapify a subtree with root at given index
    void MinHeapify(int );
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to get the root
    MinHeapNode getMin() { return harr[0]; }
 
    // to replace root with new node x and heapify() new root
    void replaceMin(MinHeapNode x) { harr[0] = x;  MinHeapify(0); }
};
 
// This function prints elements of a given matrix in non-decreasing
//  order. It assumes that ma[][] is sorted row wise sorted.
void printSorted(int mat[][N])
{
    // Create a min heap with k heap nodes.  Every heap node
    // has first element of an array
    MinHeapNode *harr = new MinHeapNode[N];
    for (int i = 0; i < N; i++)
    {
        harr[i].element = mat[i][0]; // Store the first element
        harr[i].i = i;  // index of row
        harr[i].j = 1;  // Index of next element to be stored from row
    }
    MinHeap hp(harr, N); // Create the min heap
 
    // Now one by one get the minimum element from min
    // heap and replace it with next element of its array
    for (int count = 0; count < N*N; count++)
    {
        // Get the minimum element and store it in output
        MinHeapNode root = hp.getMin();
 
        cout << root.element << " ";
 
        // Find the next elelement that will replace current
        // root of heap. The next element belongs to same
        // array as the current root.
        if (root.j < N)
        {
            root.element = mat[root.i][root.j];
            root.j += 1;
        }
        // If root was the last element of its array
        else root.element =  INT_MAX; //INT_MAX is for infinite
 
        // Replace root with next element of array
        hp.replaceMin(root);
    }
}
 
// FOLLOWING ARE IMPLEMENTATIONS OF STANDARD MIN HEAP METHODS
// FROM CORMEN BOOK
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
// A utility function to swap two elements
void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;  *x = *y;  *y = temp;
}
 
// driver program to test above function
int main()
{
  int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
  return 0;
}
