//
// Created by rloza on 28/11/2019.
//

#include "Instruccion.h"

Instruccion::Instruccion() {
Producto = "a";
Operacion = "a";
}

void Instruccion::Set_posicion_destino(number x, number y) {
Posicion_destino = {x,y};
}

vector<number> Instruccion::Get_posicion_destino() {
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
