#include <iostream>
#include "list.cpp"

class table{
    public:
    bool piece;
    list myTable[7];

    table(){
        piece = true;
    }

    void print(){
        for(int i=6;i>=0;i--){
            for(int j=0;j<7;j++){
                if(myTable[j].length() > i)
                    cout<<myTable[j][i]<<" ";
                else
                    cout<<"* ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    bool insert(int index){
        if(myTable[index].length() > 6){
            return false;
        }
        if(index < 0 || index > 6){
            return false;
        }

        myTable[index].push(piece);
        piece = !piece;
        return true;
    }

    void rotateChar(int index){
        if(!myTable[index].rotateChar() ){
            return;
        }
        piece = !piece;
        return;
    }

};

int main(){

    table myTable;
    char inputChar;
    int inputIndex;

    while(true){
        cout<<"input character (r)otate (i)nsert: ";
        cin>>inputChar;
        cout<<"input index from 0-6: "; 
        cin>>inputIndex;

        if(inputChar == 'i'){
            myTable.insert(inputIndex);
        }
        else{
            myTable.rotateChar(inputIndex);
        }
        myTable.print();
    }


    return 0;
}