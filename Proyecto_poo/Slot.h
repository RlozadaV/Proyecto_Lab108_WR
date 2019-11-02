//
// Created by Wese on 1/11/2019.
//

#ifndef PROYECTO_POO_SLOT_H
#define PROYECTO_POO_SLOT_H
#include"Help.h"

class Slot {
private:
    posicion Posicion_almacen;
    tipo Producto;
    number Capacidad_maxima;
    tipo Estado;

public:
    Slot();
    void Set_posicion(number x, number y);
    posicion Get_posicion();
    void Set_estado(tipo x);
    tipo Get_estado();
    number Get_capacidad();
    void Set_tipo_producto(tipo x);
    tipo Get_tipo_producto();
};


#endif //PROYECTO_POO_SLOT_H
