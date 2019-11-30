//
// Created by rloza on 28/11/2019.
//

#include "Almacen.h"

Almacen::Almacen() {
Ancho_almacen = 0;
Largo_almacen = 0;
}

void Almacen::Set_largo(number x) {
Largo_almacen = x;
vector<Slot> fila= {};

}

number Almacen::Get_largo() {
    return Largo_almacen;
}

void Almacen::Set_ancho(number x) {
Ancho_almacen = x;
}


number Almacen::Get_ancho() {
    return Ancho_almacen;
}
