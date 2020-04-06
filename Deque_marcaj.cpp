//
// Created by const on 4/6/2020.
//

#include "Deque_marcaj.h"
Deque_marcaj::Deque_marcaj() :Coada()
{
    // std::cout<<"Am fost invocat";
}
void Deque_marcaj::insert(char *c,int poz) {
    if(this->get_dim()==0){
        Nod*p;
        p=new Nod(c);
        this->set_first(p);
        this->set_last(this->get_first());
        this->set_dim(1);
    }
    else{
        Nod *aux = new Nod(c);
        if(poz>=get_dim()+1)
        {
            Nod* newnode=new Nod(c);
            newnode->set_next(this->get_first());
            this->set_first(newnode);
            this->set_dim(this->get_dim()+1);
        }else {
            int i = poz;
            Nod* newnode;
            Nod* aux=new Nod(c);
            newnode=this->get_first();
            while (get_dim()-i>1) {
                newnode = newnode->get_next();
                i++;
            }
            aux->set_next(newnode->get_next());
            newnode->set_next(aux);
            this->set_dim(this->get_dim()+1);
        }
    }
    /*Nod* newnode=new Nod(c);
    newnode->set_next(this->get_first());
    this->set_first(newnode);
    this->set_dim(this->get_dim()+1);*/

}
void Deque_marcaj::pop_right(){
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
void Deque_marcaj::pop_left(){
    this->pop();
}