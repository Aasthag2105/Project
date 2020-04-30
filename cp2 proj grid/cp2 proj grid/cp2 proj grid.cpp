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
using namespace std;
void DrawBoard(int gridSize, int cellSize){
    int total = gridSize*cellSize, no=1,i,j;
    char arr[28][28];
    string m1="B2", m2="B3";
    char x;
    cout<<"    A       B       C       D       E       F"<<endl;
    //cout<<"  0 1 2 3 4 5 6 7 8"<<endl;
    cout<<endl;
    if (m1[1]==m2[1]){
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
                    x=' ';
                }
                cout<<" "<<x;
                arr[i][j]=x;
            }
            cout<<endl;
        }
    }
    else if (m1[0]==m2[0]){
        int r1=(m1[0]-65)*4;
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
                else if ((j%4==0)&&((j/4)+1==m1[1]-48) && (i>((m1[1]-49)*4) && i<((m2[1]-49)*4))){
                    x='*';
                }
                else{
                    x=' ';
                }
                cout<<" "<<x;
                arr[i][j]=x;
            }
            cout<<endl;
        }
    }
}
        
 
int main(){
    DrawBoard(5,4);
}











































