double median(vector<int>& a, vector<int>& b) {
	int n=a.size();
	int m=b.size();
	if(n>m)return median(b,a);
	int sz=(n+m+1)/2;
	int low=0,high=n;
	while(low<=high){
		int mid=(low+high)/2;
		int mid2=sz-mid;
		double l1=(mid-1>=0)?a[mid-1]:INT_MIN;
		double l2=(mid2-1>=0)?b[mid2-1]:INT_MIN;
		double r1=(mid<n)?a[mid]:INT_MAX;
		double r2=(mid2<m)?b[mid2]:INT_MAX;
		if(l1<=r2 and l2<=r1){
			if((n+m)%2==0){
				double temp=max(l1,l2)+min(r1,r2);
				temp/=2.0;
				return temp;
			}
			else{
				return max(l1,l2);
			}
		}
		else
		if(l1>r2){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return 0.0;
}
