//
// Created by rloza on 28/11/2019.
//

#ifndef PROYECTOPOO_ALMACEN_H
#define PROYECTOPOO_ALMACEN_H
#include "Help.h"
#include "Slot.h"

class Almacen {
private:
    number Largo_almacen;
    number Ancho_almacen;
    vector<Slot> Slots;
public:
    Almacen();
    void Set_largo(number x);
    number Get_largo();
    void Set_ancho(number x);
    number Get_ancho();
    vector<Slot> Get_slots();
    void Add_slot (tipo producto, number x, number y);
};


#endif //PROYECTOPOO_ALMACEN_H
