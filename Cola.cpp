#include "Cola.h"

bool alumno::operator<(const alumno& otro) const
{
    return nombre < otro.nombre;
}

alumno::alumno() : nombre("juanito"), nombreCarrera("inco"), materiasAprobadas(0), promedioGeneral(0.0) {}
alumno::alumno(std::string n, std::string nC, int mA, float pG) : nombre(n), nombreCarrera(nC), materiasAprobadas(mA), promedioGeneral(pG) {}
alumno& alumno::operator=(const alumno& x)
{
    if (this != &x)
    {
        nombre = x.nombre;
        nombreCarrera = x.nombreCarrera;
        materiasAprobadas = x.materiasAprobadas;
        promedioGeneral = x.promedioGeneral;
    }
    return *this;
}


std::ostream& operator<<(std::ostream& o, alumno& p)
{
    o << "nombre: " << p.nombre << "\t nombre carrera: " << p.nombreCarrera << "\t materias aprobadas: " << p.materiasAprobadas << "\t promedio general: " << p.promedioGeneral << std::endl;
    return o;
}

std::istream& operator>>(std::istream& o, alumno& p)
{
    std::cout << "\ninserta nombre: ";
    o >> p.nombre;
    std::cout << "inserta nombre carrera: ";
    o >> p.nombreCarrera;
    std::cout << "inserta materias aprobadas: ";
    o >> p.materiasAprobadas;
    std::cin.ignore();
    std::cout << "inserta promedio general: ";
    o >> p.promedioGeneral;
    std::cin.ignore();
    return o;
}

bool Cola::vacia() const
{
    return ult == -1;
}

bool Cola::llena() const
{
    return ult == TAM - 1;
}

int Cola::ultimo() const
{
    return ult;
}

std::ostream& operator<<(std::ostream& o, Cola& L)
{
    int i = 0;
    std::cout << "\n";
    while (i <= L.ultimo())
    {
        o << L.datos[i];
        i++;
    }
    return o;
}

void Cola::enqueue(alumno& elem)
{
    if (llena())
    {
        std::cout << "La cola está llena. No se puede agregar la solicitud." << std::endl;
    }
    else
    {
        inserta(elem, ult + 1);
    }
}

alumno Cola::dequeue()
{
    if (vacia())
    {
        std::cout << "La cola está vacía. No se puede elaborar una constancia." << std::endl;
        return alumno();
    }
    else
    {
        alumno constancia = datos[0];

        for (int i = 0; i < ult; i++)
        {
            datos[i] = datos[i + 1];
        }
        ult--;

        return constancia;
    }
}

bool Cola::elimina(int pos)
{
    if (vacia() || pos < 0 || pos > ult)
    {
        std::cout << "Error de eliminación." << std::endl;
        return true;
    }

    int i = pos;
    while (i < ult)
    {
        datos[i] = datos[i + 1];
        i++;
    }
    ult--;
    return false;
}

int Cola::inserta(alumno& elem, int pos)
{
    if (llena() || pos < 0 || pos > ult + 1)
    {
        std::cout << "Error de inserción." << std::endl;
        return 0;
    }

    int i = ult + 1;
    while (i > pos)
    {
        datos[i] = datos[i - 1];
        i--;
    }
    datos[pos] = elem;
    ult++;
    return 1;
}

int Cola::busquedaLineal(alumno& elem)
{
    if (vacia())
    {
        return -1;
    }

    int constanciasAntes = 0;

    for (int i = 0; i <= ult; i++)
    {
        if (elem == datos[i])
        {
            return constanciasAntes;
        }

        constanciasAntes++;

    }

    return -1;
}

// ordenar la cola por el nombre de los alumnos
void Cola::ordenarPorNombre()
{
    if (vacia())
    {
        return; // No se puede ordenar una cola vacía
    }

    for (int i = 0; i <= ultimo(); i++)
    {
        int minIdx = i;
        for (int j = i + 1; j <= ultimo(); j++)
        {
            if (datos[j] < datos[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            // Intercambia los elementos
            alumno temp = datos[i];
            datos[i] = datos[minIdx];
            datos[minIdx] = temp;
        }
    }
}

int Cola::busquedaBinaria(alumno& elem)
{
    if (vacia())
    {
        return -1;
    }

    int inicio = 0;
    int fin = ultimo();

    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;
        if (elem < datos[medio])
        {
            fin = medio - 1;
        }
        else if (datos[medio] < elem)
        {
            inicio = medio + 1;
        }
        else
        {
            return medio;  // Elemento encontrado
        }
    }

    return -1; // No se encontró el elemento
}
