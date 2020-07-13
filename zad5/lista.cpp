#include "lista.hpp"

lista::wezel::wezel(double v) : val(v), next(nullptr), prev(nullptr) {}

lista& lista::operator=(const lista &l)  {
    std::cout<<"op copy\n";
    this->first=new wezel(l.first->val);
    //this->last=new wezel(l.last->val);
    this->ilosc=l.ilosc;
    first->kopiuj(l.first->next);
    this->last=this->first->zwroc_wezel_poz(ilosc-1, 0);
    return *this;
}


lista::~lista() {
    ilosc=0;
    delete first;
    delete last;
}

lista::lista(const lista &l) {
    std::cout<<"konstr copy\n";
    *this = l;
}

void lista::wezel::wstaw_za(double v, wezel* w) {
    wezel* nowy = new wezel(v);
    nowy->next=w->next;
    nowy->prev=w;
    if(w->next!=nullptr) w->next->prev=nowy;
    w->next=nowy;
}

void lista::wezel::wstaw_przed(double v, wezel* w) {
    std::cout<<"wstawiam przed\n";
    std::cout<<"w.val="<<w->val<<"\n";
    wezel* nowy = new wezel(v);
    nowy->next=w;
    nowy->prev=w->prev;
    if(w->prev!=nullptr) {
        w->prev->next=nowy;
    }
    w->prev=nowy;
}

lista::wezel* lista::wezel::zwroc_wezel_poz(int poz, int i) {
    if(i==poz) {
        //std::cout<<"this.val="<<this->val<<"\n";
        return this;
    }
    return this->next->zwroc_wezel_poz(poz, ++i);
}

lista::lista() : first(nullptr), last(nullptr), ilosc(0) {}

double lista::usun_koniec() {
    double val = last->val;
    last=last->prev;
    last->next=nullptr;
    
    return val;
}

double lista::usun_poczatek() {
    double val=first->val;
    first=first->next;
    first->prev=nullptr;
    return val;
}

double lista::usun_poz(int poz) {
    wezel *tmp=first->zwroc_wezel_poz(poz, 0);
    double v=tmp->val;
    tmp->usun();
    return v;
}

void lista::wstaw_poczatek(double v) {
    ilosc++;
    if(first==nullptr) {
        wezel *nowy = new wezel(v);
        first = nowy;
        last = nowy;
        ilosc++;
        //return;
    }
    else {
        first->wstaw_przed(v, first);
        first=first->prev;
    }
    std::cout<<"first.val="<<first->val<<"\n";
}

void lista::wstaw_koniec(double v) {
    ilosc++;
    if(first==nullptr) {
        wezel *nowy = new wezel(v);
        first=nowy;
        last=nowy;
        return;
    }
    last->wstaw_za(v, last);
    last=last->next;
}

void lista::wstaw_pozycja(double v, int poz) {
    if(poz==0) {
        wstaw_poczatek(v);
        return;
    }
    if(poz==ilosc-1) {
        wstaw_koniec(v);
        return;
    }
    first->wstaw_przed(v, first->zwroc_wezel_poz(poz, 0));
}

std::ostream& operator<<(std::ostream &wy, const lista &l) {
    lista::wezel *pom=l.first;
    
    while(pom->next!=nullptr) {
        wy<<pom->val<<" ";
        pom=pom->next;
    }
    wy<<pom->val<<" ";
    pom=l.last;
    wy<<"odwrotnie: ";
    while(pom!=nullptr) {
        wy<<pom->val<<" ";
        pom=pom->prev;
    }
    return wy;
}
