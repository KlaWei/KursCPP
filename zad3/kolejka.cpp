#include "kolejka.hpp"


kolejka::kolejka() :
    tab(new std::string[4]), pojemnosc(4), ile(0), poczatek(-1), koniec(-1) {}

kolejka::kolejka(int n) :
	tab(new std::string[n]), pojemnosc(n), ile(0), poczatek(-1), koniec(-1) {}

kolejka::kolejka(const kolejka &k) : tab(new std::string[k.pojemnosc]), 
 pojemnosc(k.pojemnosc), ile(k.ile), poczatek(k.poczatek) {
	
	std::cout<<"konstruktor kopiujacy\n";
	std::copy(k.tab, k.tab+k.pojemnosc, tab);
}

kolejka::kolejka(std::initializer_list<std::string> lista) :
 pojemnosc(lista.size()), tab(new std::string[lista.size()]),
 ile(lista.size()), poczatek(0), koniec(lista.size()-1) {
	
	std::initializer_list<std::string>::iterator i;
	int j=0;
	for (i=lista.begin();i!=lista.end();i++) {
		tab[j]=(*i);
		j++;
	}
}

kolejka::kolejka(kolejka &&k) : tab(std::move(k.tab)), 
 pojemnosc(std::move(k.pojemnosc)), ile(std::move(k.ile)),
 poczatek(std::move(k.poczatek)), koniec(std::move(k.koniec)) {
	std::cout<<"konstruktor przenoszacy\n";
	k.tab=nullptr;
	k.pojemnosc=0;
	k.ile=0;
	k.poczatek=-1;
	k.koniec=-1;
}

kolejka::~kolejka() {
	delete[] tab;
}	
	
kolejka& kolejka::operator=(kolejka &k) {
	std::cout<<"op kopiujacy\n";
	if (this==&k) return *this;
	this->~kolejka();
	this->tab = new std::string[k.pojemnosc];
	this->pojemnosc = k.pojemnosc;
	this->ile = k.ile;
	this->poczatek = k.poczatek;
	this->koniec = k.koniec;
	std::copy(k.tab, k.tab+k.pojemnosc, tab);
	return *this;
}

kolejka& kolejka::operator=(kolejka &&k) {
	std::cout<<"op przenoszacy\n";
	this->tab=std::move(k.tab);
	this->pojemnosc=std::move(k.pojemnosc);
	this->ile=std::move(k.ile);
	this->poczatek=std::move(k.poczatek);
	this->koniec = std::move(k.koniec);
	k.tab=nullptr;
	k.pojemnosc=0;
	k.ile=0;
	k.poczatek=-1;
	k.koniec=-1;
	
	return *this;
}

void kolejka::wstaw(std::string s) {
	if(ile==0) {
		poczatek=0;
		//koniec=0;
	}
	if(ile==pojemnosc) {
		throw std::string("Kolejka pelna!");
	};
	koniec = (koniec+1)%pojemnosc;
	//std::cout<<"koniec = "<<koniec<<"\n";
	tab[koniec]=s;
	ile++;
}
std::string kolejka::pobierz() {
	if(ile==0) {
		throw std::string("Kolejka pusta!");
	}
	std::string napis = tab[poczatek];
	//std::cout<<"poobrany: "<<napis<<", poczatek= "<<poczatek<<"\n";
	poczatek = (poczatek+1)%pojemnosc;
	ile--;
	return napis;
}
std::string kolejka::sprawdz() {
	if(ile==0) {
		throw std::string("Kolejka pusta!");
	}
	return tab[poczatek];
}

int kolejka::rozmiar() {
	return ile;
}

int kolejka::pojemnosc_k() {
	return pojemnosc;
}

void kolejka::wypisz() {
	int i;
	if(ile==0) return;
	if (poczatek <= koniec) {
		//std::cout<<"poczatek= "<<poczatek<<"\n";
		for (i=poczatek; i<=koniec; i++) {
			std::cout<<tab[i];
			if(i<koniec) std::cout<<", ";
		}
	}
	else {
		//std::cout<<"poczatek= "<<poczatek<<"\n";
		for (i=poczatek;i<pojemnosc;i++) {
			std::cout<<tab[i]<<", ";
		}
		for (i=0; i<=koniec; i++) {
			std::cout<<tab[i];
			if(i<koniec) std::cout<<", ";
		}
	}
	
	std::cout<<"\n";
}


