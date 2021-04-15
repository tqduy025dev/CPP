#include<iostream>
using namespace std;



int search(int a[], int n, int x){
	
	int l = 0, r = n-1;
	//int mid = (l+r)/2;       /////////////////
	while(l<=r){
		int mid = (l+r)/2; 
		if(a[mid] == x){
			return 1000;
		}else 
		if(x>a[mid]){
			l = mid +1;
		}else{
			r = mid -1;
		}
	}
	return 0;
}

void swap(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void print(int a[], int n){
	for(int i = 0;i<n; i++){
		cout<<a[i]<<" ";
	}
}


void bupple_sort(int a[], int n){
	for(int i = 0;i<n-1;i++){
		for(int j = n-1; j>i; j--)
			if(a[j]<a[j-1]){
				swap(a[j], a[j+1]);
			}
	}
}	

void selection_sort(int a[], int n){
	for(int i = 0;i<n-1;i++){
		for(int j = i+1; j<n; j++){
			if(a[j]<a[i]){
				swap(a[j],a[i]);
			}
		}
	}
}

void insertion_sort(int a[], int n){
	
    int key, j;
    for (int i = 1; i < n; i++){ 
        key = a[i];
        j = i - 1;  
        while ( a[j] > key && j >=0){
            a[j + 1] = a[j];  
            j--;  
        }  
        a[j + 1] = key;  
    }  
}




int partition (int a[], int low, int high)
{
    int pivot, index;
	index = low;
	pivot = high;
	
	for(int i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
	swap(&a[pivot], &a[index]);
 
	return index;	
}

int quick_sort(int a[], int low, int high){
	if(low<high){
	int pi = partition(a, low, high);
	quick_sort(a, low, pi - 1);
    quick_sort(a, pi + 1, high);
	}
}


void ImplMerge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 =  right - mid;
 
    int* L = new int[n1];
    int* R = new int [n2];
 
    for (int x = 0; x < n1; x++)
        L[x] = arr[left + x];
    for (int y = 0; y < n2; y++)
        R[y] = arr[mid + 1+ y];
 
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = left +(right -left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        ImplMerge(arr, left, mid, right);
    }
}

void ImplHeapify(int arr[], int n, int i){
  int root = i;
  int l = 2*i + 1;  // left position = 2*i + 1
  int r = 2*i + 2;  // right position = 2*i + 2
 
  // If left child is larger than root
  if (l < n && arr[l] > arr[root])
    root = l;
 
  // If right child is larger than largest so far
  if (r < n && arr[r] > arr[root])
    root = r;
 
  // If root position is not largest value
  if (root != i){
    swap(arr[i], arr[root]);
    ImplHeapify(arr, n, root);
  }
}
 
void ImplHeapSort(int arr[], int n){
  for (int i = (n/2) - 1; i >= 0; i--){
	ImplHeapify(arr, n, i);
  }
 
  for (int i = n-1; i >= 0; i--){
    swap(arr[0], arr[i]);
    ImplHeapify(arr, i, 0);
  }
}


int main(){
	int n = 10;
	int a[] = {5,2,3,7,8,9,17,6,10,1};
	
//	bupple_sort(a,n);
	selection_sort(a,n);	
//	insertion_sort(a,n);
//	quick_sort(a,0,n-1);
//	mergeSort(a,0,n-1);
//	ImplHeapSort(a,n);
	print(a,n);
	
	cout<<search(a,n, 1);

	
	
}
