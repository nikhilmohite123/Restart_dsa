#include<iostream>
#include<string.h>
using namespace std;


bool match(string &s,int si,string &p,int pi){
    if(si==s.size() && pi==p.size()){
        return true;
    }


if(si==s.size() && pi<p.size()){
   while(pi<p.size()){
       if(p[pi]!='*')return false;
       pi++;
   }
   return true;
}
    if(s[si]==p[pi] || '?'==p[pi]){
        return match(s,si+1,p,pi+1);
    }


    if(p[pi]=='*'){

        // treate * is empty
        bool ans1=match(s,si,p,pi+1);


        // treate * is one elemnt
        bool ans2=match(s,si+1,p,pi);

        return ans1||ans2;
    }
    return false;
}

int main(){

string s="abcdf";
string p="abc*d?";
int si=0,pi=0;
match(s,si,p,pi)?cout<<"matching":cout<<"not Matching";
}
