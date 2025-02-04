#include "../../include/Login.h"
#include "../../include/LoginAdmin.h"
#include "../../include/MenuAdmin.h"
#include "../../include/MenuUser.h"
#include "../../include/Global.h"

// todos los menus
MenuUser menu_user;
MenuAdmin menu_admin;

// funcion para administrador
void Login::login_admin() {
    // Credenciales del administrador
    LoginAdmin login_admin("admin", "admin");

    // Ingresar los campos
    string inputUser;
    string inputPass;

    // Solicitar las credenciales
    cout << " :::: Login Administrador :::: " << endl;
    cout << "Usuario: ";
    cin >> inputUser;
    cout << "Contrasenia: ";
    cin >> inputPass;

    // Validar credenciales
    if (login_admin.authenticate(inputUser, inputPass)) {
        cout << "\t\n -- Inicio de Sesion Exitoso -- \n" << endl;
        menu_admin.display();
    } else {
        cout << "\n ** Usuario o contrasenia incorrectos ** \n" << endl;
    }
}

// funcion para usuario
void Login::login_user() {
    cout << " :::: Login Usuario :::: " << endl;
    cout << "Ingresar Usuario: ";
    cin >> nombre;
    cout << "Ingresar Contrasenia: ";
    cin >> password;

    if (matriz.buscarUsuario(nombre, password)) {
        cout << "\t\n -- Inicio de Sesion Exitoso -- \n" << endl;
        menu_user.display(matriz.usuarioActual);
    } else {
        cout << "\n ** Usuario o Contrasenia incorrectos ** \n" << endl;
    }
}
