#ifndef __ADMINUSER_HPP__
#define __ADMINUSER_HPP__

#include "User.hpp"

class AdminUser : public User
{
public:
  AdminUser(const string &username, const string &password);
  bool isAdmin() const override; // Override, mengembalikan true untuk admin
};

#endif