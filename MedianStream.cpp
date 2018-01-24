#include<iostream>
#include<vector>
using namespace std;

long binarySearch(vector<long>& arr,long key,long first,long last){
 long mid = first+(last-first)/2;
	
	if(first<last){
		if(key>=arr.at(mid) && key<=arr.at(mid+1)){
			return mid+1;
		}
		else if(key>arr.at(mid)){
			first = mid+1;
			return binarySearch(arr,key,first,last);
		}
		else if(key<arr.at(mid)){
			last = mid;
			return binarySearch(arr,key,first,last);
		}
		
	}
}

int main(){
	long n,key,i,j,median,pos,num;
	cin>>n;
	vector<long> arr;
	vector <long> :: iterator x;
	for(long k=0;k<n;k++){
		cin>>num;
		if(k==0){
		  arr.insert(arr.begin(),num);
		  cout<<num<<"\n";
		  continue;
		}
		else if(num<=arr.at(0)){
		  pos=0;
		}
		else if(num>=arr.at(k-1)){
		  pos = k;
		}
		else if(k==1){
		  pos=1;
		}
		else{
		  pos = binarySearch(arr,num,0,k-1);
		}
		
		arr.insert(arr.begin()+pos,num);
		
	   key=(k+1)/2;
		if((k+1)%2==0){
		  median = (arr.at(key)+arr.at(key-1))/2;
		}
		else{
		  median = arr.at(key);
		}
		cout<<median<<"\n";
	}
	
	return 0;
}

