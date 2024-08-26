#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <dlfcn.h>

#define PROXY "127.0.0.1"
#define PROXYPORT 9050
#define USERNAME "toraliz"
#define reqsize sizeof(struct proxy_request);
#define ressize size(struct proxy_response);

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

/*

VN | CD | DSTPORT | DSTIP | USERID | NULL
1    1    2         4      variable  1

*/
struct proxy_request{
    int8 vn;
    int8 cd;
    int16 dstport;
    int32 dstip;
    unsigned char userid[8];
};
typedef struct proxy_request req;



/*

VN | CD | DSTPORT | DSTIP   
1    1    2         4

*/

struct proxy_response{
    int8 vn;
    int8 cd;
    int16 _;
    int32 __;

};
typedef struct proxy_response res;

req *request(struct sockaddr_in*);

int connect(int,const struct sockaddr*, socklen_t);
