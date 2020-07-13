#include "wielomian.hpp"

void wielomian::ustaw_wspolczynniki(const double wsp[]) {
    int i;
    for(i=0; i<=n; i++) {
        //std::cout<<"wspolczynnik nr "<<i<<" = "<<wsp[i]<<"\n";
        a[i]=wsp[i];
    }
}

int wielomian::stopien() {
    return n;
}

wielomian::wielomian(int st, double wsp) {
    n=st;
    a=new double[n+1];
    for(int i=0; i<=n;i++) {
        a[i]=wsp;
    }
}

wielomian::wielomian(int st, const double wsp[]) {
    if(wsp[st]==0 && st!=0) throw std::invalid_argument("Niepoprawne wspolczynniki");
    n=st;
    a=new double[st+1];
    ustaw_wspolczynniki(wsp);
}

wielomian::wielomian(std::initializer_list<double> wsp) : 
n(wsp.size()-1), a(new double[wsp.size()])
{
    std::initializer_list<double>::iterator i;
    int j=0;
    for (i=wsp.begin();i!=wsp.end();i++, j++) {
        if(j==n && (*i)==0) throw std::invalid_argument("Niepoprawne wspolczynniki");
        a[j]=(*i);
    }
    
}

wielomian::wielomian(const wielomian &w) {
    //std::cout<<"konstr. copy\n";
    *this = w;
}

wielomian::wielomian(wielomian &&w) {
    //std::cout<<"konstr. przenoszacy\n";
    *this = std::move(w);
}

wielomian::~wielomian() {
    a=nullptr;
    this->n=-1;
}

wielomian& wielomian::operator=(const wielomian &w) {
    if(this==&w) return *this;
    this->~wielomian();
    this->a=new double[w.n+1];
    this->n=w.n;
    std::copy(w.a, w.a+n+1, a);
    
    return *this;
}

wielomian& wielomian::operator=(wielomian &&w) {
    this->a=std::move(w.a);
    this->n=std::move(w.n);
    w.a=nullptr;
    w.n=-1;
    
    return *this;
}

std::ostream& operator<<(std::ostream &wy, const wielomian &w) {
    for(int i=w.n; i>=0; i--) {
        if(i!=0) wy<<w.a[i]<<"x^"<<i<<" + ";
        else wy<<w.a[i];
    }
    return wy;
}

std::istream& operator>>(std::istream &we, wielomian &w) {
    std::cout<<"Podaj stopien: ";
    we>>w.n;
    delete[] w.a;
    w.a = new double[w.n+1];
    for(int i=0; i<=w.n; i++) {
        we>>w.a[i];
        if((i==w.n) && (w.a[i]==0) && (i!=0)) throw std::invalid_argument("Niepoprawne wspolczynniki");
    }
    return we;
}

double wielomian::operator[](int i) const {
    if(i<0 || i>n) throw std::invalid_argument("Przekroczono zakres");
    return a[i];
}

double wielomian::operator()(double x) const {
    double val=a[0];
    for(int i=1; i<=n; i++) {
        val=val*x + a[i];
    }
    return val;
}

wielomian operator+(const wielomian &u, const wielomian &v) {
    wielomian tmp(u);
    tmp+=v;
    return tmp;
}

wielomian operator*(const wielomian &u, const wielomian &v) {
    wielomian tmp(u);
    tmp*=v;
    return tmp;
}
wielomian operator*(const wielomian &w, double c) {
    wielomian tmp(w);
    tmp*=c;
    return tmp;
}
wielomian operator-(const wielomian &w, const wielomian &v) {
    wielomian tmp(w);
    tmp-=v;
    return tmp;
}

wielomian& wielomian::operator+=(const wielomian &v) {
    int new_n, i;
    if(n<v.n) n=v.n;
    new_n=n;
    double *t = new double[n+1];
    for(i=0; i<=n; i++) {
        t[i]=a[i];
    }
    for(i=0; i<=v.n; i++) {
        t[i]+=v.a[i];
    }
    i=t[n];
    // jeśli współczynniki przy najwyższych potęgach się wyzerowały 
    // to zmienia stopień wielomianu
    while(i==0 && n>0) { 
        n--;
        i=t[n];
    }
    
    ustaw_wspolczynniki(t);
    delete[] t;
    return *this;
}
wielomian& wielomian::operator*=(double c) {
    if(c==0) {
        n=0;
        a[0]=0;
        return *this;
    }
    for(int i=0; i<=n; i++) {
        a[i]=a[i]*c;
        //std::cout<<"wspolczynnik nr "<<i<<" = "<<a[i]<<"\n";
    }
    return *this;
}
wielomian& wielomian::operator*=(const wielomian& v) {
    int old_n=n;
    n+=v.n;
    int i,j;
    double *t = new double[n+1];
    for(i=0; i<=n; i++) t[i]=0;
    for(i=0;i<=v.n;i++) {
        for(j=0;j<=old_n;j++) {
            t[i+j]=t[i+j]+(v.a[i]*a[j]);
        }
    }
    std::cout<<"n= "<<n<<"\n";
    while(t[n]==0 && n>0) {
        n--;
    }
    ustaw_wspolczynniki(t);
    delete[] t;
    return *this;
}

wielomian& wielomian::operator-=(const wielomian &v) {
    wielomian tmp = (v);
    tmp*=(-1);
    (*this)+=tmp;
    
    return *this;
}

