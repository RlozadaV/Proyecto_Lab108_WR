//
// Created by Wese on 1/11/2019.
//

#ifndef PROYECTO_POO_ALMACEN_H
#define PROYECTO_POO_ALMACEN_H
#include "Help.h"


class Almacen {
private:
    number Largo_alamacen;
    number Ancho_almacen;
public:
    Almacen();
    void Set_largo(number x);
    number Get_largo();
    void Set_ancho(number x);
    number Get_ancho();

};


#endif //PROYECTO_POO_ALMACEN_H
