#include <iostream>
#include "Nod.h"
#include "Coada.h"
#include "Deque.h"

using namespace std;
int main() {
    char*car="Apa";
    Nod a(car);
    cout<<a;
    Nod c("ENDL",a);
    cout<<c;
    Nod b(a);
    cout<<b;
    cout<<endl;
    /*Nod d;
    cin>>d;
    cout<<endl;
    cout<<d<<endl;
    Nod dd;
    dd=b;
    cout<<dd;*/
    Coada e(&c);
    Nod f;
    f.set_info("mama");
    cout<<f<<endl;
    cout<<e.top()->get_info()<<endl;
    Coada g(e);
    e.empty();
    cout<<g.top()->get_info();
    ///g.pop();
    ///g.empty();
    cout<<endl;
    Coada h;
    cin>>h;
    cin>>h;
    //cout<<h.top()->get_info();
    //cout<<h;
    //h.empty();
    h.insert("Ana");
    h.insert("are");
    h.insert("mere");
    cout<<h<<endl;
    Coada k(h);
    //k=h;
    cout<<k<<endl;
    h.pop();
    h.pop();
    cout<<h<<endl;
    h.empty();
    cout<<k<<endl;
    //cout<<h.top()->get_info();
    Deque deq;
    Deque deq2;
    cin>>deq;
    //cout<<deq;
    deq2=deq;
    deq.insert_right("salt");
    deq.insert_left("salut");
    cout<<deq;
    //deq.empty();
    cout<<endl<<deq2<<endl;
    deq.pop_right();
    cout<<deq;
    //cout<<deq.top()->get_info();
    return 0;
}
