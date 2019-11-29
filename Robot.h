//
// Created by rloza on 28/11/2019.
//

#ifndef PROYECTOPOO_ROBOT_H
#define PROYECTOPOO_ROBOT_H
#include "Help.h"
#include "Instruccion.h"

class Robot {
private:
    posicion Posicion_inicial;
    posicion Posicion_actual;
    number Numero_robot;
    vector<Instruccion> Instrucciones;
public:
    Robot();
    void Ingresar();
    void Retirar();
    posicion Get_posicion_inicial();
    void Set_posicion_inicial(number x, number y);
    number Get_numero_robot();
    void Set_numero_robot(number x);
    void Agregar_instruccion(string operacion, number x, number y, string producto);
    Instruccion Get_instruccion(number x);
    posicion Get_posicion_actual();
    void Set_posicion_actual(number x, number y);
};


#endif //PROYECTOPOO_ROBOT_H
