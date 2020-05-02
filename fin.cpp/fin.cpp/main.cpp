//
//  main.cpp
//  project.cpp
//
//  Created by Aastha Goel on 02/05/20.
//  Copyright © 2020 Aastha Goel. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <iterator>
#include <stdlib.h>
//#include "queue.h"
//#include "stack.h"
#include <algorithm>
#include <time.h>

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
 
string compinput(string CombinedMoves[], int size){
    //
    int i=rand()%size;
    return CombinedMoves[i];
}
 
void checkboxmade(vector<string> line, string mt){
    //Convert the string into integers using ASCII values
    int l1=mt[0]-64;
    int i1=mt[1]-48;
    int l2=mt[2]-64;
    int i2=mt[3]-48;
    int i=i1+1;
    int k=i1-1;
    //Conversion of integers into strings
    auto s1 = std::to_string(i1);
    auto s2 = std::to_string(i);
    auto sub = std::to_string(k);
    //Naming the adjacent dots to the line drawn
    string next1= mt[0]+s1;
    string next2= mt[0]+s2;
    string next3=mt[2]+s1;
    string next4=mt[2]+s2;
    string nextsub1=mt[0]+sub;
    string nextsub2=mt[2]+sub;
    //Conversion of adjacent letters to integers
    int fl1= mt[0]+1;
    int fl2= mt[2]-1;
    string nletter1, nletter2;
    nletter1= (char)fl1;
    nletter2= (char)fl2;
    //Naming the adjacent dots to the line drawn
    string vnext= nletter1+s1;
    string vnext2= nletter1+s2;
    string vnextsub1= nletter2+s1;
    string vnextsub2= nletter2+s2;
    //Lower side: checking if box is made
    for (int j=1; j<6; j++){
        if (l1==j && l2==j+1)
            if (std::find(line.begin(), line.end(), next1+next2) != line.end())
                if (std::find(line.begin(), line.end(), next3+next4) != line.end())
                    if (std::find(line.begin(), line.end(), next2+next4) != line.end())
                        cout<<"LB"<<endl;}
    //Upper side: checking if box is made
    for (int j=2;j<7;j++){
        if (l1==j && l2==j+1)
            if (std::find(line.begin(), line.end(), nextsub1+nextsub2) != line.end())
                if (std::find(line.begin(), line.end(), nextsub1+next1) != line.end())
                    if (std::find(line.begin(), line.end(), nextsub2+next3) != line.end())
                        cout<<"UB"<<endl;}
    //Right side: checking if box is made
    for (int n=1; n<6;n++){
        if (l1==l2)
            if (i1==n && i2==n+1)
                if (std::find(line.begin(), line.end(), next1+vnext) != line.end())
                    if (std::find(line.begin(), line.end(), vnext+vnext2) != line.end())
                        if (std::find(line.begin(), line.end(), next4+vnext2) != line.end())
                            cout<<"verticalbox right"<< endl;}
    //Left side: checking if box is made
    for (int n=2; n<7; n++){
        if (l1==l2)
            if (i1==n && i2==n+1)
                if (std::find(line.begin(), line.end(), vnextsub1+next1) != line.end())
                    if (std::find(line.begin(), line.end(), vnextsub1+vnextsub2) != line.end())
                        if (std::find(line.begin(), line.end(), vnextsub2+next4) != line.end())
                            cout<< "verticalbox left"<< endl;}

}
 
void DrawBoard(char arr[28][28],int gridSize, int cellSize, string m1, string m2){
    int total = gridSize*cellSize, no=1,i,j;
    char x;
    cout<<"    A       B       C       D       E       F"<<endl;
    cout<<endl;
    if (m1[1]==m2[1]){    //HORIZONTAL
        int c1=(m1[0]-65)*4;
        int c2=(m2[0]-65)*4;
        for ( i=0; i<=total; i++){
            if (i%4==0){
                cout<<no<<"  ";
                no=no+1;
            }
            else{
                cout<<"   ";
            }
            for ( j=0; j<=total; j++){
                if (i%cellSize==0 && j%cellSize==0){
                    x='*';
                }
                else if ((i%4==0)&&((i/4)+1==m1[1]-48) && (j>c1 && j<c2)){
                    x='*';
                }
                else{
                    if (arr[i][j]!='*'){
                        x=' ';
                    }
                    else{
                        x='*';
                    }
                }
                cout<<" "<<x;
                arr[i][j]=x;
            }
            cout<<endl;
        }
    }
    else if (m1[0]==m2[0]){  //VERTICAL
        for ( i=0; i<=total; i++){
            if (i%4==0){
                cout<<no<<"  ";
                no=no+1;
            }
            else{
                cout<<"   ";
            }
            
            for ( j=0; j<=total; j++){
                if (i%cellSize==0 && j%cellSize==0){
                    x='*';
                }
                
                else if ((j%4==0)&&((j/4)+1==m1[0]-64) && (i>((m1[1]-49)*4) && i<((m2[1]-49)*4))){
                    x='*';
                }
                else{
                    if (arr[i][j]!='*'){
                        x=' ';
                    }
                    else{
                        x='*';
                    }
                }
                cout<<" "<<x;
                arr[i][j]=x;
            }
            cout<<endl;
        }
    }
}

