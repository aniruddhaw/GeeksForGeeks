#include <iostream>
#include<string.h>
#include<cmath>
using namespace std;
void bubbleSort(int[],int);
int main() {
  int sumOfExp(string,int[]);
  int sum1[100],sum2[100];
  int normalize(int[],int);
  int tcs;
  cin>>tcs;
  for(int i=0;i<tcs;i++){
    int flag=1;
    string str1,str2;
    cin>>str1;
    cin>>str2;
    int size1 = sumOfExp(str1,sum1); 
    int size2 = sumOfExp(str2,sum2); 
    size1 = normalize(sum1,size1);
    size2 = normalize(sum2,size2);
    if(size1==size2){
      for(int i=0;i<size1;i++){
        if(sum1[i]!=sum2[i]){
          flag = 0;
          break;
        }
      }
    }
    else{
      flag=0;
    }
    if(flag==1){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }
  return 0;
}
int sumOfExp(string str1,int sum[]){
  int mul=1,flag=0,inc=0,sum2,ar[100],i=0;
  for(int j=0;j<str1.length();j++){
    
      if(str1[j]=='-'){
        mul = -1 * pow(-1,flag);
      }
      else if(str1[j]=='+'){
        mul = 1 * pow(-1,flag);
      }
      else if(str1[j]=='('){
        if(j-1>=0 && str1[j-1]=='-'){
          ar[inc] = -1;
          flag++;
          inc++;
        }
        else{
          ar[inc] = 1;
          inc++;
        }
        mul = 1 * pow(-1,flag);
      }
      else if(str1[j]==')'){
        inc--;
        if(ar[inc]==-1){
          flag--;
        }
      }
      else{
        sum2 = (mul * (int)str1[j]);
        sum[i]= sum2;
        
        i++;
        
      }
    }
    bubbleSort(sum,i);
    return i;
}
void bubbleSort(int sum[],int size){
  int temp;
    for(int i=0;i<size-1;i++){
      for(int j=0;j<size-i-1;j++){
        if(sum[j]>sum[j+1]){
          temp = sum[j];
          sum[j]=sum[j+1];
          sum[j+1]=temp;
        }
      }
    }
}
int normalize(int sum[],int n){
  int temp1,temp2,count=0,flag;
  for(int i=0;i<n;i++){
    flag=0;
    temp2=sum[i];
    if(temp2==0){
      continue;
    }
    for(int j=i+1;j<n;j++){
        temp1=sum[j];
        
      if(temp1==temp2 * (-1) && temp1!=0){
          sum[j]+=temp2;
          sum[i]+=temp1;
          flag=1;
          break;
      }
    }
    if(flag==0){
      sum[count]=temp2;
      count++;
    }
  }
  return count;
}