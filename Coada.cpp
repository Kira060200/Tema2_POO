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
    dim_max++;
    Nod* p=new Nod();
    if(dim_max>1) {
        ultim->next=p;
        strcpy(p->info,c);
        ultim=p;
    }
    else
    {
        strcpy(prim->info,c);
        ultim=prim;
    }
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
        if(old==0)
            throw i;
        while(old)
        {
            Nod* newnode;
            newnode=prim;
            if(old!=1)
                prim=prim->next;
            //std::cout<<prim<<' '<<newnode<<' '<<old<<std::endl;
            free(newnode);
            //std::cout<<prim<<' '<<newnode<<' '<<old<<std::endl;
            old--;
        }
        free(ultim);
        //prim=ultim=nullptr;
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