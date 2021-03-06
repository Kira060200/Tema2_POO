//
// Created by const on 4/3/2020.
//

#ifndef TEMA2_POO_NOD_H
#define TEMA2_POO_NOD_H


#include <iostream>
class Nod{
    char* info;
    Nod* next;
public:
    Nod();     ///constructor de initializare
    Nod(char*);
    Nod(char*,const Nod&); ///constructor parametrizat
    Nod(const Nod&);  ///copiere
    ~Nod();
    Nod* get_next();
    char* get_info();
    void set_next(Nod*);
    void set_info(char*);
    friend class Coada;
    friend std::ostream& operator << (std::ostream&, const Nod&);
    friend std::istream& operator >> (std::istream&, Nod&);
    Nod& operator=(const Nod&);
};


#endif //TEMA2_POO_NOD_H
