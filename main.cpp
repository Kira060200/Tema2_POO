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
    Coada e(&c,1);
    Nod f;
    cout<<e.top()->get_info();
    Coada g(e);
    e.empty();
    cout<<g.top()->get_info();
    g.empty();
    return 0;
}
