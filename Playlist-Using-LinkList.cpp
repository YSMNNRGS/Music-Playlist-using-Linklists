#include<iostream>
#include<string>
using namespace std;

struct Node{
    string data;
    Node* next;
    Node* prev;
};

Node* head=NULL;
Node* current=NULL;

void insert(){
    cout<<"Enter Music Name: ";
    string temp;
    getline(cin>>ws, temp);
    Node* newNode=new Node{temp, NULL, NULL};
    if(!head){
        newNode->next=newNode->prev=newNode;
        head=current=newNode;
        return;
    }
    Node* last=head->prev;
    newNode->prev=last;
    newNode->next=head;
    last->next=newNode;
    head->prev=newNode;
}

void removeMusic(){
    if(!head){
        cout<<"No Music to delete!\n";
        return;
    }
    cout<<"Enter Music Name to delete: ";
    string temp;
    getline(cin>>ws, temp);
    Node* ptr=head;
    do{
        if(ptr->data==temp){
            if(ptr->next==ptr){
                head=NULL;
                cout<<"Playlist is Empty Now!\n";
            }else{
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
                if(ptr==head) head=ptr->next;
                cout<<"Music deleted!\n";
            }
            delete ptr;
            return;
        }
        ptr=ptr->next;
    }while(ptr!=head);
    cout<<"Music not found!\n";
}

void show(){
    if(!head){
        cout<<"Playlist is Empty!\n";
        return;
    }
    Node* ptr=head;
    int i=1;
    cout<<"\nDisplaying Playlist:\n";
    do{
        cout<<"Song "<<i++<<" : "<<ptr->data<<"\n";
        ptr=ptr->next;
    }while(ptr!=head);
}

void playNext(){
    if(!current) cout<<"No songs in Playlist!\n";
    else{
        current=current->next;
        cout<<"Playing Next: "<<current->data<<"\n";
    }
}

void playPrev(){
    if(!current) cout<<"No songs in Playlist!\n";
    else{
        current=current->prev;
        cout<<"Playing Previous: "<<current->data<<"\n";
    }
}

void playFirst(){
    if(!head) cout<<"Playlist is Empty!\n";
    else cout<<"Playing First: "<<head->data<<"\n";
}

void playLast(){
    if(!head) cout<<"Playlist is Empty!\n";
    else cout<<"Playing Last: "<<head->prev->data<<"\n";
}

void playSpecific(){
    if(!head){
        cout<<"No music to search!\n";
        return;
    }
    cout<<"Enter Music Name: ";
    string temp;
    getline(cin>>ws, temp);
    Node* ptr=head;
    do{
        if(ptr->data==temp){
            cout<<"Music Found! Playing: "<<ptr->data<<"\n";
            return;
        }
        ptr=ptr->next;
    }while(ptr!=head);
    cout<<"Music not found!\n";
}

int main(){
    while(true){
        cout<<"\n-----Song Playlist Application-----\n"
            "1. Add Music\n"
            "2. Remove Music\n"
            "3. Show Playlist\n"
            "4. Play Next\n"
            "5. Play Previous\n"
            "6. Play First\n"
            "7. Play Last\n"
            "8. Play Specific\n"
            "9. Exit\n";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
			insert(); 
			break;
            case 2: 
			removeMusic();
			break;
            case 3: 
			show(); 
			break;
            case 4: 
			playNext(); 
			break;
            case 5: 
			playPrev(); 
			break;
            case 6: 
			playFirst(); 
			break;
            case 7: 
			playLast(); 
			break;
            case 8: 
			playSpecific(); 
			break;
            case 9: return 0;
            default: cout<<"Invalid choice!\n";
        }
    }
}
