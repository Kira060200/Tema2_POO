//
// Created by const on 4/3/2020.
//

#include "Nod.h"
#include <cstring>
Nod::Nod(char* c)
{
    info=c;
    //next=new Node;
}
Nod::Nod(char* s,Nod* obj)
{
    //strcpy(info,s);
    next=obj;
}
Nod::Nod(Nod const &obj)
{
    info=obj.info;
    next=obj.next;
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
