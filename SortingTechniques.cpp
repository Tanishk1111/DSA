#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[],int n){
    /*
    - Comparisons => max = O(n^2)
                     min = O(n)
    - Swaps => max = O(n^2)
               min = O(1)
    - It is made Adaptive and Stable algorithm
    - No extra memory
    - Can be used for k-passes (like if you want to find two maximum numbers, run the loop twice)
    */

    int flag;
    for(int i = 0;i < n-1; i++){
        flag = 0;
        for(int j = 0; j < n-1-i; j++){
            if(A[j] > A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;

                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

void InsertionSort(int A[],int n){

    /*
    - Comparisons => max = O(n^2)
                     min = O(n)
    - Swaps => max = O(n^2)
               min = O(1)
    - It is Adaptive
    - It is stable
    - made for linked list
    */

    for(int i = 1;i < n; i++){
        int j = i-1;
        int x = A[i];
        while(j > -1 and A[j] > x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }

}

void SelectionSort(int A[],int n){

    /*
    - Comparison => O(n^2) {always}
    - Swaps => max = O(n)
               min = O(1)
    - Not Adaptive
    - Not Stable
    - Useful for k-passes (if you want to find like 2 minimum numbers, run the loop twice)
    */

    for(int i = 0;i < n-1; i++){
        int j,k;
        j = k = i;
        for(;j < n;j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

// First Element is Pivot, and using infinity ;
int partition(int A[],int l,int h){
    int pivot = A[l];
    int i = l,j = h;

    do{
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if(i < j){
            swap(&A[i],&A[j]);
        }

    }while(i<j);
    swap(&A[l],&A[j]);

    return j;

}

void QuickSort(int A[],int l,int h){
    
    /*
    - Comparison => min = O(nlogn)  {when partitioning is always done from middle};
                    max = O(n^2)    {when partitioning is done from first index or last index};
    - Swaps => O(log n) {my guess}
    - Not Adaptive
    - Not Stable
    */
    
    int j;
    if(l < h){
        j = partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

// Last Element is Pivot + without using INT_MAX or INFINITY :
int PartitionLast(int A[],int low,int high){
    int pivot = A[high];
    int i = low - 1;
    for(int j = low; j <= high-1; j++){
        if(A[j] < pivot){
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    return i+1;
     
}

void QuickSortLast(int A[], int low, int high){
    if(low < high){
        int p = PartitionLast(A,low,high);
        QuickSortLast(A,low,p-1);
        QuickSortLast(A,p+1,high);
    }
}

// Merge function :
void Merge(int A[],int l,int mid,int h){
    // O(m+n);
    int B[100];
    int i = l,j = mid+1,k = l;
    while(i <= mid and j <= h){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }

    for(;i <= mid; i++){
        B[k++] = A[i];
    }
    for(;j <= h; j++){
        B[k++] = A[j];
    }

    for(int i = l;i <= h;i++){
        A[i] = B[i]; 
    }
}

void IMergeSort(int A[],int n){
    // O(nlogn);
    int i,p,l,h,mid;
    for(p = 2; p <= n; p= p*2){
        for(i = 0; i+p-1 < n; i = i+p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2 < n){
        Merge(A,0,p/2-1,n-1);
    }
}

void MergeSort(int A[], int l,int h){
    // Time complexity = O(nlogn);
    // Space Complexity = O(n{for array} + logn{for stack});
    // the only comparison based sort that uses extra space
    if(l < h){
        int mid = (l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

// Count Sort :
int findMax(int A[], int n){
    int max = A[0];
    for(int i = 0; i < n; i++){
        if(max < A[i]){
            max = A[i];
        }
    }
    return max;
}

void CountSort(int A[],int n){
    // Time Complexity = O(n); Fastest index based sort;
    // Space Complexity = O(n); recommended if maximum element is not too big;
    int max = findMax(A,n);
    int *C = new int[max+1];
    for(int i = 0; i < max+1; i++){
        C[i] = 0;
    }
    for(int i = 0; i < n; i++){
        C[A[i]] ++;
    }
    int i = 0, j = 0;
    while(i < max + 1){
        if(C[i] > 0){
            A[j++] = i;
            C[i]--;
        }
        else{
            i++;
        }
    }

    delete [] C;
}


// Radix Sort :
class Node{
    public:
        int value;
        Node *next;
};

int Max(int A[],int n){
    int maxi = A[0];
    for(int i = 0; i < n; i++){
        if(A[i] > maxi){
            maxi = A[i];
        }
    }
    return maxi;
}

int CountDigit(int x){
    int count = 0;
    while(x!=0){
        x = x/10;
        count++;
    }
    return count;
}

void InitializeBins(Node **p, int n){
    for(int i = 0; i<n; i++){
        p[i] = NULL;
    }
}

void Insert(Node **ptrBins, int value, int idx){
    Node *t = new Node;
    t->value = value;
    t->next = NULL;
    if(ptrBins[idx] == NULL){
        ptrBins[idx] = t;
    }
    else{
        Node *p = ptrBins[idx];
        while(p->next != NULL){
            p = p->next;
        }
        p->next = t;
    }
}

int Delete(Node **ptrBins, int idx){
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

int getBinIndex(int x, int idx){
    return (int)(x/pow(10,idx))%10;
}

void RadixSort(int A[], int n){
    // O(dn) here d is like a constant so Radix Sort's time complexity is O(n);
    int maxi = Max(A,n);
    int npass = CountDigit(maxi);
    Node **bins = new Node*[10];
    InitializeBins(bins,10);
    for(int pass = 0; pass < npass; pass++){
        for(int i = 0; i < n; i++){
            int bindx = getBinIndex(A[i],pass);
            Insert(bins,A[i],bindx);
        }
        int i = 0,j = 0;
        while(i<10){
            while(bins[i]!=NULL){
                A[j++] = Delete(bins,i);
            }
            i++;
        }
        InitializeBins(bins,10);
    }
    delete [] bins;
}

// Shell Sort :
void ShellSort(int A[], int n){
    // O(nlogn) or O(n^(3/2)) or O(n^(5/3));
    int gap,i,j,temp;
    for(gap = n/2; gap >= 1; gap/=2){
        for(i = gap; i < n ; i++){
            temp = A[i];
            j = i-gap;
            while(j >= 0 and A[j] > temp){
                A[j+gap] = A[j];
                j-=gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main(){

    int A[] = {11,13,7,12,16,9,24,5,10,3};
    ShellSort(A,10);

    for(int i = 0; i < 10; i++){
        cout << A[i] << " ";
    }
    
    return 0;
}