//
// Created by const on 4/3/2020.
//

#include "Coada.h"
#include "Nod.h"
#include <cstring>
Coada::Coada()
{
    dim_max=0;
    prim=new Nod();
    ultim=prim;
}
Coada::Coada(Nod *obj)
{
    dim_max=1;
    prim=ultim=obj;
}
Coada::Coada(Coada &obj)
{
    dim_max=0;
    prim=new Nod();
    ultim=prim;
    int i=0;
    Nod *p2;
    p2 = obj.prim;
    while (i<obj.dim_max) {
        i++;
        this->insert(p2->info);
        p2 = p2->next;
    }
}
Coada::~Coada()
{
    int old=dim_max;
    dim_max=0;
    try {
        if(old==0)
            throw 1;
        while (old) {
            Nod *newnode;
            newnode = prim;
            if (old != 1)
                prim = prim->next;
            free(newnode);
            old--;
        }
    }catch(int ex){}
}
void Coada::insert(char* c) {
    if(dim_max==0){
        prim = ultim = new Nod(c);
    }
    else{
        Nod *aux = new Nod(c);
        ultim -> next = aux;
        ultim = aux;
    }
    dim_max ++;
}
Nod* Coada::top(){
    try {
        if(dim_max==0)
            throw 1;
        return prim;
    }catch(int ex){
        return nullptr;
    }
}
void Coada::pop()
{
    try{
        if(dim_max==0)
            throw 2;
        if(prim==ultim){
            free(prim);
            dim_max=0;
        }
        else{
            dim_max--;
            Nod *p;
            p=prim;
            prim=prim->next;
            free(p);
        }
    }catch(int ex){
        std::cout<<"Queue is empty!";
    }
}
void Coada::empty() {
    int old=dim_max;
    dim_max=0;
    try{
        int i=1;
        if(old==0)
            throw i;
        while(old)
        {
            Nod* newnode;
            newnode=prim;
            if(old!=1)
                prim=prim->next;
            free(newnode);
            old--;
        }
        free(ultim);
    }catch(int x)
    {
        std::cout<<"Queue already empty";
    }
}
std::ostream& operator <<(std::ostream& output, const Coada& obj){
    Nod*p;
    p=obj.prim;
    int i=0;
    while(i<obj.dim_max) {
        i++;
        output << p->get_info()<<' ';
        p=p->get_next();
    }
    return output;
}

std::istream& operator >>(std::istream& input, Coada& obj){
    char *c;
    c=new char[256];
    input >> c;
    obj.insert(c);
    return input;
}
Coada& Coada::operator=(const Coada &obj) {
        int i=0;
        Nod *p2;
        p2 = obj.prim;
        while (i<obj.dim_max) {
            i++;
            this->insert(p2->info);
            p2 = p2->next;
        }
    return *this;
}