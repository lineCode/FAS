#include "NetAddress.h"
#include <endian.h>
#include <typeinfo>
#include <iostream>

using namespace std;

NetAddress::NetAddress(unsigned short sa_family,
                       int sa_port,
                       const char *sa_ip) {
  addr.sin_family = sa_family;
  addr.sin_port = htobe16(sa_port);
  addr.sin_addr.s_addr = inet_addr(sa_ip);
}
NetAddress::NetAddress(unsigned short sa_family,
                       int sa_port,
                       unsigned int sa_ip) {
  addr.sin_family = sa_family;
  addr.sin_port = htobe16(sa_port);
  addr.sin_addr.s_addr = htobe32(sa_ip);
}

NetAddress::NetAddress(int sa_port,
                       const char *sa_ip):
    NetAddress(AF_INET, sa_port, sa_ip) {
}
NetAddress::NetAddress(int sa_port):
    NetAddress(AF_INET, sa_port, INADDR_ANY){
}
struct sockaddr_in& NetAddress::NetAddress_get_addr() {
  return addr;
}
socklen_t NetAddress::NetAddress_get_addr_len() {
  return sizeof(addr);
}
