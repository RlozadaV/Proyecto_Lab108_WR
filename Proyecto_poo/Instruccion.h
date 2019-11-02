//
// Created by Wese on 1/11/2019.
//

#ifndef PROYECTO_POO_INSTRUCCION_H
#define PROYECTO_POO_INSTRUCCION_H
#include "Help.h"

class Instruccion {
private:
    number instruccion;
    number Numero_robot;
    tipo Operacion;
    number Posicion_destino;
    tipo Producto;

public:
    Instruccion();
    void Set_numero_robot(number x);
    number Get_numero_robot();
    void Set_posicion_destino(number x, number y);
    number Get_posicion_destino();
    void Set_operacion(tipo x);
    tipo Get_operacion();
    void Set_producto(tipo x);
    tipo Get_producto();

};


#endif //PROYECTO_POO_INSTRUCCION_H
