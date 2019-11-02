//
// Created by Wese on 1/11/2019.
//

#include "Slot.h"

Slot::Slot() {
Producto= "a";
Posicion_almacen = {0,0};
Estado = "Moderado";
Capacidad_maxima = 15;
}

posicion Slot::Get_posicion() {
    return Posicion_almacen;
}

void Slot::Set_posicion(number x, number y) {
Posicion_almacen = {x,y};
}

void Slot::Set_estado(tipo x) {
Estado = x;
}

tipo Slot::Get_estado() {
    return Estado;
}

number Slot::Get_capacidad() {
    return Capacidad_maxima;
}

void Slot::Set_tipo_producto(tipo x) {
Producto = x;
}

tipo Slot::Get_tipo_producto() {
    return Producto;

}
