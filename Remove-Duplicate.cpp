int removeDuplicates(vector<int> &arr, int n) {
	int idx=0;
	int j=0;
	for(int i=1;i<n;i++){
		if(arr[i]==arr[idx]){
			continue;
		}
		else{
			idx++;
			arr[idx]=arr[i];
		}
	}
	return idx+1;
}
