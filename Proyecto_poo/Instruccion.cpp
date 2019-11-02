//
// Created by Wese on 1/11/2019.
//

#include "Instruccion.h"

Instruccion::Instruccion() {
Producto = "a";
Operacion = "a";
Posicion_destino = {0,0};
Numero_robot = 0;
}

void Instruccion::Set_numero_robot(number x) {
Numero_robot = x;
}

number Instruccion::Get_numero_robot() {
    return Numero_robot;
}

void Instruccion::Set_posicion_destino(number x, number y) {
Posicion_destino = {x,y};
}

number Instruccion::Get_posicion_destino() {
    return Posicion_destino;
}

void Instruccion::Set_operacion(tipo x) {
Operacion = x;
}

tipo Instruccion::Get_operacion() {
    return Operacion;
}

void Instruccion::Set_producto(tipo x) {
Producto = x;
}

tipo Instruccion::Get_producto() {
    return Producto;
}
