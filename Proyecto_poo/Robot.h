//
// Created by Wese on 1/11/2019.
//

#ifndef PROYECTO_POO_ROBOT_H
#define PROYECTO_POO_ROBOT_H
#include "Help.h"

class Robot {
private:
posicion Posicion_inicial;
number Numero_Robot;
tipo Producto;
posicion Posicion_destino;

public:
    Robot();
    void Ingresar();
    void Retirar();
    posicion Get_posicion_incial();
    void Set_posicion_inicial(number x , number y);
    posicion Get_posicion_destino();
    void Set_posicion_destino(number x, number y);
    number Get_numero_robot();
    void Set_numero_robot(number x);
    tipo Get_producto();
    void Set_producto(tipo x);

};


#endif //PROYECTO_POO_ROBOT_H
