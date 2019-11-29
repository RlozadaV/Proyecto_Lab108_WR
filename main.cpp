#include <iostream>
#include "Help.h"
#include "Robot.h"
#include "Instruccion.h"
#include "Almacen.h"

int main() {
    int ancho = 0;
    int largo = 0;
    cout<<"Ancho del almacen:";cin>>ancho;
    cout<<"Largo del almacen:";cin>>largo;
    Almacen mapa;
    mapa.Set_ancho(ancho);
    mapa.Set_largo(largo);
    vector<Robot> Robots;
    int numero_de_robots = 0;
    cout<<"\nNumero de robots: "; cin>> numero_de_robots;
    for (int i = 0; i<numero_de_robots; i++){
        Robot r;
        Robots.push_back(r);
        cout<<"\nPosicion del robot #"<<i <<": ";
        int x = 0;
        int y = 0;
        cout << endl;
        cin>>x;
        cin>>y;
        if (x> mapa.Get_largo()-1||y>mapa.Get_ancho()-1){
            cout<<"No puede tener una posicion afuera del almacen";
            return  0;
        }
        int b = 0;
        for (int j = 0; j< i; j++){
            if (x == Robots[j].Get_posicion_inicial()[0] && y == Robots[j].Get_posicion_inicial()[1]){
                b = b + 1;
            }
        }
        if (b >0){
            cout<<"Los robots no pueden tener la misma posicion inicial";
            return  0;
        }
        else{
            Robots[i].Set_posicion_inicial(x,y);
        }

    }
    int numero_de_instrucciones = 0;
    cout<<"\nNumero de instrucciones:";cin>> numero_de_instrucciones;
    for(int i = 0; i< numero_de_instrucciones;i++){
        int numero_robot = 0;
        cout<<"\nNumero del robot:"; cin>> numero_robot;
        if (numero_robot > numero_de_robots - 1){
            cout<<"La instruccion no es valida. Esta instruccion se omitira.";
        }
        else{
            string operacion = "n";
            cout<<"\nIngrese tipo de operacion:"; cin>> operacion;
            if (operacion == "Ingresar" || operacion == "Retirar"){
                int x = 0;
                int y = 0;
                cout<<"\nIngrese detino del robot:"; cin>>x>>y;
                if (x>mapa.Get_ancho()-1 || y>mapa.Get_largo()-1){
                    cout<<"La instruccion no es valida. Esta instruccion se omitira.";
                }
                if (x == Robots[numero_robot].Get_posicion_inicial()[0] || y == Robots[numero_robot].Get_posicion_inicial()[1]){
                    cout<<"La instruccion no es valida. Esta instruccion se omitira.";
                }
                else{
                    string producto;
                    cout<<"\nIngrese producto de manejo:";cin>>producto;
                    if (mapa.Get_slots().size() != 0){
                        for (int n = 0; n<mapa.Get_slots().size(); n++){
                            if (mapa.Get_slots()[n].Get_posicion()[0]==x && mapa.Get_slots()[n].Get_posicion()[1] == y){
                                if (producto == mapa.Get_slots()[n].Get_tipo_producto()){
                                    if (operacion == "Ingresar"){
                                        if (mapa.Get_slots()[n].Get_capacidad() >= 10){
                                            cout<<"No se puede realizar la instruccion, se ignorara";
                                        }
                                        else{
                                            mapa.Get_slots()[n].Set_capacidad(mapa.Get_slots()[n].Get_capacidad() + 1);
                                            Robots[numero_robot].Agregar_instruccion(operacion,x,y,producto);
                                        }

                                    }
                                    if (operacion == "Retirar"){
                                        if (mapa.Get_slots()[n].Get_capacidad() <= 0){
                                            cout<<"No se puede realizar la instruccion, se ignorara";
                                        }
                                        else{
                                            mapa.Get_slots()[n].Set_capacidad(-1 + mapa.Get_slots()[n].Get_capacidad());
                                            Robots[numero_robot].Agregar_instruccion(operacion,x,y,producto);
                                        }
                                    }
                                }
                                else{
                                    cout<<"La instruccion no es valida. Esta instruccion se omitira.";
                                }
                            }
                            else{
                                Robots[numero_robot].Agregar_instruccion(operacion,x,y,producto);
                                mapa.Add_slot(producto,x,y);
                                if (operacion == "Ingresar"){
                                    mapa.Get_slots()[n].Set_capacidad(1+ mapa.Get_slots()[n].Get_capacidad());
                                }
                                else
                                    mapa.Get_slots()[n].Set_capacidad(-1 + mapa.Get_slots()[n].Get_capacidad());
                            }
                        }
                    }
                    if (mapa.Get_slots().size() == 0){
                        Robots[numero_robot].Agregar_instruccion(operacion,x,y,producto);
                        mapa.Add_slot(producto,x,y);
                        if (operacion == "Ingresar"){
                            if (mapa.Get_slots()[0].Get_capacidad() >= 10){
                                cout<<"No se puede realizar la instruccion, se ignorara";
                            }
                            else{
                                mapa.Get_slots()[0].Set_capacidad(mapa.Get_slots()[0].Get_capacidad() + 1);
                                Robots[numero_robot].Agregar_instruccion(operacion,x,y,producto);
                            }

                        }
                        if (operacion == "Retirar"){
                            if (mapa.Get_slots()[0].Get_capacidad() <= 0){
                                cout<<"No se puede realizar la instruccion, se ignorara";
                            }
                            else{
                                mapa.Get_slots()[0].Set_capacidad(-1 + mapa.Get_slots()[0].Get_capacidad());
                                Robots[numero_robot].Agregar_instruccion(operacion,x,y,producto);
                            }
                        }
                    }

                }

                }
            else{
                cout << "La instruccion no es valida. Esta instruccion se omitira.";
            }
        }
    }
    for (int i = 0 ; i< mapa.Get_largo();i++) {
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

    return 0;
}