#include <iostream>
#include <list>

using namespace std;

class Neurona {
private:
    int id;
    float voltaje;
    int posicion_x;
    int posicion_y;
    int red;
    int green;
    int blue;

public:
    Neurona(int _id, float _voltaje, int _pos_x, int _pos_y, int _red, int _green, int _blue)
    : id(_id), voltaje(_voltaje), posicion_x(_pos_x), posicion_y(_pos_y), red(_red), green(_green), blue(_blue) {}

    void print() const {
        cout << "ID: " << id <<endl;
        cout << "Voltaje: " << voltaje <<endl;
        cout << "Posicion X: " << posicion_x <<endl;
        cout << "Posicion Y: " << posicion_y <<endl;
        cout << "Color (R,G,B): (" << red << "," << green << "," << blue << ")"<<endl;
    }
};

class AdminNeuronas {
private:
    list<Neurona> neuronas;

public:
    void agregar_inicio(const Neurona& neurona) {
        neuronas.insert(neuronas.begin(), neurona);
    }

    void agregar_final(const Neurona& neurona) {
        neuronas.push_back(neurona);
    }

    void mostrar() const {
        for (const Neurona& neurona : neuronas) {
            neurona.print();
            cout << "\n";
        }
    }
};

int main() {
    AdminNeuronas a_n;

    Neurona neurona1(7, 12.2, 42, 12, 470, 5, 0);
    Neurona neurona2(76, 6.54, 8, 22, 47, 78, 2);

    a_n.agregar_inicio(neurona1);
    a_n.agregar_final(neurona2);
    a_n.agregar_inicio(neurona2);

    cout << "Neuronas almacenadas:\n";
    a_n.mostrar();

    return 0;
}
