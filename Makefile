CC      = gcc
CFLAGS  = 
RM      = rm -f

default: all

all: svr clnt

svr: ipv6_mcast_svr.c
	$(CC) $(CFLAGS) -o svr ipv6_mcast_svr.c

clnt: ipv6_mcast_clnt.c
	$(CC) $(CFLAGS) -o clnt ipv6_mcast_clnt.c

clean:
	$(RM) svr clnt
