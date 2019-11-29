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
}

number Almacen::Get_largo() {
    return Largo_almacen;
}

void Almacen::Set_ancho(number x) {
Ancho_almacen = x;
}

vector<Slot> Almacen::Get_slots() {
    return Slots;
}

void Almacen::Add_slot(tipo producto,number x,number y) {
Slot i;
i.Set_tipo_producto(producto);
i.Set_posicion(x,y);
Slots.push_back(i);

}

number Almacen::Get_ancho() {
    return Ancho_almacen;
}
