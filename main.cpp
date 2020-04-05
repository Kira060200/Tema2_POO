#include <iostream>
#include "Nod.h"
#include "Coada.h"
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
    cout<<e.top()->get_info();
    Coada g(e);
    ///e.empty();
    cout<<g.top()->get_info();
    ///g.pop();
    ///g.empty();
    cout<<endl;
    Coada h;
    cin>>h;
    cin>>h;
    cout<<h.top()->get_info();
    cout<<h;
    h.empty();
    h.insert("Ana");
    h.insert("are");
    h.insert("mere");
    cout<<h;
    h.empty();
    cout<<h.top()->get_info();
    return 0;
}
