#include "socket.h"

TcpSocket::TcpSocket(int sockfd) : sockfd_(sockfd) {}

TcpSocket::~TcpSocket() {
  close(sockfd_);
}


int TcpSocket::sendMsg(std::string msg) {
  bag sbag;
  sbag.len = htonl(msg.size());
  sbag.str = msg;
  int ret = send(sockfd_,&sbag,sizeof sbag,0);
  if(ret != sizeof(sbag)) return -1;
  return 0;
}


int TcpSocket::recvMsg(std::string& msg) {
  int ret = recv(sockfd_,&msg,msg.size(),0);
  if(ret != msg.size()) return -1;
  return 0;
}
