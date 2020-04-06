//
// Created by const on 4/3/2020.
//

#ifndef TEMA2_POO_COADA_H
#define TEMA2_POO_COADA_H

#include "Nod.h"

class Coada{
    Nod* prim;
    Nod* ultim;
    int dim_max;
public:
    Coada();                ///constructor de initializare
    Coada(Nod *);  ///constructor param
    Coada(Coada&);    ///copiere
    ~Coada();
    virtual void insert(char*);    ///inserare
    Nod* top();                      ///return primul element
    void pop();                     ///eliminarea primului element
    void empty();                   ///golire coada
    friend std::ostream& operator << (std::ostream&, const Coada&);
    friend std::istream& operator >> (std::istream&, Coada&);
    Coada& operator=(const Coada&);
    int get_dim();
    Nod* get_first();
    Nod* get_last();
    int set_dim(int);
    Nod* set_first(Nod*);
    Nod* set_last(Nod*);
};


#endif //TEMA2_POO_COADA_H
