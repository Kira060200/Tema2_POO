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
Coada::Coada(const Coada &obj)
{
    dim_max=obj.dim_max;
    prim=new Nod(*obj.prim);
    if(obj.prim!=obj.ultim) {
        Nod *p;
        prim->next = p;
        Nod *p2;
        p2 = obj.prim;
        while (p2->next != obj.ultim && p2 != obj.ultim) {
            p->info = p2->info;
            p = p->next;
            p2 = p2->next;
        }
        p->info = obj.ultim->info;
        ultim = p;
    }else{
        ultim=prim;
    }
}
Coada::~Coada()
{
    if(dim_max>0) {
        delete prim;
        if (dim_max > 1)
            delete ultim;
        dim_max = 0;
    }
}
Nod* Coada::top(){
    try {
        if(prim==nullptr)
            throw 1;
        return prim;
    }catch(int ex){
        return NULL;
    }
}
void Coada::pop()
{
    try{
        if(prim==nullptr&&ultim==nullptr)
            throw 2;
        if(prim==ultim){
            delete prim;
            prim=ultim=nullptr;
            dim_max=0;
        }
        else{
            dim_max--;
            Nod *p;
            p=prim;
            prim=prim->next;
            delete p;
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
        if(prim==nullptr||ultim== nullptr)
            throw i;
        Nod* newnode;
        while(prim!=ultim)
        {
            newnode=prim;
            prim=prim->next;
            delete newnode;
        }
        delete prim;
        if(old>1)
            delete ultim;
        prim=ultim=nullptr;
    }catch(int x)
    {
        std::cout<<"Queue already empty";
    }
}
std::ostream& operator <<(std::ostream& output, const Coada& obj){
    //output << obj.info;
    return output;
}

std::istream& operator >>(std::istream& input, Coada& obj){
    obj.dim_max++;
    char *c;
    c=new char[256];
    Nod* p;
    p=new Nod();
    input >> c;
    p->set_info(c);
    if(obj.dim_max!=1) {
        obj.ultim->set_next(p);
        obj.ultim = p;
    }
    else
    {
        obj.prim->set_info(c);
    }
    return input;
}