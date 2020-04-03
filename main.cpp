#include <iostream>
#include "Nod.h"
using namespace std;
int main() {
    Nod a("Ana are mere");
    cout<<a;
    Nod c("ENDL",a);
    cout<<c;
    Nod b(a);
    cout<<b;
    cout<<endl;
    Nod d;
    cin>>d;
    cout<<endl;
    cout<<d;
    return 0;
}
