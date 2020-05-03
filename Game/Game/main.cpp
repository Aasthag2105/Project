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
#include <algorithm>
#include <time.h>

using namespace std;
 
void printgrid(char arr[28][28]){
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
}
 
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

void delelement(string CombinedMoves[], int size, string mt){
    int i,flag=0,loc;
    for (i=0; i<size; i++){
        if (CombinedMoves[i]==mt){
            flag=1;
            loc=i;
            break;
        }
    }
    if (flag==1){
        for (i=loc; i<size-1;i++){
            CombinedMoves[i]=CombinedMoves[i+1];
        }
    }
}
 
string checkboxmade(vector<string> line, string mt, string flag){
    //Convert the string into integers using ASCII values
    flag="novalue";
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
        if (l1==j && l2==j+1){
            if (std::find(line.begin(), line.end(), next1+next2) != line.end()){
                if (std::find(line.begin(), line.end(), next3+next4) != line.end()){
                    if (std::find(line.begin(), line.end(), next2+next4) != line.end()){
                        flag=mt;}}}}}
    //Upper side: checking if box is made
    for (int j=2;j<7;j++){
        if (l1==j && l2==j+1){
            if (std::find(line.begin(), line.end(), nextsub1+nextsub2) != line.end()){
                if (std::find(line.begin(), line.end(), nextsub1+next1) != line.end()){
                    if (std::find(line.begin(), line.end(), nextsub2+next3) != line.end()){
                        flag=nextsub1+nextsub2;}}}}}
    //Right side: checking if box is made
    for (int n=1; n<6;n++){
        if (l1==l2){
            if (i1==n && i2==n+1){
                if (std::find(line.begin(), line.end(), next1+vnext) != line.end()){
                    if (std::find(line.begin(), line.end(), vnext+vnext2) != line.end()){
                        if (std::find(line.begin(), line.end(), next4+vnext2) != line.end()){
                            flag= next1+vnext;}}}}}}
    //Left side: checking if box is made
    for (int n=1; n<7; n++){
        if (l1==l2){
            if (i1==n && i2==n+1){
                //cout<<vnextsub1+next1<<" "<< vnextsub1+vnextsub2<<"  "<<vnextsub2+next4<<" "<<endl;
                if (std::find(line.begin(), line.end(), vnextsub1+next1) != line.end()){
                    if (std::find(line.begin(), line.end(), vnextsub1+vnextsub2) != line.end()){
                        if (std::find(line.begin(), line.end(), vnextsub2+next4) != line.end()){
                            flag=vnextsub1+next1;}}}}}}
    return flag;

}
 
