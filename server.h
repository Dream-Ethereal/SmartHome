#ifndef SERVER_H
#define SERVER_H

void server_init(const char* port);

void server_run();

void* client_handle(void* arg);

void save_client(int client);

void remove_clinet(int client);

void send_all(const char* buf, int size);


void save_controller_status(const char* buf);

void send_controller_status(int client);


#endif
