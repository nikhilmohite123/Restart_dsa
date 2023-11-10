#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& a,int s,int e){
    int m=(s+e)/2;
    int l1=m-s+1,l2=e-m;
    int *left=new int(l1);
    int *right=new int(l2);

    int j=s;

    // copy left side of array
    for(int i=0; i<l1;i++){
   left[i]=a[j++];
    }
j=m+1;
// copy right side of array
    for(int i=0; i<l2; i++){
        right[i]=a[j++];
    }
int i=0;
j=0;
int x=s;
while(i<l1 && j<l2){
    if(left[i]<right[j]){
        a[x++]=left[i++];
    }
    else{
        a[x++]=right[j++];
    }
}
while(i<l1){
    a[x++]=left[i++];
}

while(j<l2){
    a[x++]=right[j++];
}

delete [] left;
delete [] right;

}


void mergeSort(vector<int>& a,int s,int e){
    if(s>=e){
        return;
    }
    int m=(s+e)/2;
    mergeSort(a,s,m);
    mergeSort(a,m+1,e);
    merge(a,s,e);
}


int main(){
    vector<int>a={5,2,3,1,9,2,1};
      int s=0,e=a.size()-1;
       for(int i=0; i<=e; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    mergeSort(a,s,e);
    for(int i=0; i<=e; i++){
        cout<<a[i]<<" ";
    }
}