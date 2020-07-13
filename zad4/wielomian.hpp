#include <iostream>
#include <initializer_list>

class wielomian {
    private:
        int n; //stopień
        double *a; //współczynniki
        void ustaw_wspolczynniki(const double wsp[]);
    public:
        wielomian(int st=0, double wsp=1.0);
        //wielomian(int st, double wsp);
        wielomian(int st, const double wsp[]);
        wielomian(std::initializer_list<double> wsp);
        wielomian(const wielomian &w);
        wielomian(wielomian &&w);
        wielomian& operator = (const wielomian &w);
        wielomian& operator = (wielomian &&w);
        ~wielomian();
        
        int stopien();
        friend std::istream& operator >> (std::istream &we, wielomian &w);
        friend std::ostream& operator << (std::ostream &wy, const wielomian &w);
        friend wielomian operator + (const wielomian &u, const wielomian &v);
        friend wielomian operator - (const wielomian &u, const wielomian &v);
        friend wielomian operator * (const wielomian &u, const wielomian &v);
        friend wielomian operator * (const wielomian & w, double c);
        wielomian& operator += (const wielomian &v);
        wielomian& operator -= (const wielomian &v);
        wielomian& operator *= (const wielomian &v);
        wielomian& operator *= (double c);
        double operator () (double x) const; // obliczenie wartości wielomianu w x-sie
        double operator [] (int i) const; // i-ty współczynnik
};