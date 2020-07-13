#include "wyrazenie.hpp"

class operator1arg : public wyrazenie {
    protected:
        wyrazenie *wyraz;
        operator1arg(wyrazenie* w) : wyraz(w) {}
        int priorytet() { return 2; }
};

class Sin : public operator1arg {
    public:
        Sin(wyrazenie* w) : operator1arg(w) {}
        double oblicz() { return std::sin(wyraz->oblicz()); }
        std::string opis() { return "sin("+wyraz->opis()+")"; }
};

class Cos : public operator1arg {
    public:
        Cos(wyrazenie* w) : operator1arg(w) {}
        double oblicz() { return std::cos(wyraz->oblicz()); }
        std::string opis() { return "cos("+wyraz->opis()+")"; }
};

class ln : public operator1arg {
    public:
        ln(wyrazenie* w) : operator1arg(w) {}
        double oblicz() { return std::log(wyraz->oblicz()); }
        std::string opis() { return "ln("+wyraz->opis()+")"; }
};

class exp : public operator1arg {
    public:
        exp(wyrazenie* w) : operator1arg(w) {}
        double oblicz() { return std::exp(wyraz->oblicz()); }
        std::string opis() { return "exp("+wyraz->opis()+")"; }
};

class bezwzgl : public operator1arg {
    public:
        bezwzgl(wyrazenie* w) : operator1arg(w) {}
        double oblicz() { return std::fabs(wyraz->oblicz()); }
        std::string opis() { return "abs("+wyraz->opis()+")"; }
};

class przeciw : public operator1arg {
    public:
        przeciw(wyrazenie* w) : operator1arg(w) {}
        double oblicz() { return -1*wyraz->oblicz(); }
        std::string opis() { return "(-"+wyraz->opis()+")"; }
};

class odwrot : public operator1arg {
    public:
        odwrot(wyrazenie* w) : operator1arg(w) {}
        double oblicz() { return 1/wyraz->oblicz(); }
        std::string opis() { return "1/("+wyraz->opis()+")"; }
};
