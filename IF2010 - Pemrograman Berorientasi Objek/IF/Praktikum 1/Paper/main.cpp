#include "Paper.hpp"

/*
ctor A
ctor B
ctor C
cctor C
fold A(1)
fold B(1)
fold C(1)
glue C
fold C(2)
dtor A
setName C => X
fold C(1)
glue C
fold C(2)
dtor C
dtor X
dtor B
*/
int main(void){

    Paper *a = new Paper('A');
    Paper *b = new Paper('B');
    Paper *c = new Paper('C'); 
    Paper *cc = new Paper(*c);

    a->fold();
    b->fold();
    c->fold();

    c->glue();

    delete a;

    c->setName('X');

    cc->fold();
    cc->glue();

    delete cc;
    delete c;
    delete b;
}