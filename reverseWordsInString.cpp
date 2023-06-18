string reverseString(string &str){
	int i=0,j=0;
	if(str.size()==0)return str;
	while(str.back()==' ')str.pop_back();
	if(str.size()==0)return "";
	int n=str.length();
	while(j<n and str[j]==' ')j++;
	int ok=-1;
	while(j<n){
		if(str[j]==' '){
			if(ok==-1){
				ok=1;
				str[i]=str[j];
				i++;
				j++;
			}
			else{
				j++;
			}
		}
		else{
			ok=-1;
			str[i]=str[j];
			i++;
			j++;
		}
	}
	while(str.size() and str.size()>i)str.pop_back();
	int c=0;
	for(auto it:str){
		if(it==' '){
			c++;
		}
	}
	if(c==0)return str;
	reverse(str.begin(),str.end());
	int prev=0;
	int sz=0;
	for(int i=0;i<str.size();i++){
		if(str[i]==' '){
			reverse(str.begin()+prev,str.begin()+prev+sz);
			sz=0;
			prev=-1;
		}
		else{
			if(prev==-1){
				prev=i;
			}
			sz++;
		}
	}
	reverse(str.begin()+prev,str.begin()+prev+sz);
	sz=0;
	prev=-1;
	return str;
		
}
