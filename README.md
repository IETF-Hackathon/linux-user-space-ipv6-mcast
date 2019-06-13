This directory contains prototype C code to help a Linux host join a new IPv6 link-local multicast
address as required by https://datatracker.ietf.org/doc/draft-hsingh-ipv6-coin-ml/

The code uses IPV6_JOIN_GROUP from https://tools.ietf.org/html/rfc3493

# Use:

Just type "make" to build the code.  The server code app is "svr".  Client code app is "clnt"

Run the code using two terminals.  One terminal runs svr and another runs clnt.
Once the client runs, the server prints "hello multicast world".
