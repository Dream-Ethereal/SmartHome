#include "server.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static int ssocket;

static int sockets[1024];
static int count = 0;


static int lamp_status = 0;
static int door_status = 0;
static int curtain_status = 0;
static int airc_status = 0;
static int threhold_value[10] = {0};
static char value[16] = {0};
static int mode = 0;

// struct sockaddr_in {
//    sa_family_t    sin_family; /* address family: AF_INET */
//    in_port_t      sin_port;   /* port in network byte order */
//    struct in_addr sin_addr;   /* internet address */
// };

// /* Internet address. */
// struct in_addr {
//    uint32_t       s_addr;     /* address in network byte order */
// };

static void error_handle(const char* errmsg)
{
	perror(errmsg);
	exit(1);
}

void server_init(const char* port)
{
	ssocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ssocket == -1)
		error_handle("socket error");

	int opt = 1;
	setsockopt(ssocket, SOL_SOCKET, SO_REUSEADDR, (void*)&opt, sizeof(opt));

	struct sockaddr_in address;
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_port = htons(atoi(port));
	address.sin_addr.s_addr = INADDR_ANY;

	if (bind(ssocket, (struct sockaddr*)&address, sizeof(address)) == -1)
		error_handle("bind error");

	if (listen(ssocket, 10) == -1)
		error_handle("listen error");

	puts("server init success!! ");
}


void server_run()
{
	while (1)
	{
		// 阻塞等待连接
		int client = accept(ssocket, NULL, NULL);
		// 接到连接后，创建一个新线程处理连接
		pthread_t tid;
		pthread_create(&tid, NULL, client_handle, (void*)&client);
	}
}


void* client_handle(void* arg)
{
	// 接受传递过来的客户套接字
	int client = *(int*)arg;
	// 保存客户套接字
	save_client(client);
	
	// 客户上线时，发送最新的控制器状态
	send_controller_status(client);

	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	getpeername(client, (struct sockaddr*)&addr, &len); // 根据套接字描述符 获取对端的地址信息
	printf("[%s]  online...\n", inet_ntoa(addr.sin_addr));
	while (1)
	{
		// 读数据
		char buf[17] = {0};
		int ret = read(client, buf, sizeof(buf));
		if (ret == 0)
		{
			// 客户下线，删除该套接字
			printf("[%s]  offline...\n", inet_ntoa(addr.sin_addr));
			remove_clinet(client); 	// 移除
			close(client);			// 关闭
			pthread_exit(NULL);
		}
		// 记录控制器的状态 
		save_controller_status(buf);
		// 转发给所有在线客户端
		send_all(buf, ret);
	}
}

void save_controller_status(const char* buf)
{
	// 上锁
	if (buf[0] == 0x01)
		door_status = buf[1];
	else if (buf[0] == 0x02)
		lamp_status = buf[1];
	else if (buf[0] == 0x03)
		curtain_status = buf[1];
	else if (buf[0] == 0x04)
		airc_status = buf[1];
	else if (buf[0] == 0x05)	//阈值： 0X 05 00 14 7F 00 14 7F 00 14 7F 7F
	{
		for (int i = 1; i < 11; i++)
		{
			threhold_value[i - 1] = buf[i];
		}
		
	}
    else if (buf[0] == 0X06)    //模式
        mode = buf[1];
	else if (buf[0] == 0x00)	//传感器数据：0X 00 00 14 7F 00 14 7F 00 14 7F 00 14 7F 00 14 7F 7F
	{
		for(int i = 1; i < 17; i++)
		{
			value[i - 1] = buf[i];
		}
	}
	// 解锁
}

void send_controller_status(int client)
{
	// 上锁
	char buf1[2] = {1, door_status};
	write(client, buf1, sizeof(buf1));
	
	char buf2[2] = {2, lamp_status};
	write(client, buf2, sizeof(buf2));

	char buf3[2] = {3, curtain_status};
	write(client, buf3, sizeof(buf3));

	char buf4[2] = {4, airc_status};
	write(client, buf4, sizeof(buf4));

	char buf5[17];
	buf5[0] = 0x00;
	for (int i = 1; i < 17; i++)
	{
		buf5[i] = value[i - 1];
	}
	write(client, buf5, sizeof(buf5));

	char buf6[11];
	buf5[0] = 0x05;
	for (int i = 1; i < 11; i++)
	{
		buf6[i] = threhold_value[i - 1];
	}
	write(client, buf6, sizeof(buf6));

    char buf7[2] = {6, mode};
    write(client, buf7, sizeof(buf7));
	// 解锁
}


void save_client(int client)
{
	// 上锁
	sockets[count++] = client;
	// 解锁
}

void remove_clinet(int client)
{
	// 上锁
	for (int i = 0; i < count; ++i)
	{
		if (sockets[i] == client)
		{
			// 后面所有的元素往前移一格，覆盖原有值
			for (int j = i; j < count-1; ++j)
			{
				sockets[j] = sockets[j+1];
			}
			break;
		}
	}
	--count;
	// 解锁
}

void send_all(const char* buf, int size)
{
	printf("recv buf: [%d, %d]\n", buf[0], buf[1]);
	// 上锁
	for (int i = 0; i < count; ++i)
	{
		write(sockets[i], buf, size);
	}
	// 解锁
}
