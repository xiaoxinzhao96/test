#include <stdio.h>

#define Y_OFFSET 1000
#define U_OFFSET 250

int main(int argc, char *argv[])
{
	int ret, i;
	FILE *fp_in, *fp_out;
	char buf[Y_OFFSET] = {};
	
	if (argc != 3) {
		printf("Usage : %s infilename outfilename\n", argv[0]);
		return -1;
	}
	
	fp_in = fopen(argv[1], r);
	if (fp_in == NULL) {
		printf("fopen error \n");
		return -1;
	}
	fp_out = fopen(argv[2], w);
	if (fp_out == NULL) {
		printf("fopen error \n");
		return -1;
	}
	ret = fread(buf, sizeof(char), Y_OFFSET, fp_in);
	if (ret != Y_OFFSET) {
		printf("fread error\n");
		return -1;
	}
	fwrite(buf, sizeof(char), Y_OFFSET, fp_out);
	if (ret != Y_OFFSET) {
		printf("fwrite error\n");
		return -1;
	}
	for (i = 1; i <= U_OFFSET; i++) {
		if (i % 2 != 0) {
			fseek(fd_in, Y_OFFSET + i, SEEK_SET);
			fread(buf, sizeof(char), 1, fp_in);
			fwrite(buf, sizeof(char), 1, fp_out);
		} else {
			fseek(fd_in, Y_OFFSET + U_OFFSET + i, SEEK_SET);
			fread(buf, sizeof(char), 1, fp_in);
			fwrite(buf, sizeof(char), 1, fp_out);
		}
		
	
}
