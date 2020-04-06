//
// Created by const on 4/3/2020.
//

#include "Deque.h"
Deque::Deque() :Coada()
{
   // std::cout<<"Am fost invocat";
}
void Deque::insert_right(char* c) {
    this->insert(c);
}
void Deque::insert_left(char *c) {
    Nod* newnode=new Nod(c);
    newnode->set_next(this->get_first());
    this->set_first(newnode);
    this->set_dim(this->get_dim()+1);
}
void Deque::pop_right(){
    try{
        if(this->get_dim()==0)
            throw 2;
        if(this->get_first()==this->get_last()){
            free(this->get_last());
            this->set_dim(0);
        }
        else{
            Nod *p;
            free(this->get_last());
            this->set_dim(this->get_dim()-1);
        }
    }catch(int ex){
        std::cout<<"Queue is empty!";
    }
}
void Deque::pop_left(){
    this->pop();
}