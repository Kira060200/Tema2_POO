//
// Created by const on 4/3/2020.
//

#include "Coada.h"
#include "Nod.h"
#include <cstring>
Coada::Coada()
{
    dim_max=0;
    prim=ultim=NULL;
}
Coada::Coada(Nod *obj , int n)
{
    dim_max=n;
    prim=obj;
    ultim=obj;
}
Coada::Coada(const Coada &obj)
{
    dim_max=obj.dim_max;
    prim=obj.prim;
    ultim=obj.ultim;
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
        if(prim==NULL)
            throw i;
        Nod* newnode=prim ;
        while(prim!=ultim)
        {
            newnode=prim;
            std::cout<<"YEE";
            //std::cout<<newnode->get_info()<<' ';
            prim=prim->get_next();
            delete newnode;
        }
        std::cout<<prim->get_next()<<std::endl;
        //delete prim->get_next();
        prim->~Nod();
        std::cout<<prim->get_next()<<std::endl;
        delete ultim;
    }catch(int x)
    {
        std::cout<<"NULL pointer exception";
    }
}