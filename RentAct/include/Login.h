#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>

using namespace std;

class Login {
    public:
        string nombre;
        string password;
        void login_admin();
        void login_user();
};
#endif //LOGIN_H