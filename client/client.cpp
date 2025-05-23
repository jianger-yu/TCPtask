#include "client.h"

TcpClient::TcpClient()
    : fd_(socket(AF_INET, SOCK_STREAM, 0)),
      socket_(std::make_unique<TcpSocket>(fd_)) {}

TcpClient::~TcpClient() {
  close(fd_);
}


bool TcpClient::connectToHost(const char* ip, unsigned short port) {
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  int ret = inet_pton(AF_INET,ip,&addr.sin_addr.s_addr);
  if(ret <= 0) return false;
  
  ret = connect(fd_,(struct sockaddr *)&addr,sizeof addr);
  if(ret == -1) return false;
  return true;
}
