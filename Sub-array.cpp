#include <stdio.h>
#include<iostream>
using namespace std;
typedef long long int li;
int main() {
	//code
	int tcs;
	cin>>tcs;
	for(int i=0;i<tcs;i++){
	    li num,k,count=0,temp,j,x=0,mul;
	    
	    mul=1;
	    cin>>num;
	    cin>>k;
	    li ar[num];
	    for(j=0;j<num;j++){
	        cin>>ar[j];
	        mul*=ar[j];
	        while(j<num){
    	           if(mul>=k){
    	            count+=(j-x);
    	            mul/=ar[x];
    	            x++;
    	            
    	            if(j<x){
    	                break;
    	            }
    	        }
    	        else{break;}
	        }
	   }
	   temp = (j-x);
	   count+= (temp * (temp+1)/2);
	   cout<<count<<"\n";
	}
	return 0;
}