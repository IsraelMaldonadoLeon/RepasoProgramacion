#include <iostream>
#include <stdlib.h>
#include <string>
#include<fstream>

using namespace std;

class Paquete{
    public:
    int id, peso;
    string origen, destino;
};


class Paqueteria {
private:
    struct Nodo {
    Paquete paquete;
    Nodo *siguiente;
    };
    Nodo *lista = nullptr;
public:
    void insertarLista(const Paquete &paquete) {
        Nodo *nuevo_nodo = new Nodo();
        nuevo_nodo->paquete = paquete;
        nuevo_nodo->siguiente = lista;
        lista = nuevo_nodo;
        system("cls");
    }

    void mostrarLista(){
        Nodo *temp = lista;
        while (temp){
            cout<<"id :"<<temp-> paquete.id<<endl;
            cout<<"Origen: "<<temp-> paquete.origen<<endl;
            cout<<"Destino: "<< temp -> paquete. destino<<endl;
            cout<<"Peso: "<<temp-> paquete.peso <<endl;
            temp=temp-> siguiente;
        }
    }

    void eliminarLista(){
        if(lista){
            Nodo *temp = lista;
            lista = lista->siguiente;
            delete temp;
        }
    }

    void guardarArchivo(){
        ofstream archivo("ArchivoPaquetes.txt");
        Nodo *temp = lista;
        while (temp){
            archivo << temp->paquete.id << "  " << temp->paquete.origen << "  " << temp->paquete.destino << "  " << temp->paquete.peso<< endl;
            temp=temp->siguiente;
        }
        archivo.close();
    }

    void recuperarArchivo(){
        ifstream archivo("ArchivoPaquetes.txt");
        if(archivo.is_open()){
            int id, peso;
            string origen, destino;
            while (archivo >> id >> origen >> destino >> peso){
                Paquete paquete;
                paquete.id = id;
                paquete.origen = origen;
                paquete.destino = destino;
                paquete.peso = peso;
                insertarLista(paquete);
            }
            archivo.close();
        }
    }
};

int main() {
    int op;

    Paqueteria paqueteria;

    do {
        cout << "\n\t\t ACTIVIDAD 1: REPASO DE PROGRAMACION \n\n";
        cout << " 1. AGREGAR PAQUETE " << endl;
        cout << " 2. ELIMINAR PAQUETE DEL INICIO" << endl;
        cout << " 3. MOSTRAR         " << endl;
        cout << " 4. GUARDAR         " << endl;
        cout << " 5. RECUPERAR       " << endl;
        cout << " 6. SALIR           " << endl;

        cout << "\n INGRESE OPCION: ";
        cin >> op;
        switch (op) {
            case 1:
                {
                Paquete nuevoPaquete;
                cout << "id: "; cin >> nuevoPaquete.id;
                cout << "peso: "; cin >> nuevoPaquete.peso;
                cout << "origen: "; cin >> nuevoPaquete.origen;
                cout << "destino: "; cin >> nuevoPaquete.destino;
                cout << "Elemento agregado correctamente" << endl;
                system("pause");
                paqueteria.insertarLista(nuevoPaquete);
                }
                break;

            case 2:
                paqueteria.eliminarLista();
                cout<<"El paquete ha sido eliminado"<<endl;
                system("pause");
                break;

            case 3:
                paqueteria.mostrarLista();
                system("pause");
                break;

            case 4:
                paqueteria.guardarArchivo();
                cout<<"Las paqueterias han sido guardadas en el archivo ArchivoPaquetes.txt"<<endl;
                system("pause");
                break;

            case 5:
                paqueteria.recuperarArchivo();
                cout << "Paquetes recuperados del archivo ArchivosPaquetes.txt"<<endl;
                system("pause");
                break;
            default:
                cout<<"Opcion no valida, intentelo de nuevo"<<endl;
                system("pause");
                system("cls");
        }
        cout << endl << endl;
        system("cls");
    } while (op != 6);
    system("pause");
    return 0;
}
