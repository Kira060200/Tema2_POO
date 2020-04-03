//
// Created by const on 4/3/2020.
//

#include "Nod.h"
#include <cstring>
Nod::Nod()
{
    info=new char[256];
    next=NULL;
}
Nod::Nod(char* c)
{
    info=c;
    next=NULL;
}
Nod::Nod(char* c,Nod const &obj)
{
    info=c;
    next=obj.next;
}
Nod::Nod(Nod const &obj)
{
    info=obj.info;
    next=obj.next;
}
Nod::~Nod()
{
    delete info;
    delete next;
}
Nod& Nod:: operator=(const Nod& obj)
{
    info=obj.info;
    next=obj.next;
    return *this;
}
std::ostream& operator <<(std::ostream& output, const Nod& obj){
    output << obj.info;
    return output;
}

std::istream& operator >>(std::istream& input, Nod& obj){
    input >> obj.info;
    return input;
}
