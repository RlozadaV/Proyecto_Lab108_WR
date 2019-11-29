//
// Created by rloza on 28/11/2019.
//

#include "Slot.h"

Slot::Slot() {
Producto = "a";
Posicion_almacen = {0,0};
Estado = "Moderado";
Capacidad = 10;
}

void Slot::Set_capacidad(int x) {
    Capacidad = x;
    if (Capacidad >= 10){
        Estado = "Lleno";
    }
    if (Capacidad <= 0){
        Estado = "Vacio";
    }
    if (Capacidad>0 && Capacidad<10){
        Estado = "Moderado";
    }
}

void Slot::Set_posicion(number x, number y) {
Posicion_almacen = {x,y};
}

posicion Slot::Get_posicion() {
    return Posicion_almacen;
}

void Slot::Set_estado(tipo x) {
Estado = x;
}

tipo Slot::Get_estado() {
    return Estado;
}

number Slot::Get_capacidad() {
    return Capacidad;
}

void Slot::Set_tipo_producto(tipo x) {
Producto = x;
}

tipo Slot::Get_tipo_producto() {
    return Producto;
}
