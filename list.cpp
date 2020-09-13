#include <iostream>

using namespace std;

struct node{
    bool piece;
    node* next;
};

class list{
    public:
    node* head;
    node* tail;
    int count;

    list(){
        head = nullptr;
        tail = nullptr;
        count = -1;
    }

    void push(bool myChar){
        node *myNode = new node();
        myNode->piece = myChar;
        myNode->next = nullptr;
        count++;

        if(head == nullptr && tail == nullptr){
            head = myNode;
            tail = myNode;
        }
        else{
            tail->next = myNode;
            tail = myNode;
        }
    }

    bool rotateChar(){
        if(count < 0){
            return false;
        }
        if(count == 0){
            return true;
        }

        node* front = head;

        head = head->next;
        tail->next = front;
        tail = tail->next;

        front->next = nullptr;

        return true;
    }

    bool operator[](int index){
        if(index > count){
            throw std::out_of_range("error accessing node out of range");
        }

        int cnt = 0;
        node* pnt = head;

        do{
            if(cnt == index){
                return pnt->piece;
            }
            pnt = pnt->next;

        }while(cnt++ <= count);
    }

    void print(){
        node* pnt = head;
        while(pnt != nullptr){
            cout<<pnt->piece;
            if(pnt->next != nullptr){
                cout<<" -> ";
            }
            pnt = pnt->next;
        }
        cout<<endl;
    }

    int length(){
        return count+1;
    }
};