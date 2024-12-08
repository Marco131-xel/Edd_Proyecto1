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
        "src/login/LoginUser.cpp"
        include/LoginAdmin.h
        include/LoginUser.h
        "src/login/Inicio.cpp"
        include/Inicio.h
        src/nodos/Nodo.cpp
        include/Nodo.h
        src/matriz/MatrizDispersa.cpp
        include/MatrizDispersa.h
        src/funciones_admin/Registrar_Usuario.cpp
        include/Registrar_Usuario.h)
