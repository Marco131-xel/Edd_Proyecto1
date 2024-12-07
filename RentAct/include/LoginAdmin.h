#ifndef LOGINADMIN_H
#define LOGINADMIN_H
#include <iostream>

using namespace std;

class LoginAdmin {
    public:
        LoginAdmin(const string &user, const string &password);
        bool authenticate(const string& inputUser, const string& inputPassword) const;
    private:
        string adminUser;
        string adminPassword;
};
#endif //LOGINADMIN_H
