#include <stddef.h> //for size_t
#include <stdint.h> //for uint8_t
#include <stdio.h> //for printf

uint32_t my_ntohl(uint32_t n){
	uint32_t n1 = (n & 0xFF000000) >> 24;
	uint32_t n2 = (n & 0x00FF0000) >> 8;
	uint32_t n3 = (n & 0x0000FF00) << 8;
	uint32_t n4 = (n & 0x000000FF) << 24;
	return n1 | n2 | n3 | n4;
}

int main(int argc, char*argv[]) {
	
	FILE *fd1, *fd2;
	uint32_t network_buf1[255];
	uint32_t network_buf2[255];

	fd1 = fopen(argv[1], "r");
	fd2 = fopen(argv[2], "r");

	while(fread(network_buf1, 1, 255, fd1)) {}
	while(fread(network_buf2, 1, 255, fd2)) {}

	uint32_t* p =reinterpret_cast<uint32_t*>(network_buf1);
	uint32_t* p2 = reinterpret_cast<uint32_t*>(network_buf2);

	uint32_t n = my_ntohl(*p) + my_ntohl(*p2);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", my_ntohl(*p), my_ntohl(*p), my_ntohl(*p2), my_ntohl(*p2),n,  n);
}
