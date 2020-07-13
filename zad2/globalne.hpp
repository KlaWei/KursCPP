#ifndef globalne_hpp
#define globalne_hpp

#include "punkt.hpp"
#include "trojkat.hpp"
#include "odcinek.hpp"

double odleglosc_pkt(punkt a, punkt b);
bool wew_trojkata(punkt p, trojkat t);
bool odcinki_rownolegle(odcinek odc1, odcinek odc2);
bool odcinki_prostopadle(odcinek odc1, odcinek odc2);
punkt pkt_przeciecia(odcinek odc1, odcinek odc2);
bool zawieranie_trojkatow(trojkat t1, trojkat t2);
bool trojkaty_rozlaczne(trojkat t1, trojkat t2);


#endif /* globalne_hpp */
