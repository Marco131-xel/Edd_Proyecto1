cmake_minimum_required(VERSION 3.30)
project(RentAct)

set(CMAKE_CXX_STANDARD 20)

add_executable(RentAct main.cpp
        include/MenuUser.h
        src/menu/MenuUser.cpp
        "src/login/Login.cpp"
        include/Login.h
        src/menu/MenuAdmin.cpp
        include/MenuAdmin.h
        "src/login/LoginAdmin.cpp"
        include/LoginAdmin.h
        "src/login/Inicio.cpp"
        include/Inicio.h
        src/matriz/MatrizDispersa.cpp
        include/MatrizDispersa.h
        src/funciones_admin/Registrar_Usuario.cpp
        include/Registrar_Usuario.h
        src/matriz/Global.cpp
        include/Global.h
        src/arbol/Arbol.cpp
        include/Arbol.h
        src/funciones_user/Agregar_Activo.cpp
        include/Agregar_Activo.h
        src/nodos/NodoM.cpp
        src/nodos/NodoA.cpp
        include/NodoA.h
        include/NodoM.h
        src/funciones_user/Activo.cpp
        include/Activo.h)
