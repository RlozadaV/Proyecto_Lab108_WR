//
// Created by Wese on 1/11/2019.
//

#include "Robot.h"

Robot::Robot() {
    Posicion_inicial = {0,0};
    Numero_Robot= 0;
    Producto = "a";
    Posicion_destino = {0,0};
}

void Robot::Ingresar() {

}

void Robot::Retirar() {

}

posicion Robot::Get_posicion_incial() {
    return Posicion_inicial;
}

void Robot::Set_posicion_inicial(number x, number y) {
    Posicion_inicial = {x,y};
}

posicion Robot::Get_posicion_destino() {
    return Posicion_destino;
}

void Robot::Set_posicion_destino(number x, number y) {
Posicion_destino = {x,y};
}

number Robot::Get_numero_robot() {
    return Numero_Robot;
}

void Robot::Set_numero_robot(number x) {
Numero_Robot = x;
}

tipo Robot::Get_producto() {
    return Producto;
}

void Robot::Set_producto(tipo x) {
Producto = x;
}
