//
// Created by rloza on 28/11/2019.
//

#ifndef PROYECTOPOO_INSTRUCCION_H
#define PROYECTOPOO_INSTRUCCION_H
#include "Help.h"

class Instruccion {
private:
    tipo Operacion;
    vector<number> Posicion_destino;
    tipo Producto;
public:
    Instruccion();
    void Set_posicion_destino(number x, number y);
    vector<number> Get_posicion_destino();
    void Set_operacion(tipo x);
    tipo Get_operacion();
    void Set_producto(tipo x);
    tipo Get_producto();
};


#endif //PROYECTOPOO_INSTRUCCION_H
