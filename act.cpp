#include <iostream>

using namespace std;

const int TAM = 3;

enum
{
    PUSH = 1,
    POP,
    TOP,
    SALIR
};

class Empleado
{
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReporteA;

public:
    Empleado() : ClaveEmpleado(0), Nombre(""), Domicilio(""), Sueldo(0), ReporteA("") {}
    Empleado(int clave, string nom, string dom, float sal, string repA) : ClaveEmpleado(clave), Nombre(nom), Domicilio(dom), Sueldo(sal), ReporteA(repA) {}

    friend istream& operator >> (istream& in, Empleado& emp)
    {
        cout << endl << "Ingrese la Clave del Empleado: ";
        in >> emp.ClaveEmpleado;

        cout << "Ingrese el Nombre: ";
        in.ignore();
        getline(in, emp.Nombre);

        cout << "Ingrese el Domicilio: ";
        getline(in, emp.Domicilio);

        cout << "Ingrese el Sueldo: ";
        in >> emp.Sueldo;

        cout << "Ingrese el ReporteA: ";
        in.ignore();
        getline(in, emp.ReporteA);

        return in;
    }

    friend ostream& operator << (ostream& out, const Empleado& emp)
    {
        out << endl << "Clave del Empleado: " << emp.ClaveEmpleado << endl << "Nombre: " << emp.Nombre << endl << "Domicilio: " << emp. Domicilio << endl << "Sueldo: " << emp.Sueldo << endl << "ReporteA: " << emp.ReporteA << endl;

        return out;
    }

    int getClave() const
    {
        return ClaveEmpleado;
    }

    void muestra() const
    {
        cout << endl << "Clave: " << ClaveEmpleado << ", Nombre: " << Nombre << ", Domicilio: " << Domicilio << ", Sueldo: " << Sueldo  << ", Reporte: " << ReporteA << endl;
    }
};

class PilaEmpleados
{
private:
    Empleado empleados[TAM];
    int ult;

public:
    PilaEmpleados() : ult(-1), empleados{} {}

    bool vacia() const
    {
        return ult == -1;
    }

    bool llena() const
    {
        return ult == TAM - 1;
    }

    void push(const Empleado& empleado)
    {
        if (llena())
        {
            cout << endl << "La pila esta llena, no se puede agregar el empleado." << endl;
            return;
        }

        empleados[++ult] = empleado;
        cout << endl << "Empleado agregado exitosamente." << endl;
    }

    void pop(Empleado& empleado)
    {
        if (vacia())
        {
            cout << endl << "La pila esta vacia, no se puede eliminar un empleado." << endl;
            return;
        }

        empleado = empleados[ult--];
        cout << endl << "Empleado eliminado exitosamente." << endl;
    }

    void top() const
    {
        if (vacia())
        {
            cout << endl << "La pila esta vacia, no hay un empleado en la cima." << endl;
            return;
        }

        Empleado aux = empleados[ult];
        cout << endl << "El empleado en la cima de la pila es: " << endl;
        aux.muestra();
    }
};

void menu()
{
    cout << endl << "Menu:" << endl << " " << PUSH << ") Push Empleado" << endl << " " << POP << ") Pop Empleado" << endl << " " << TOP << ") Top Empleado" << endl << " " << SALIR << ") Salir" << endl << "Ingresa una opción: ";
}

int main()
{
    PilaEmpleados pilaEmpleados;
    int op;
    
    do
    {
        menu();
        cin >> op;

        switch (op)
        {
            case PUSH:
            {
                Empleado empleado;
                cin >> empleado;
                pilaEmpleados.push(empleado);
                break;
            }

            case POP:
            {
                Empleado empleado;
                pilaEmpleados.pop(empleado);
                break;
            }

            case TOP:
            {
                pilaEmpleados.top();
                break;
            }

            case SALIR:
            {
                cout << endl << "Saliendo del Programa" << endl;
                return 0;
            }

            default:
            {
                cout << endl << "Opción no válida" << endl;
            }
        }
    } while (1);

    return 0;
}