#include "automaton.h"
#include <iostream>
#include <windows.h>

using namespace std ;

void gotoxy(int x, int y){
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

void firstline(int x,int y,automaton A){

    gotoxy(x,y);
    char alphabet[28] = {"abcdefghijklmnopqrstuvwxyz*"} ;
    cout << "States |   " ;
    for (int i = 0 ; i < A.language ; i++){
        cout << alphabet[i] << "   |   " ;
    }
    cout << "*   | " ;
    cout << "I/F ? |"  ;
    gotoxy(x,y+1);
    cout << "--------" ;
    for (int i = 0 ; i < A.language ; i++){
        cout << "--------" ;
    }
    cout << "----------------" ;

}

void CheckTransitions(int i, int j, automaton A,int &pos){

    char alphabet[28] = {"abcdefghijklmnopqrstuvwxyz*"} ;

    for (int k = 0 ; k<A.nb_transitions ; k++ ){
        if (A.transitions[k].source == A.states[i] ){
            if (A.transitions[k].character == alphabet[j]){
                printf("%d",A.transitions[k].target);
                pos++ ;
            }
        }
    }
}

void InitOrFinal(int i,automaton A,int &pos,int x,int y){

        int init = 0 , term = 0 ;

        for (int j = 0 ; j < A.nb_init ; j++){
            if (A.init_states[j] == A.states[i]){
                init = 1 ;
            }
        }
        for (int j = 0 ; j < A.nb_final ; j++){
            if (A.final_states[j] == A.states[i]){
                term = 1 ;
            }
        }

        if ((init == 1)&&(term == 1)){
            pos = pos -1  ;
            gotoxy(pos,i*2+2+y);
            printf("I/F");
        } else {
            gotoxy(pos,i*2+2+y);
            if ((init == 1)&&(term == 0)){
                printf("I");
            }
            if ((init == 0)&&(term == 1)){
                printf("F");
            }
        }
        pos = 8*(A.language+3) + x;
        gotoxy(pos-1,i*2+2+y);
        cout << "|" ;
}

void Separation(automaton A,int x,int y,int i,int var,int &pos){

        pos = 8*(A.language+var) + x ;
        gotoxy(pos-1,i*2+2+y);
        cout << "|" ;
        pos = pos + 3 ;
        gotoxy(pos,i*2+2+y);
}
