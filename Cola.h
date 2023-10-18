#ifndef COLA_H
#define COLA_H

#include <iostream>
const int TAM = 100;

// Declaración de la clase alumno
class alumno
{
private:
    std::string nombre;
    std::string nombreCarrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    alumno();
    alumno(std::string n, std::string nC, int mA, float pG);
    alumno& operator=(const alumno& x);

    bool operator<(const alumno& otro) const;
    friend std::ostream& operator<<(std::ostream&, alumno&);
    friend std::istream& operator>>(std::istream&, alumno&);
    bool operator==(const alumno& p) const
    {
        return p.nombre == nombre && p.nombreCarrera == nombreCarrera && p.materiasAprobadas == materiasAprobadas && p.promedioGeneral == promedioGeneral;
    }
};

// Declaración de la clase Cola
class Cola
{
private:
    alumno datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(alumno& elem, int pos);

public:
    Cola() : ult(-1) {}
    bool vacia() const;
    bool llena() const;
    int ultimo() const;
    friend std::ostream& operator<<(std::ostream& o, Cola& L);
    void enqueue(alumno& elem);
    alumno dequeue();
    int busquedaLineal(alumno& elem);
    void ordenarPorNombre();
    int busquedaBinaria(alumno& elem);
};

#endif // COLA_H
