#ifndef _NWC_TCP_HANDLER_H_
#define _NWC_TCP_HANDLER_H_

#include "nwc_io_handler.h"

enum NWC_TCP_STATE
{
    NTS_CLOSED = 1,
    NTS_LISTEN,
    NTS_CONNECTING,
    NTS_ESTABLISHED
};

struct nwc_tcp_handler
{
    struct nwc_io_handler parent;
    int state;
};

int nwc_tcp_handler_init(struct nwc_tcp_handler *handler);
int nwc_tcp_handler_accept(struct nwc_tcp_handler *handler, int fd);

int nwc_tcp_handler_listen(struct nwc_io_handler *handler, const char *ip, uint16_t port);
int nwc_tcp_handler_connect(struct nwc_io_handler *handler, const char *hostname, uint16_t port);
int nwc_tcp_handler_send(struct nwc_io_handler *handler, const uint8_t buffer[], uint32_t buflen);
int nwc_tcp_handler_recv(struct nwc_io_handler *handler, uint8_t buffer[], uint32_t buflen);
int nwc_tcp_handler_close(struct nwc_io_handler *handler);
void nwc_tcp_handle_input(struct nwc_io_handler *handler);
void nwc_tcp_handle_output(struct nwc_io_handler *handler);

#define tcp_handler(io_handler) \
    (struct nwc_tcp_handler*)(io_handler)

#endif//_NWC_TCP_HANDLER_H_

