//
// Created by const on 4/3/2020.
//

#include "Coada.h"
#include "Nod.h"
#include <cstring>
Coada::Coada()
{
    dim_max=0;
    prim=ultim=nullptr;
}
Coada::Coada(Nod *obj , int n)
{
    dim_max=n;
    prim=ultim=obj;
}
Coada::Coada(const Coada &obj)
{
    dim_max=obj.dim_max;
    prim=new Nod(*obj.prim);
    Nod* p;
    prim->next=p;
    Nod* p2;
    p2=obj.prim;
    while(p2->next!=obj.ultim && p2!=obj.ultim)
    {
        p->info=p2->info;
        p=p->next;
        p2=p2->next;
    }
    p->info=obj.ultim->info;
    ultim=p;
}
Coada::~Coada()
{
    dim_max=0;
    delete prim;
    delete ultim;
}
Nod* Coada::top(){
    return prim;
}
void Coada::empty() {
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
        delete ultim;
    }catch(int x)
    {
        std::cout<<"Queue already empty";
    }
}