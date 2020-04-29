#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>
#include <iterator>
using namespace std;

/*Making grid
Check box is complete
To check whose turn
For computer’s turn*/

int checkifvalid(string m){
    string Moves[]={"A1","A2","A3","A4","A5","A6","B1","B2","B3","B4","B5","B6","C1","C2","C3","C4","C5","C6","D1","D2","D3","D4","D5","D6","E1","E2","E3","E6","E4","E5","F1","F2","F3","F4","F5","F6"};
        bool exists=std::find(std::begin(Moves), std::end(Moves),m)!=std::end(Moves);
    if (exists==0){
        return 0;
    }
    else{
        return 1;
    }
}

/*char compinput(){
    
}

char checkboxmade(){
    
}

void printgrid(){
    
}*/

int main(){
    int tot=0,up=0,cp=0,turn=0,valid;
    char boxmade,cen;
    string m1,m2,t;
    
    //print grid
    int total = 20, no=1;
    char x;
    cout<<"    A       B       C       D       E       F"<<endl;
    cout<<endl;
    for (int i=0; i<=total; i++){
        if (i%4==0){
            cout<<no<<"  ";
            no=no+1;
        }
        else{
            cout<<"   ";
        }
        for (int j=0; j<=total; j++){
            if (i%4==0 && j%4==0){
                x='*';
            }
            else{
                x=' ';
            }
            cout<< " "<<x;}
        cout<<endl;
    }

    
    while(tot!=25){
        /*Check whose turn
        If users turn call that function
        Else call other function
        Some func to check if box is made
        If point of user increased center=u turn=turn+2
         else center=c turn=turn+2
         else if no increase cent=’ ‘ turn=turn+1
        Send 2 point to to grid function and print grid(p1,p2,arr,cen)
        Display points*/
        
        //user's turn PART.1
        if (turn%2==0){
            cin>>m1;
            valid=checkifvalid(m1);
            if (valid==0){
                cout<<"Invalid"<<endl;
                continue;
            }
            cin>>m2;
            valid=checkifvalid(m2);
            if (valid==0){
                cout<<"Invalid"<<endl;
                continue;
            }
        }
        if(m1==m2){
            cout<<"Invalid, as both points are same"<<endl;
            continue;
        }
        if(m1[0]>m2[0]){
            t=m1;
            m1=m2;
            m2=t;
        }
        else if(m1[0]==m2[0]){
            if(m1[1]>m2[1]){
                t=m1;
                m1=m2;
                m2=t;
            }
        }
        //computer's turn PART.1
        /*else{
            compinput();
        }
        
        //check if box is made PART.2
        boxmade=checkboxmade();
        
        if (boxmade=='Y'){
            tot+=1;
            if (turn%2==0){
                up+=1;
                cen='U';
                turn+=2;
            }
            else{
                cp+=1;
                cen='C';
                turn+=2;
            }
        }
        else{
            cen=' ';
            turn+=1;
        }
        
        //print grid PART.3
        printgrid();
        
        //display points PART.4
        cout<<"USER'S Score:"<<up<<endl;
        cout<<"COMPUTER'S Score:"<<cp<<endl;*/
    }
    /*if (up>cp){
        cout<<"USER wins by "<<up-cp<<" points!"<<endl;
    }
    else{
        cout<<"COMPUTER wins by "<<cp-up<<" points!"<<endl;
    }*/
}
