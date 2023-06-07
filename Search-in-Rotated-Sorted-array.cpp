int pivot(int *arr,int n){
    int l=0,r=n-1;
    if(arr[0]<arr[n-1])return 0;
    while(l<r){
        int mid=(l+r)/2;
        if(arr[l]<arr[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }

    }
    return l;
}
int search(int* arr, int n, int key) {
    int low = 0;
    int high = n - 1;
    while (low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==key)return mid;
        if(arr[low]<=arr[mid]){ 
            if(key>=arr[low] && key<=arr[mid])
                high=mid-1;
            else
                low=mid+1;

        }else{
            if(key>arr[mid] && key<=arr[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return -1;
}
