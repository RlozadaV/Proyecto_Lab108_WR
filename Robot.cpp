//
// Created by rloza on 28/11/2019.
//

#include "Robot.h"

Robot::Robot() {
Posicion_inicial = {0,0};
Posicion_actual = {0,0};
Numero_robot = 0;
Instrucciones = {};
}

void Robot::Ingresar() {

}

void Robot::Retirar() {

}

posicion Robot::Get_posicion_inicial() {
    return Posicion_inicial;
}

void Robot::Set_posicion_inicial(number x, number y) {
Posicion_inicial = {x,y};
}

number Robot::Get_numero_robot() {
    return Numero_robot;
}

void Robot::Set_numero_robot(number x) {
Numero_robot = x;
}

void Robot::Agregar_instruccion(string operacion, number x, number y, string producto) {
Instruccion i;
i.Set_operacion(operacion);
i.Set_posicion_destino(x,y);
i.Set_producto(producto);
Instrucciones.push_back(i);
}

Instruccion Robot::Get_instruccion(number x) {
    return Instrucciones[x];
}

posicion Robot::Get_posicion_actual() {
    return Posicion_actual;
}

void Robot::Set_posicion_actual(number x, number y) {
Posicion_actual = {x,y};
}