void DrawBoard(char arr[28][28],int gridSize, int cellSize, string m1, string m2, string p1, char cen){
    int total = gridSize*cellSize, no=1,i,j;
    cout<<"    A       B       C       D       E       F"<<endl;
    cout<<endl;
    if (m1[1]==m2[1]){    //HORIZONTAL
        int c1=(m1[0]-65)*4;
        int c2=(m2[0]-65)*4;
        for ( i=0; i<=total; i++){
            for ( j=0; j<=total; j++){
                if (i%cellSize==0 && j%cellSize==0){
                    arr[i][j]='*';
                }
                else if ((i%4==0)&&((i/4)+1==m1[1]-48) && (j>c1 && j<c2)){
                    arr[i][j]='*';
                }
            }
        }
    }
    else if (m1[0]==m2[0]){  //VERTICAL
        for ( i=0; i<=total; i++){
            for ( j=0; j<=total; j++){
                if (i%cellSize==0 && j%cellSize==0){
                    arr[i][j]='*';
                }
                
                else if ((j%4==0)&&((j/4)+1==m1[0]-64) && (i>((m1[1]-49)*4) && i<((m2[1]-49)*4))){
                    arr[i][j]='*';
                }
            }
        }
    }
    if (p1!="novalue"){
        int a=(4*(p1[1]-49))+2;
        int b=(4*(p1[0]-65))+2;
        if (cen!=' '){
            arr[a][b]=cen;
        }
    }
    for ( i=0; i<=total; i++){
        if (i%4==0){
            cout<<no<<"  ";
            no=no+1;
        }
        else{
            cout<<"   ";
        }
        for ( j=0; j<=total; j++){
            cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }
    
}


int main(){
    int tot=0,up=0,cp=0,turn=0,valid1, valid2,top=0;
    char cen, arr[28][28];
    string flag;
    string m1,m2,t,mt,p1;
    //stack<string, vector<string> > str_stack;
    vector<string> line;
    //stack<int> list;
    srand(time(0));
    string CombinedMoves[]={"A1A2","A2A3","A3A4","A4A5","A5A6","B1B2","B2B3","B3B4","B4B5","B5B6","C1C2","C2C3","C3C4","C4C5","C5C6","D1D2","D2D3","D3D4","D4D5","D5D6","E1E2","E2E3","E3E4","E4E5","E5E6","F1F2","F2F3","F3F4","F4F5","F5F6","A1B1","B1C1","C1D1","D1E1","E1F1","A2B2","B2C2","C2D2","D2E2","E2F2","A3B3","B3C3","C3D3","D3E3","E3F3","A4B4","B4C4","C4D4","D4E4","E4F4","A5B5","B5C5","C5D5","D5E5","E5F5","A6B6","B6C6","C6D6","D6E6","E6F6"};
    string Checkadjacent[]={"A1A2","A2A3","A3A4","A4A5","A5A6","B1B2","B2B3","B3B4","B4B5","B5B6","C1C2","C2C3","C3C4","C4C5","C5C6","D1D2","D2D3","D3D4","D4D5","D5D6","E1E2","E2E3","E3E4","E4E5","E5E6","F1F2","F2F3","F3F4","F4F5","F5F6","A1B1","B1C1","C1D1","D1E1","E1F1","A2B2","B2C2","C2D2","D2E2","E2F2","A3B3","B3C3","C3D3","D3E3","E3F3","A4B4","B4C4","C4D4","D4E4","E4F4","A5B5","B5C5","C5D5","D5E5","E5F5","A6B6","B6C6","C6D6","D6E6","E6F6"};
    string IsPlayed[60];
    
    int size=sizeof(CombinedMoves)/sizeof(CombinedMoves[0]);
    
    //print grid
    printgrid(arr);
    cout<<endl;
 
    while(tot!=25){
        //user's turn PART.1
        if (turn%2==0){
            cout<<"User's Move: ";
            cin>>m1;
            cin>>m2;
            valid1=checkifvalid(m1);
            valid2=checkifvalid(m2);
            if (valid1==0 || valid2==0){
                cout<<"Invalid move as the point does not exist. Enter values again!"<<endl;
                continue;
            }
            if(m1==m2){
                cout<<"Invalid move as both points are same. Enter values again!"<<endl;
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
            bool exist=std::find(std::begin(Checkadjacent), std::end(Checkadjacent),mt)!=std::end(Checkadjacent);
            if (exist==0){
                cout<<"Invalid move because these 2 points are not adjacent. Enter values again!"<<endl;
                continue;
            }
            bool exist2=std::find(std::begin(IsPlayed), std::end(IsPlayed),mt)!=std::end(IsPlayed);
            if (exist2==1){
                cout<<"Invalid because this move has already been played. Enter values again!"<<endl;
                continue;
            }
        }
        
        //computer's turn PART.1
        else if (turn%2!=0){
            cout<<"Computer's Move: ";
            mt=compinput(CombinedMoves,size);
            std::string a=mt[0]+std::to_string(mt[1]-48);
            std::string b=mt[2]+std::to_string(mt[3]-48);
            m1=a;m2=b;
            cout<<a<<" "<<b<<endl;
        }
        
        //array with used elements
        IsPlayed[top]=mt;
        top++;
        
        // delete used element(mt) from array CombinedMoves
        delelement(CombinedMoves, size, mt);
        size--;
        
        cout<<endl;
        //Adding the moves of the user into the vector string
        line.push_back(mt);
        flag= checkboxmade(line, mt, flag);
        
        if (flag!="novalue"){
            tot+=1;
            std::string p=flag[0]+std::to_string(flag[1]-48);
            p1=p;
            cout<<p1<<endl;
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
        DrawBoard(arr,5,4,m1,m2,p1,cen);
        cout<<endl;
        //display points PART.4
        cout<<"USER'S Score:"<<up<<endl;
        cout<<"COMPUTER'S Score:"<<cp<<endl;
        cout<<endl;
    }
    if (up>cp){
        cout<<"USER wins by "<<up-cp<<" points!"<<endl;
    }
    else{
        cout<<"COMPUTER wins by "<<cp-up<<" points!"<<endl;
    }
}
