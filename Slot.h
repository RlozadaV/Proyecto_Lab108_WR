//
// Created by rloza on 28/11/2019.
//

#ifndef PROYECTOPOO_SLOT_H
#define PROYECTOPOO_SLOT_H
#include "Help.h"

class Slot {
private:
    posicion Posicion_almacen;
    tipo Producto;
    number Capacidad;
    tipo Estado;
public:
    Slot();
    void Set_posicion(number x, number y);
    posicion Get_posicion();
    void Set_estado(tipo x);
    tipo Get_estado();
    number Get_capacidad();
    void Set_capacidad (int x);
    void Set_tipo_producto(tipo x);
    tipo Get_tipo_producto();
};


#endif //PROYECTOPOO_SLOT_H
