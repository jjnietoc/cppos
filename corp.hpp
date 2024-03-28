// corp.hpp -- manage organzation, users, passwords, privileges, etc.

#include <cstdint>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

#ifndef CORP_HPP
#define CORP_HPP

class User 
{
  private: 
    std::string ID;
    std::string username;
    bool isAdmin;

  public:
    User() { }
    User(const std::string & un = "Null",
         bool ad = false);
    ~User();
    
    void setID();
    void setName(const std::string & un);
    void setAdmin(bool ad);

    const std::string & getID() const { return ID; };
    const std::string & getName() const { return username; };
    const bool & getAdmin() const { return isAdmin; };
    
    void modifyUser(const std::string & n_user, 
                    bool n_ad);

    friend std::ostream& operator<<(std::ostream& out, const std::vector<User>& v);
  };


#endif
