#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){
        // this->data=0;
        this->next=NULL;
    }
    Node(int data){
      this->data=data;
      this->next=NULL;
    }
    ~Node(){
        
        delete next;
    }
};

void inserAtHead( Node *&Head,Node *&Tail,int data){
//   empty ll
  if(Head==NULL){
  Node *newNode=new Node(data);
  
  Head=newNode;
  Tail=newNode; 
  return;
  }
  Node *newNode=new Node(data);
  newNode->next=Head;
  Head=newNode;
 
}

void inserAtTail(Node *&Head,Node *&Tail,int data){

    if(Head==NULL){
        Node *newNode=new Node(data);
        Head=newNode;
        Tail=newNode;
        return;
    }
    if(Head->next==NULL){
         Node *newNode=new Node(data);
         Head->next=newNode;
         Tail=newNode;
         return;
    }
    Node *newNode=new Node(data);
    Tail->next=newNode;
    Tail=newNode;

}



int length(Node*Head){
    Node *temp=Head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
       temp= temp->next;
    }
    return cnt;
}

void inserAtPosition(Node *&Head, Node *&Tail,int data,int position){

 int len=length(Head);
//   if(len<position){
//     return;
//      }
 
   if(position==1){
     inserAtHead(Head,Tail,data);
     return;
   }
 if(position==len-1){
     inserAtTail(Head,Tail,data);
     return;
 }
int cnt=1;
Node *prev=Head;

while(cnt<position-1 && prev->next!=NULL){
prev=prev->next;
cnt++;
}

  Node *newNode=new Node(data);
  newNode->next=prev->next;
  prev->next=newNode;


}


void deleteAtHead(Node *&Head,Node *&Tail){
    if(Head==NULL){
        return;
    }
    Node *temp=Head;
    Head=Head->next;
    
    temp->next=NULL;
    delete temp;
   

}

void deleteAtTail(Node *&Head,Node *&Tail){
    if(Head==NULL){
        return;
    }
    int len=length(Head);
    

    Node *prev=Head;
    int cnt=1;
    while(cnt<len-1){
        prev=prev->next;
        cnt++;
    }
    
   Node *temp=Tail;
   prev->next=NULL;
   Tail=prev;
   delete temp;
}

void deleteAtPosition(Node *&Head,Node *&tail,int pos){
    int len=length(Head);
    if(len<=pos){
        deleteAtTail(Head,tail);
        return;
    }
    if(pos==1){
        deleteAtHead(Head,tail);
   return;
    }


    Node *prev=Head;
    int cnt=1;
     while(cnt<pos-1){
         cnt++;
         prev=prev->next;
     }
     
     Node *curr=prev->next;
     prev->next=prev->next->next;
     curr->next=NULL;
     delete curr;

}


void print(Node *Head){
    Node *temp=Head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){


 Node *Head=NULL;
 Node *Tail=NULL;
     

     inserAtHead(Head,Tail,5);
     inserAtHead(Head,Tail,4);
     inserAtTail(Head,Tail,6);
     inserAtHead(Head,Tail,3);
     inserAtHead(Head,Tail,2);
     inserAtHead(Head,Tail,1);
     

   

     print(Head);

    //  inserAtPosition(Head,Tail,999,8);
     deleteAtPosition(Head,Tail,99);
     print(Head);
}