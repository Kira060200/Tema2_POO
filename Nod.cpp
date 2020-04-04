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
    info=new char[strlen(c)+1];
    strcpy(info,c);
    next=NULL;
}
Nod::Nod(char* c,Nod const &obj)
{
    info=new char[strlen(c)+1];
    strcpy(info,c);
    next=obj.next;
}
Nod::Nod(Nod const &obj)
{
    info=new char[strlen(obj.info)+1];
    strcpy(info,obj.info);
    next=obj.next;
}
Nod::~Nod()
{
    delete info;
    delete next;
}
Nod& Nod:: operator=(const Nod& obj)
{
    try{
        if(this==&obj)
            throw 1;
        info=new char[strlen(obj.info)+1];
        strcpy(info,obj.info);
        next=new Nod(*obj.next);
    }catch(int ex)
    {
        return *this;
    }
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
char* Nod::get_info() {
    return info;
}
Nod* Nod::get_next(){
    return next;
}
void Nod::set_next(Nod* obj) {
    this->next=obj;
}
void Nod::set_info(char *c) {
    info=new char[strlen(c)+1];
    strcpy(this->info,c);
}