#include "../../include/Activo.h"

// Constructor vacio
Activo::Activo() {

}
Activo::Activo(int idR, string nombre, string descripcion, string idT)
    : idR(idR), nombre(nombre), descripcion(descripcion), idT(idT) {}
