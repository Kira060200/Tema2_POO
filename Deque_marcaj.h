//
// Created by const on 4/6/2020.
//

#ifndef TEMA2_POO_DEQUE_MARCAJ_H
#define TEMA2_POO_DEQUE_MARCAJ_H

#include "Coada.h"
class Deque_marcaj:public Coada {
public:
    Deque_marcaj();
    void insert(char*c,int);
    void pop_left();
    void pop_right();
};


#endif //TEMA2_POO_DEQUE_MARCAJ_H
