#include <iostream>
#include<string>

using namespace std;


void permutaion(string &s,int position){
    if(position>=s.size()){
        cout<<s<<" "<<endl;
        return;
    }


    for(int j=position; j<s.size(); j++){
        swap(s[position],s[j]);
        
        permutaion(s,position+1);

    //  bactrack
        swap(s[position],s[j]);
        
       
    }
}



int main() {
    string s="abc";
    permutaion(s,0);
    
}
