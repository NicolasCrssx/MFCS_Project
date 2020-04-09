#include <iostream>
#include <fstream>
#include "automaton.h"

using namespace std;

void getfile (char name[],automaton &A){ //This function sends all the information about the automaton into a structure.

    ifstream file (name);
    file >> A.language ;
    file >> A.nb_states ;
    file >> A.nb_init ;
    for (int i = 0 ; i < A.nb_init ; i++){
        file >> A.init_states[i] ;
    }
    file >> A.nb_final ;
    for (int i = 0 ; i < A.nb_final ; i++){
        file >> A.final_states[i] ;
    }
    file >> A.nb_transitions ;
    for (int i = 0 ; i < A.nb_transitions ; i++){
        file >> A.transitions[i].source ;
        file >> A.transitions[i].character ;
        file >> A.transitions[i].target ;
    }

    int counter = 0 ;
    int k ;

    for (int i = 0 ; i < A.nb_transitions ; i++){
        int var = 0, j = 0 ;

        k = counter ;

        if (counter != 0){
            while ((var == 0)&&(j<k)){

                if (A.transitions[i].source == A.states[j]){
                    var = 1 ;
                }
                j++ ;
            }

            if (var == 0){
                A.states[counter] = A.transitions[i].source ;
                counter++ ;
            }
            var = 0 ;
            j = 0 ;
        } else {
            A.states[counter] = A.transitions[i].source ;
            counter++ ;
        }

        k = counter ;

        while ((var == 0)&&(j<k)){
            if (A.transitions[i].target == A.states[j]){
                var = 1 ;
            }
            j++ ;
        }

        if (var == 0){
            A.states[counter] = A.transitions[i].target ;
            counter++ ;
        }
        var = 0 ;
        j = 0 ;
    }


}


void display(automaton &A,int x,int y){

    firstline(x,y,A);

    gotoxy(x,y+2);

    for (int i=0 ; i<A.nb_states ; i++){

        int pos = x + 3 ;
        gotoxy(pos,i*2+2+y) ;
        cout << A.states[i]  ;

        for (int j = 0 ; j < A.language ; j++){

            pos = 8*(j+1) + x ;
            gotoxy(pos-1,i*2+2+y);
            cout << "|"  ;
            gotoxy(pos+3,i*2+2+y);

            CheckTransitions(i,j,A,pos);

        }

        Separation(A,x,y,i,1,pos);



        CheckTransitions(i,26,A,pos);

        Separation(A,x,y,i,2,pos);

        InitOrFinal(i,A,pos,x,y);


        gotoxy(x,i*2+3+y);
        cout << "--------" ;
        for (int l = 0 ; l < A.language ; l++){
            cout << "--------" ;
        }
        cout << "----------------" ;

    }


}
