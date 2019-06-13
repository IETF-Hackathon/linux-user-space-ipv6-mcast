/*
* Copyright 2019, MNK Consulting
* http://mnkcg.com
*
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void main()
{
  int fd = socket(AF_INET6, SOCK_DGRAM, 0);

  // BIND
  struct sockaddr_in6 address = {AF_INET6, htons(4321)};
  bind(fd, (struct sockaddr*)&address, sizeof address);

  // JOIN MEMBERSHIP
  struct ipv6_mreq group;
  group.ipv6mr_interface = 0;
  inet_pton(AF_INET6, "FF02:0:0:0:0:0:1:8:1234", &group.ipv6mr_multiaddr);
  setsockopt(fd, IPPROTO_IPV6, IPV6_JOIN_GROUP, &group, sizeof group);

  // READ
  char buffer[128];
  read(fd, buffer, sizeof buffer);
  printf("%s\n", buffer);
}
