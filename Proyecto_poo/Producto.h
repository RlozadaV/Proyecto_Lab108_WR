//
// Created by Wese on 1/11/2019.
//

#ifndef PROYECTO_POO_PRODUCTO_H
#define PROYECTO_POO_PRODUCTO_H
#include "Help.h"

class Producto {
private:
    posicion Posicion_almacen;
    tipo Tipo_producto;

public:
    Producto();
    void Set_tipo_producto(tipo x);
    tipo Get_tipo_producto();
    void Set_posicion_almacen(number x, number y);
    posicion Get_posicion_almacen();
};


#endif //PROYECTO_POO_PRODUCTO_H
