/*
  RAII is often used to connect and then automatically
  disconnect from a remote resource.

  In this example, there are two functions to connect and
  disconnect from a network resource. These could be,
  for example, functions defined in a C library or as
  an interface in the operating system.

  These should be wrapped into a class so that any
  open connection is automatically disconnected.

  Fill out the Connection class so that this is handled
  in the constructor and destructor. The constructor should
  take (and store) the ip address (as a std::string).
*/

#include <iostream>
#include <string>

void connect(std::string ip_address)
{
  std::cout << "Connecting to ip address: "
            << ip_address << std::endl;
}

void disconnect(std::string ip_address)
{
  std::cout << "Disconnecting from ip address " 
            << ip_address << std::endl;
}

class Connection
{
};


int main() {

  std::string ip_address = "12.34.56.78";
  Connection conn(ip_address);
  return 0;
}
