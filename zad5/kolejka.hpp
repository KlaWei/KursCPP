#include "lista.hpp"

class kolejka : protected lista {
    
    public:
        kolejka();
        void wstaw(double v);
        double usun();
}