#include <iostream>
#include <map>
using namespace std;

int tam;
int row,col;
int index;
string value;

void printRight(){
    for (int i = 0; i < col-1; ++i) {
        putchar(' ');
    }
    putchar('|');
}
void printLeft(){
    putchar('|');
    for (int i = 0; i < col-1; ++i) {
        putchar(' ');
    }
}
void printBothSides(){
    putchar('|');
    for (int i = 0; i < col - 2; ++i) {
        putchar(' ');
    }
    putchar('|');
}
void printNull(){
    for (int i = 0; i < col; ++i) {
        putchar(' ');
    }
}
void printMid(){
    putchar(' ');
    for (int i = 0; i < col - 2; ++i) {
        cout<<"-";
    }
    putchar(' ');
}

void printZero(){
    if(index == 0 || index == row - 1){
        printMid();
    }
    else if((1<=index && index<row/2)||(row/2<index && index<row-1)){
        printBothSides();
    }
    else{
        printNull();
    }
}
void printOne(){
    if(index == 0 || index == row-1 || index == row/2){
        printNull();
    }
    else{
        printRight();
    }
}
void printTwo(){
    if(index == 0 || index == row-1 || index == row/2){
        printMid();
    }
    else if(1<=index && index<row/2){
        printRight();
    }
    else{
        printLeft();
    }
}
void printThree(){
    if(index == 0 || index == row-1 || index == row/2){
        printMid();
    }
    else{
        printRight();
    }
}
void printFour(){
    if(index == 0 || index == row-1){
        printNull();
    }
    else if(1<=index && index<row/2){
        printBothSides();
    }
    else if(index == row/2){
        printMid();
    }
    else{
        printRight();
    }
}
void printFive(){
    if(index == 0 || index == row-1 || index == row/2){
        printMid();
    }
    else if(1<=index && index<row/2){
        printLeft();
    }
    else{
        printRight();
    }
}
void printSix(){
    if(index == 0 || index == row-1 || index == row/2){
        printMid();
    }
    else if(1<=index && index<row/2){
        printLeft();
    }
    else{
        printBothSides();
    }
}
void printSeven(){
    if(index == 0) printMid();
    else if(index==row/2 || index==row-1){
        printNull();
    }
    else{
        printRight();
    }
}
void printEight(){
    if(index == 0 || index == row-1 || index==row/2) printMid();
    else printBothSides();
}
void printNine(){
    if(index==0 || index == row/2 || index == row-1) printMid();
    else if(1<=index && index<row/2) printBothSides();
    else printRight();
}
map<int,void (*)()> printNumbers{{0,printZero},{1,printOne},{2,printTwo},
                                 {3,printThree},{4,printFour},{5,printFive},
                                 {6,printSix},{7,printSeven},{8,printEight},{9,printNine}};


int main() {

    while(cin>>tam>>value, tam){
        index = 0;
        row = 2*tam + 3;
        col = tam+2;
        for(;index<row;++index){
            for (int i = 0; i<value.size();++i) {
                (*printNumbers[value[i]-'0'])();
                if(i != value.size()-1) putchar(' ');
            }
            puts("");
        }
        puts("");
    }

    return 0;
}
