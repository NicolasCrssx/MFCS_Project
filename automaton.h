#ifndef AUTOMATON_H_INCLUDED
#define AUTOMATON_H_INCLUDED

#include <fstream>

struct transition {

    int source ;
    int target ;
    char character ;

} ;

struct automaton {

    int language ;
    int nb_states ;
    int nb_init ;
    int nb_final ;
    int nb_transitions ;

    int init_states[100] ;
    int final_states[100] ;
    int states[100] ;

    transition transitions[100];

} ;


void getfile(char name[],automaton &A);

void display(automaton &A,int x, int y);

void gotoxy(int x, int y);

void CheckTransitions(int i, int j, automaton A,int &pos);

void firstline(int x,int y,automaton A);

void InitOrFinal(int i,automaton A,int &pos,int x,int y);

void Separation(automaton A,int x,int y,int i,int var,int &pos);

#endif // AUTOMATON_H_INCLUDED
