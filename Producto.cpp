//
// Created by rloza on 28/11/2019.
//

#include "Producto.h"

Producto::Producto() {
Posicion_almacen = {0,0};
Tipo_producto = "a";
}

void Producto::Set_tipo_producto(tipo x) {
Tipo_producto = x;
}

tipo Producto::Get_tipo_producto() {
    return Tipo_producto;
}

void Producto::Set_posicion_almacen(number x, number y) {
Posicion_almacen = {x,y};
}

posicion Producto::Get_posicion_almacen() {
    return Posicion_almacen;
}
