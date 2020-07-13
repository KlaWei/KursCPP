#include <iostream>

class lista {
protected:
    class wezel {
    public:
        double val;
        wezel* next;
        wezel* prev;
        wezel(double v);
        void wstaw_za(double v, wezel* w); // wstawia nowy węzeł za w
        void wstaw_przed(double v, wezel* w); // wstawia nowy węzeł przed w
        wezel* zwroc_wezel_poz(int poz, int i);
        void kopiuj(wezel *w) {
            if(w==nullptr) {
                //last=w->prev;
                return;
            }
            next=new wezel(w->val); // nastepny węzeł obecnego
            next->prev=this; // obecny to następny poprzedniego
            next->kopiuj(w->next);
            //prev=this;
        }
        void usun() {
            prev->next=next;
            next->prev=prev;
            delete this;
        }
        
    };
    wezel* first;
    wezel* last;
    int ilosc;
public:
    lista();
    lista(const lista &l);
    ~lista();
    void wstaw_poczatek(double v);
    void wstaw_koniec(double v);
    void wstaw_pozycja(double v, int p);
    double usun_poczatek();
    double usun_koniec();
    double usun_poz(int poz);
    lista& operator=(const lista &l);
    friend std::ostream& operator<<(std::ostream &wy, const lista &l);
    double operator [] (int i) const;
};