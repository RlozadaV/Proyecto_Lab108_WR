#include <iostream>
#include "Help.h"
#include "Robot.h"
#include "Instruccion.h"
#include "Almacen.h"
#include <chrono>
#include <thread>
#include <cmath>

void dibujar_robots (Almacen mapa, int numero_de_robots, vector<Robot> Robots){
    for (int i = 0 ; i< mapa.Get_largo();i++) {
        cout << "\n";
        for (int j = 0; j < mapa.Get_ancho(); j++) {
            int val = 0;
                if (i == Robots[0].Get_posicion_actual()[0] && j == Robots[0].Get_posicion_actual()[1]) {
                    val = val + 1;
                }
            if (val > 0) {
                cout << "|o|";
            } else {
                cout << "[ ]";
            }
        }
    }
}

int main() {
    int ancho = 0;
    int largo = 0;
    cout << "Ancho del almacen:";
    cin >> ancho;
    cout << "Largo del almacen:";
    cin >> largo;
    Almacen mapa;
    mapa.Set_ancho(ancho);
    mapa.Set_largo(largo);
    string n = "nada";
    vector<vector<Slot>> Slots;
    for (int i = 0; i < mapa.Get_largo(); i++) {
        vector<Slot> m = {};
        Slots.push_back(m);
    }
    for (int i = 0; i < mapa.Get_largo(); i++) {
        for (int j = 0; j < mapa.Get_ancho(); j++) {
            Slot f;
            f.Set_tipo_producto(n);
            f.Set_posicion(i, j);
            Slots[j].push_back(f);
        }
    }


    vector<Robot> Robots;
    int numero_de_robots = 0;
    cout << "\nNumero de robots: ";
    cin >> numero_de_robots;
    for (int i = 0; i < numero_de_robots; i++) {
        Robot r;
        Robots.push_back(r);
        cout << "\nPosicion del robot #" << i << ": ";
        int x = 0;
        int y = 0;
        cout << endl;
        cin >> x;
        cin >> y;
        if (x > mapa.Get_largo() - 1 || y > mapa.Get_ancho() - 1) {
            cout << "No puede tener una posicion afuera del almacen";
            return 0;
        }
        int b = 0;
        for (int j = 0; j < i; j++) {
            if (x == Robots[j].Get_posicion_inicial()[0] && y == Robots[j].Get_posicion_inicial()[1]) {
                b = b + 1;
            }
        }
        if (b > 0) {
            cout << "Los robots no pueden tener la misma posicion inicial";
            return 0;
        } else {
            Robots[i].Set_posicion_inicial(x, y);
        }

    }
    int numero_de_instrucciones = 0;
    cout << "\nNumero de instrucciones:";
    cin >> numero_de_instrucciones;
    for (int i = 0; i < numero_de_instrucciones; i++) {
        int numero_robot = 0;
        cout << "\nNumero del robot:";
        cin >> numero_robot;
        if (numero_robot > numero_de_robots - 1) {
            cout << "La instruccion no es valida. Esta instruccion se omitira.";
        } else {
            string operacion = "n";
            cout << "\nIngrese tipo de operacion:";
            cin >> operacion;
            if (operacion == "Ingresar") {
                int x = 0;
                int y = 0;
                cout << "\nIngrese destino del robot:";
                cin >> x >> y;
                if (x > mapa.Get_largo() - 1 || y > mapa.Get_ancho() - 1) {
                    cout << "La instruccion no es valida. Esta instruccion se omitira.";
                }
                if (x == Robots[numero_robot].Get_posicion_inicial()[0] ||
                    y == Robots[numero_robot].Get_posicion_inicial()[1]) {
                    cout << "La instruccion no es valida. Esta instruccion se omitira.";
                }
                string producto;
                cout << "\nIngrese producto de manejo:";
                cin >> producto;

                if (Slots[x][y].Get_tipo_producto() == producto) {
                    if (Slots[x][y].Get_capacidad() >= 10) {
                        cout << "El slot esta lleno, no se puede realizar instruccion";
                    } else {
                        int nc = Slots[x][y].Get_capacidad() + 1;
                        Slots[x][y].Set_capacidad(nc);
                        Robots[numero_robot].Agregar_instruccion(operacion, x, y, producto);
                    }
                }
                if (Slots[x][y].Get_tipo_producto() == "nada") {
                    Slots[x][y].Set_tipo_producto(producto);
                    int nc = Slots[x][y].Get_capacidad() + 1;
                    Slots[x][y].Set_capacidad(nc);
                    Robots[numero_robot].Agregar_instruccion(operacion, x, y, producto);
                }
                if (Slots[x][y].Get_tipo_producto() != producto) {
                    cout << "No maneja el mismo tipo de producto, la instruccion no es valida";
                }
            }
            if (operacion == "Retirar") {
                int x = 0;
                int y = 0;
                cout << "\nIngrese detino del robot:";
                cin >> x >> y;
                if (x > mapa.Get_largo() - 1 || y > mapa.Get_ancho() - 1) {
                    cout << "La instruccion no es valida. Esta instruccion se omitira.";
                }
                if (x == Robots[numero_robot].Get_posicion_inicial()[0] &&
                    y == Robots[numero_robot].Get_posicion_inicial()[1]) {
                    cout << "La instruccion no es valida. Esta instruccion se omitira.";
                }
                string producto;
                cout << "\nIngrese producto de manejo:";
                cin >> producto;

                if (Slots[x][y].Get_tipo_producto() == producto) {
                    if (Slots[x][y].Get_capacidad() <= 0) {
                        cout << "El slot esta vacio, no se puede realizar instruccion";
                    } else {
                        int nc = Slots[x][y].Get_capacidad() - 1;
                        Slots[x][y].Set_capacidad(nc);
                        Robots[numero_robot].Agregar_instruccion(operacion, x, y, producto);
                    }
                }
                if (Slots[x][y].Get_tipo_producto() == "nada") {
                    Slots[x][y].Set_tipo_producto(producto);
                    int nc = Slots[x][y].Get_capacidad() - 1;
                    Slots[x][y].Set_capacidad(nc);
                    Robots[numero_robot].Agregar_instruccion(operacion, x, y, producto);
                }
                if (Slots[x][y].Get_tipo_producto() != producto) {
                    cout << "No maneja el mismo tipo de producto, la instruccion no es valida";
                }
            }
            if (operacion != "Ingresar" && operacion != "Retirar") {
                cout << "La operacion no es valida. Esta instruccion se omitira.";
            }
        }
    }
    for (int i = 0; i < mapa.Get_largo(); i++) {
        cout << "\n";
        for (int j = 0; j < mapa.Get_ancho(); j++) {
            int val = 0;
            for (int k = 0; k < numero_de_robots; k++) {
                if (i == Robots[k].Get_posicion_inicial()[0] && j == Robots[k].Get_posicion_inicial()[1]) {
                    val = val + 1;
                }
            }
            if (val > 0) {
                cout << "|o|";
            } else {
                cout << "[ ]";
            }
        }
    }

    for (int i = 0; i < mapa.Get_largo(); i++) {
        for (int j = 0; j < mapa.Get_ancho(); j++) {
            if (Slots[i][j].Get_tipo_producto() != "nada"){

                cout<<"\n\nPosicion de slot: "<<i<<","<<j<<"\n"<<"Numero de productos: "<<Slots[i][j].Get_capacidad()<<"\nProducto que maneja: "<<Slots[i][j].Get_tipo_producto();
            }
        }
    }

    for (int a = 0; a<numero_de_robots; a++){
        if (!Robots[a].Get_instruccion().empty()){
            cout<<"\n\nMovimiento de Robot #"<<a<<":";
            int f = Robots[a].Get_instruccion().size();
            for (int q = 0; q< f; q++){
                if (Robots[a].Get_instruccion()[0].Get_operacion() == "Ingresar"){
                    vector<vector<int>> mov= {};
                    vector<int> posa = Robots[a].Get_posicion_actual();
                    vector<int> posd = Robots[a].Get_posicion_inicial();
                    if (posa == posd){
                        mov.push_back(posa);
                    }
                    if (posa != posd){
                        for (int i = 1; i< abs(posd[0]-posa[0])+1; i++){
                            if (posd[0]-posa[0]>0){
                                vector<int> m = {posa[0]+i,posa[1]};
                                mov.push_back(m);
                            }
                            if (posd[0]-posa[0]<0){
                                vector<int> m = {posa[0]-i,posa[1]};
                                mov.push_back(m);
                            }
                        }
                        for (int j = 1; j< abs(posd[1]-posa[1])+1; j++) {
                            if (posd[1] - posa[1] > 0) {
                                vector<int> m = {posa[0] + (posd[0] - posa[0]), posa[1] + j};
                                mov.push_back(m);
                            }
                            if (posd[1] - posa[1] < 0) {
                                vector<int> m = {posa[0] + (posd[0] - posa[0]), posa[1] - j};
                                mov.push_back(m);
                            }
                        }
                    }
                    int r = mov.size() -1;
                    Robots[a].Set_posicion_actual(mov[r][0],mov[r][1]);
                    posa = Robots[a].Get_posicion_actual();
                    posd = Robots[a].Get_instruccion()[0].Get_posicion_destino();
                    if (posa == posd){
                        mov.push_back(posa);
                    }
                    if (posa != posd){
                        for (int i = 1; i< abs(posd[0]-posa[0])+1; i++){
                            if (posd[0]-posa[0]>0){
                                vector<int> m = {posa[0]+i,posa[1]};
                                mov.push_back(m);
                            }
                            if (posd[0]-posa[0]<0){
                                vector<int> m = {posa[0]-i,posa[1]};
                                mov.push_back(m);
                            }
                        }
                        for (int j = 1; j< abs(posd[1]-posa[1])+1; j++) {
                            if (posd[1] - posa[1] > 0) {
                                vector<int> m = {posa[0] + (posd[0] - posa[0]), posa[1] + j};
                                mov.push_back(m);
                            }
                            if (posd[1] - posa[1] < 0) {
                                vector<int> m = {posa[0] + (posd[0] - posa[0]), posa[1] - j};
                                mov.push_back(m);
                            }
                        }
                        r = mov.size() -1;
                        Robots[a].Set_posicion_actual(mov[r][0],mov[r][1]);
                    }
                    vector<vector<int>> x = mov;
                    for (int z = 0; z< x.size();z++ ){
                        cout<<"\n";
                        cout<<x[z][0]<<","<<x[z][1];
                    }
                    Robots[a].Quitar_intruccion();
                }
                else{
                    vector<vector<int>> mov = {};
                    vector<int> posa = Robots[a].Get_posicion_actual();
                    vector<int> posd = Robots[a].Get_instruccion()[0].Get_posicion_destino();
                    if (posa == posd){
                        mov.push_back(posa);
                    }
                    else{
                        for (int i = 1; i< abs(posd[0]-posa[0])+1; i++){
                            if (posd[0]-posa[0]>0){
                                vector<int> m = {posa[0]+i,posa[1]};
                                mov.push_back(m);
                            }
                            if (posd[0]-posa[0]<0){
                                vector<int> m = {posa[0]-i,posa[1]};
                                mov.push_back(m);
                            }
                        }
                        for (int j = 1; j< abs(posd[1]-posa[1])+1; j++) {
                            if (posd[1] - posa[1] > 0) {
                                vector<int> m = {posa[0] + (posd[0] - posa[0]), posa[1] + j};
                                mov.push_back(m);
                            }
                            if (posd[1] - posa[1] < 0) {
                                vector<int> m = {posa[0] + (posd[0] - posa[0]), posa[1] - j};
                                mov.push_back(m);
                            }
                        }
                    }
                    int r = mov.size() -1;
                    Robots[a].Set_posicion_actual(mov[r][0],mov[r][1]);
                    posa = Robots[a].Get_posicion_actual();
                    posd = Robots[a].Get_posicion_inicial();
                    if (posa == posd){
                        mov.push_back(posa);
                    }
                    else{
                        for (int i = 1; i< abs(posd[0]-posa[0])+1; i++){
                            if (posd[0]-posa[0]>0){
                                vector<int> m = {posa[0]+i,posa[1]};
                                mov.push_back(m);
                            }
                            if (posd[0]-posa[0]<0){
                                vector<int> m = {posa[0]-i,posa[1]};
                                mov.push_back(m);
                            }
                        }
                        for (int j = 1; j< abs(posd[1]-posa[1])+1; j++) {
                            if (posd[1] - posa[1] > 0) {
                                vector<int> m = {posa[0] + (posd[0] - posa[0]), posa[1] + j};
                                mov.push_back(m);
                            }
                            if (posd[1] - posa[1] < 0) {
                                vector<int> m = {posa[0] + (posd[0] - posa[0]), posa[1] - j};
                                mov.push_back(m);
                            }
                        }
                        r = mov.size() -1;
                        Robots[a].Set_posicion_actual(mov[r][0],mov[r][1]);
                    }
                    vector<vector<int>> x = mov;
                    for (int z = 0; z< x.size();z++ ){
                        cout<<"\n";
                        cout<<x[z][0]<<","<<x[z][1];
                    }
                    Robots[a].Quitar_intruccion();
                }
            }
        }
    }


    return 0;
}