//template<typename T> void pushElements(T& stackRef);
//template<typename T> void popElements(T& stackRef){
//}
 /*void showstack(stack <string, vector<string>> str_stack)
 {
     while (!str_stack.empty())
     {
         cout << '\t' << str_stack.top();
         str_stack.pop();
     }
     cout << '\n';
 }
 */
int main(){
    int tot=0,up=0,cp=0,turn=0,valid;
    char boxmade,cen, arr[28][28];
    string m1,m2,t,mt;
    //stack<string, vector<string> > str_stack;
    vector<string> line;
    //stack<int> list;
    srand(time(0));
    string CombinedMoves[]={"A1A2","A2A3","A3A4","A4A5","A5A6","B1B2","B2B3","B3B4","B4B5","B5B6","C1C2","C2C3","C3C4","C4C5","C5C6","D1D2","D2D3","D3D4","D4D5","D5D6","E1E2","E2E3","E3E4","E4E5","E5E6","F1F2","F2F3","F3F4","F4F5","F5F6","A1B1","B1C1","C1D1","D1E1","E1F1","A2B2","B2C2","C2D2","D2E2","E2F2","A3B3","B3C3","C3D3","D3E3","E3F3","A4B4","B4C4","C4D4","D4E4","E4F4","A5B5","B5C5","C5D5","D5E5","E5F5","A6B6","B6C6","C6D6","D6E6","E6F6"};
    
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
            cout<< " "<<x;
            arr[i][j]=x;
        }
        cout<<endl;
    }
    cout<<endl;
 
    
    while(tot!=8){
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
                cout<<"Invalid, this point does not exixt"<<endl;
                continue;
            }
            cin>>m2;
            valid=checkifvalid(m2);
            if (valid==0){
                cout<<"Invalid move as this point does not exixt"<<endl;
                continue;
            }
            if(m1==m2){
                cout<<"Invalid move as both points are same"<<endl;
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
            
            mt=m1+m2;
            bool exist=std::find(std::begin(CombinedMoves), std::end(CombinedMoves),mt)!=std::end(CombinedMoves);
            if (exist==0){
                cout<<"Invalid move because these 2 points are not adjacent"<<endl;
                continue;
            }
        }
        /*stack <int> s;
          s.push(10);
          s.push(30);
          s.push(20);
          s.push(5);
          s.push(1);
        
          cout << "The stack is : ";
          showstack(s);
        
          cout << "\ns.size() : " << s.size();
          cout << "\ns.top() : " << s.top();
        
        
          cout << "\ns.pop() : ";
          s.pop();
          showstack(s);
        //
        for (int i=0; i<4;i++){
            stack<char> cc;
            cc=mt[i];
            for (char c:mt){
                mt.push(c);}
            for (char c:mt){
                cout<<mt.top();
                mt.pop();}}
        }*/
        
       //queue<string> q;
        //q.push(mt);
       // cout<< q.push(mt)<<endl;
           
       // while (!str_queue.empty()) {
         //  cout << str_stack.top();
          // str_stack.pop();
        
        //FINAL IF STACK
        
        /*string quote[2] ={m1,m2};

        for (int i =0; i < 2; ++i){
            str_stack.push(quote[i]);
            cout << quote[i];}*/
        //while (!str_stack.empty()) {
           //cout << str_stack.top();
           //str_stack.pop();
        //}
        
        //(list);
        //computer's turn PART.1
        else if (turn%2!=0){
            int size=sizeof(CombinedMoves)/sizeof(CombinedMoves[0]);
            mt=compinput(CombinedMoves,size);
            std::string a=mt[0]+std::to_string(mt[1]-48);
            std::string b=mt[2]+std::to_string(mt[3]-48);
            m1=a;m2=b;
            cout<<endl;
            cout<<a<<" "<<b<<endl;
        }
        // delete used element(mt) from array CombinedMoves
        DrawBoard(arr,5,4,m1,m2);
        cout<<endl;
        //string quote[2] ={m1,m2};
        //for (int i =0; i < 2; ++i){
        //str_stack.push(mt);
        //Adding the moves of the user into the vector string
        line.push_back(mt);
        checkboxmade(line, mt);
        //str_stack.push(m2);
            //cout << quote[i];
        turn+=1;
        tot+=1;
        /*
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
        DrawBoard(arr,5,4,m1,m2);
        cout<<endl;
        //display points PART.4
        cout<<"USER'S Score:"<<up<<endl;
        cout<<"COMPUTER'S Score:"<<cp<<endl;*/
    }
    //cout<<"H"<< endl;
    //showstack(str_stack);
    for(int i=0; i < line.size(); i++){
          cout << line.at(i) << ' ';
    }

    /*if (up>cp){
        cout<<"USER wins by "<<up-cp<<" points!"<<endl;
    }
    else{
        cout<<"COMPUTER wins by "<<cp-up<<" points!"<<endl;
    }*/
}

/*template<typename T> void pushElements(T& stackRef){
    for (int i=0; i<4; i++){
        stackRef.push(i);
        cout<< stackRef.top()<<' ';
}
}*/


