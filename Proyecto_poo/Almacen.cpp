
//
// Created by Wese on 1/11/2019.
//

#include "Almacen.h"

Almacen::Almacen() {
Ancho_almacen = 0;
Largo_alamacen = 0;
}

void Almacen::Set_largo(number x) {
Largo_alamacen = x;
}

number Almacen::Get_largo() {
    return Largo_alamacen;
}

void Almacen::Set_ancho(number x) {
Ancho_almacen = x;
}

number Almacen::Get_ancho() {
    return Ancho_almacen;
}
