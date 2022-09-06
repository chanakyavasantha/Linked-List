#include<bits/stdc++.h>
using namespace std;


//class of Node
class Node{
public:
    int data;
    Node* next = NULL;
}*head = NULL,*tail = NULL;
//utility function to create a Node
Node* newNode(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}
//Insert function without any  positional arguments will act as insert at beignning
void Insert(int x){
    Node* temp = newNode(x);
    if(head == NULL){
        head = temp;
        tail = temp;
        temp->next = head;
        return;
    }
    temp->next = head;
    head = temp;
    tail->next = head;
}
//insert function with positional arguments will act as insertion at some position
void Insert(int x,int pos){
    if(pos == 0){
        Insert(x);
        return;
    }
    Node* temp = newNode(x);
    Node* temp1 = head;
    pos -=1;
    while(pos--){
        if(temp1 == tail){
            cout<<"The given index is out of bound"<<endl;
            return;
        }
        temp1 = temp1->next;
    }
    if(temp1->next == head){
        temp1->next = temp;
        temp->next = head;
        tail = temp;
        return;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

//search function to search for a key
void Search(int a){
    Node* temp = head;
    while(temp->next != head){
        if(a == temp->data){
            cout<<"Key is found"<<endl;
            return;
        }
        temp = temp->next;
    }
    if(temp->data == a){
        cout<<"Key is found"<<endl;
    }
    else{
        cout<<"Key is not found"<<endl;
    }
}
//Display function to display linked list
void Display(){
    Node* temp = head;
    if(head == NULL){
        cout<<"The list is empty"<<endl;
        return;
    }
    cout<<"Present Linked list is: ";
    while(temp->next !=head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
//Delete function without arguments deletes at the beginning
void Delete(){
    Node* temp = head;
    head = head->next;
    tail->next = head;
    free(temp);
}
//Delete function with arguments deletes at some position
void Delete(int pos){
    if(pos == 0){
        Delete();
        return;
    }
    Node* temp = head;
    Node* prev;
    while(pos--){
        prev = temp;
        if(temp == tail){
            cout<<"The given index is out of bound"<<endl;
            return;
        }
        temp = temp->next;
    }
    if(temp->next == head){
        prev->next = head;
        tail = prev;
        free(temp);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void Menu(){
    cout<<"Enter 1 to insert"<<endl;
    cout<<"Enter 2 to delete"<<endl;
    cout<<"Enter 3 to search"<<endl;
    cout<<"Enter 4 to display"<<endl;
    cout<<"Enter 5 to exit"<<endl;
}
int main(){
    Menu();
    int n;
    cin>>n;
    while(true){
        if(n == 1){
            int q;
            cout<<"Enter 1 to insert in the beginning"<<endl;
            cout<<"Enter 2 to insert at some position"<<endl;
            cin>>q;
            if(q == 1){
                cout<<"Enter data: "<<endl;
                int data;
                cin>>data;
                Insert(data);
                Display();
            }
            else{
                cout<<"Enter data: "<<endl;
                int data;
                cin>>data;
                int pos;
                cout<<"Enter position: "<<endl;
                cin>>pos;
                Insert(data,pos);
                Display();
            }
            Menu();
            cin>>n;
        }
        if(n == 2){
            int q;
            cout<<"Enter 1 to Delete at beginning"<<endl;
            cout<<"Enter 2 to Delete at some position"<<endl;
            cin>>q;
            if(q == 1){
                Delete();
                Display();
            }
            else{
                cout<<"Enter the position: "<<endl;
                int p;
                cin>>p;
                Delete(p);
                Display();
            }
            Menu();
            cin>>n;
        }
        if(n == 3){
            int key;
            cout<<"Enter key: "<<endl;
            cin>>key;
            Search(key);
            Menu();
            cin>>n;
        }
        if(n == 4){
            Display();
            Menu();
            cin>>n;
        }
        if(n == 5){
            return 0;
        }
    }

}

