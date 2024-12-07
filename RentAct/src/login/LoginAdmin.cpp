#include "../../include/LoginAdmin.h"

// Creando el login para el admin
LoginAdmin::LoginAdmin(const string &user, const string &password)
    : adminUser(user), adminPassword(password){}

// Autenticacion del admin
bool LoginAdmin::authenticate(const string &inputUser, const string &inputPassword) const {
    return (inputUser == adminUser && inputPassword == adminPassword);
}
