//
// Created by const on 4/3/2020.
//

#ifndef TEMA2_POO_DEQUE_H
#define TEMA2_POO_DEQUE_H

#include "Coada.h"

class Deque:public Coada {
public:
    Deque();
    void insert_left(char*c);
    void insert_right(char*c);
    void pop_left();
    void pop_right();

};


#endif //TEMA2_POO_DEQUE_H
