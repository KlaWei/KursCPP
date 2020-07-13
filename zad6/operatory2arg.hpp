#include "wyrazenie.hpp"

class operator2arg : public wyrazenie {
    protected:
        wyrazenie *left, *right;
        operator2arg(wyrazenie *lw, wyrazenie *rw) : left(lw), right(rw) {}
        virtual int priorytet()=0;
        virtual std::string op()=0;
        std::string opis() {
            if(left->priorytet() > priorytet() && right->priorytet() > priorytet()) 
                return "("+left->opis()+")"+op()+"("+right->opis()+")";
            else if(left->priorytet() > priorytet()) {
                return "("+left->opis()+")"+op()+right->opis();
            }
            else if(right->priorytet() > priorytet()) {
                return left->opis()+op()+"("+right->opis()+")";
            }
            else return left->opis()+op()+right->opis();
        }
};

class dodaj : public operator2arg {
    public:
        dodaj(wyrazenie *rw, wyrazenie *lw) : operator2arg(rw, lw) {}
        double oblicz() { return left->oblicz() + right->oblicz(); }
        //std::string opis() { if()return "("+left->opis()+"+"+right->opis()+")"; }
        std::string op() { return "+"; }
        int priorytet() { return 5; }
};

class odejmij : public operator2arg {
    public:
        odejmij(wyrazenie *rw, wyrazenie *lw) : operator2arg(rw, lw) {}
        double oblicz() { return left->oblicz() - right->oblicz(); }
        //std::string opis() { return "("+left->opis()+"-"+right->opis()+")"; }
        std::string op() { return "-"; }
        int priorytet() { return 5; }
};

class mnoz : public operator2arg {
    public:
        mnoz(wyrazenie *rw, wyrazenie *lw) : operator2arg(rw, lw) {}
        double oblicz() { return left->oblicz() * right->oblicz(); }
        //std::string opis() { return "("+left->opis()+"*"+right->opis()+")"; }
        std::string op() { return "*"; }
        int priorytet() { return 4; }
};

class dziel : public operator2arg {
    public:
        dziel(wyrazenie *rw, wyrazenie *lw) : operator2arg(rw, lw) {}
        double oblicz() {
            if(right->oblicz()==0) throw std::invalid_argument("Dzielenie przez 0");
            else return left->oblicz() / right->oblicz(); 
        }
        //std::string opis() { return "("+left->opis()+"/"+right->opis()+")"; }
        std::string op() { return "/"; }
        int priorytet() { return 3; }
};

class potega : public operator2arg {
    public:
        potega(wyrazenie *rw, wyrazenie *lw) : operator2arg(rw, lw) {}
        double oblicz() { return std::pow(left->oblicz(), right->oblicz()); }
        std::string opis() { return left->opis()+"^"+right->opis(); }
        std::string op() { return "^"; }
        int priorytet() { return 2; }
};

class modulo : public operator2arg {
    public:
        modulo(wyrazenie *rw, wyrazenie *lw) : operator2arg(rw, lw) {}
        double oblicz() {
            if(right->oblicz()==0) throw std::invalid_argument("Modulo 0");
            return std::fmod(left->oblicz(), right->oblicz()); 
        }
        std::string op() { return "mod"; }
        std::string opis() { return "("+left->opis()+" mod "+right->opis()+")"; }
        int priorytet() { return 2; }
};

class logarytm : public operator2arg {
    public:
        logarytm(wyrazenie *rw, wyrazenie *lw) : operator2arg(rw, lw) {}
        double oblicz() {
            if(log(right->oblicz())<=0) throw std::invalid_argument("Niepoprawna baza logarytmu");
            return log(left->oblicz())/log(right->oblicz());
        }
        std::string op() { return "log"; }
        std::string opis() { return "log("+left->opis()+", "+right->opis()+")"; }
        int priorytet() { return 2; }
};