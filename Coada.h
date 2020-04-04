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
    Coada(Nod *, int);  ///constructor param
    Coada(const Coada&);    ///copiere
    ~Coada();
    void insert(const Nod&,int);    ///inserare cu prioritate
    Nod* top();                      ///return primul element
    void pop();                     ///eliminarea primului element
    void empty();                   ///golire coada
    friend std::ostream& operator << (std::ostream&, const Nod&);
    friend std::istream& operator >> (std::istream&, Nod&);
    Coada& operator=(const Coada&);
};


#endif //TEMA2_POO_COADA_H
