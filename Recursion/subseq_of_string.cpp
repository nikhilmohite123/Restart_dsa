#include<iostream>
#include<string.h>
using namespace std;


void subseq(string &s,string op,int i){

if(i==s.size()){
    cout<<op<<endl;
    return;
}


// include
subseq(s,op+s[i],i+1);

// exclude
subseq(s,op,i+1);

}




int main(){
string s="xyz";
string op="";
int i=0;
subseq(s,op,i);




    return 0;
}