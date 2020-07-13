#include "globalne.hpp"

double odleglosc_pkt(punkt a, punkt b) {
    return sqrt((b.X()-a.X())*(b.X()-a.X()) + (b.Y()-a.Y())*(b.Y()-a.Y()));
}

void wypisz_trojkat2(trojkat t) {
    std::cout<<"T A("<<t.A().X()<<", "<<t.A().Y()<<"), B("<<t.B().X()<<", "<<
    t.B().Y()<<"), C("<<t.C().X()<<", "<<t.C().Y()<<")\n";
}

bool wew_trojkata(punkt p, trojkat t) {
    //std::cout<<"przec punkt: "<<t.A().X()<<", "<<t.A().Y()<<"\n";
    if((p.X()==t.A().X() && p.Y()==t.A().Y()) ||
       (p.X()==t.B().X() && p.Y()==t.B().Y()) ||
       (p.X()==t.C().X() && p.Y()==t.C().Y())) return true;
    
    odcinek odc1, odc2, odc3;
    odc1=odcinek(t.A(), t.B());
    odc2=odcinek(t.A(), t.C());
    odc3=odcinek(t.B(), t.C());
    if(odc1.nalezy_do_odc(p) || odc2.nalezy_do_odc(p) || odc3.nalezy_do_odc(p))
    return true;
    
    trojkat t1, t2, t3;
    try {
        t1=trojkat(t.A(), t.B(), p);
        t2=trojkat(t.A(), t.C(), p);
        t3=trojkat(t.B(), t.C(), p);
    } catch(std::string msg) {
        return false;
    }
    double p1=t1.pole()+t2.pole()+t3.pole(), p2=t.pole();
    //std::cout<<p1<<" p1-p2 "<<p1-p2<<" "<<p2<<"\n";
    if(fabs(p1-p2) < eps) {
        return true;
    }
    else return false;
}

bool odcinki_rownolegle(odcinek odc1, odcinek odc2) {
    double wsp_kier1 = (odc1.A().Y()-odc1.B().Y())/(odc1.A().X()-odc1.B().X());
    double wsp_kier2 = (odc2.A().Y()-odc2.B().Y())/(odc2.A().X()-odc2.B().X());
    if(fabs(wsp_kier1-wsp_kier2) < eps) return true;
    else return false;
}

bool odcinki_prostopadle(odcinek odc1, odcinek odc2) {
    /*double wsp_kier1 = (odc1.A().Y()-odc1.B().Y())/(odc1.A().X()-odc1.B().X());
     double wsp_kier2 = (odc2.A().Y()-odc2.B().Y())/(odc2.A().X()-odc2.B().X());*/
    double il_sk=(odc1.A().Y()-odc1.B().Y())*(odc2.A().Y()-odc2.B().Y()) +
    (odc1.A().X()-odc1.B().X())*(odc2.A().X()-odc2.B().X());
    std::cout<<il_sk<<"\n";
    if(fabs(il_sk) < eps) return true;
    return false;
}

// metoda Cramera, każdy punkt na odcinku można przedstawić jako
// A(x1, y1) B(x2, y2) jako x=x1 + (x2-x1)*s, y=y1+(y2-y1)*s
punkt pkt_przeciecia(odcinek odc1, odcinek odc2) {
    double s, t;
    double w = (odc1.B().X()-odc1.A().X())*(odc2.A().Y()-odc2.B().Y()) +
    (odc2.B().X()-odc2.A().X())*(odc1.B().Y()-odc1.A().Y());
    
    double ws = (odc2.A().X()-odc1.A().X())*(odc2.A().Y()-odc2.B().Y()) +
    (odc2.B().X()-odc2.A().X())*(odc2.A().Y()-odc1.A().Y());
    
    double wt = (odc1.B().X()-odc1.A().X())*(odc2.A().Y()-odc1.A().Y()) -
    (odc2.A().X()-odc1.A().X())*(odc1.B().Y()-odc1.A().Y());
    
    if(fabs(w)<eps)
        throw std::string("Odcinki rownolegle.");
    
    if(fabs(w)<eps && fabs(ws)<eps && fabs(wt)<eps)
        throw std::string("Odcinki takie same.");
    
    s = ws/w;
    t = wt/w;
    if(s>1 || s<0 || t>1 || t<0)
        throw std::string("Odcinki sie nie przecinaja.");
    
    return punkt(odc1.A().X() + s*(odc1.B().X()-odc1.A().X()),
                 odc1.A().Y() + s*(odc1.B().Y()-odc1.A().Y()));
    
}

bool czy_przecinaja(odcinek odc1, odcinek odc2) {
    punkt p;
    try {
        p=pkt_przeciecia(odc1, odc2);
    } catch (std::string msg) {
        if(msg=="Odcinki takie same.") return true;
        return false;
    }
    std::cout<<"odcinek: "<<odc1.A().X()<<", "<<odc1.A().Y()<<" . "<<odc1.B().X()<<
               ", "<<odc1.B().Y()<<" przecina sie z: "<<odc2.A().X()<<", "<<odc2.A().Y()<<
               " . "<<odc2.B().X()<<", "<<odc2.B().Y()<<" w punkcie: "<<p.X()<<", "<<p.Y()<<"\n";
    return true;
}

bool zawieranie_trojkatow(trojkat t1, trojkat t2) {
    wypisz_trojkat2(t1);
    wypisz_trojkat2(t2);
    
    
   /* if(wew_trojkata(t1.A(), t2)) {
        std::cout<<"wew t2 punkt: "<<t1.A().X()<<", "<<t1.A().Y()<<"\n";
    }
    if(wew_trojkata(t2.A(), t1)) {
        std::cout<<"wew t1 punkt: "<<t1.A().X()<<", "<<t1.A().Y()<<"\n";
    }
    if(wew_trojkata(t1.B(), t2)) {
        std::cout<<"wew t2 punkt: "<<t1.A().X()<<", "<<t1.A().Y()<<"\n";
    }*/
    if(((wew_trojkata(t1.A(), t2) && wew_trojkata(t1.B(), t2) && wew_trojkata(t1.C(), t2)) ||
       (wew_trojkata(t2.A(), t1) && wew_trojkata(t2.B(), t1) && wew_trojkata(t2.C(), t1)))) {
        
        std::cout<<"Zawieraja sie..\n";
        return true;
    }
    return false;
    
}

bool trojkaty_rozlaczne(trojkat t1, trojkat t2) {
    odcinek a_t1=odcinek(t1.A(), t1.B()), b_t1=odcinek(t1.A(), t1.C()),
    c_t1=odcinek(t1.B(), t1.C());
    odcinek a_t2=odcinek(t2.A(), t2.B()), b_t2=odcinek(t2.A(), t2.C()),
    c_t2=odcinek(t2.B(), t2.C());
    if(czy_przecinaja(a_t1, a_t2) || czy_przecinaja(a_t1, b_t2) ||
       czy_przecinaja(a_t1, c_t2) || czy_przecinaja(b_t1, a_t2) ||
       czy_przecinaja(b_t1, b_t2) || czy_przecinaja(b_t1, c_t2) ||
       czy_przecinaja(c_t1, a_t2) || czy_przecinaja(c_t1, b_t2) ||
       czy_przecinaja(c_t1, c_t2) || zawieranie_trojkatow(t1, t2)) return false;
    
    return true;
}
