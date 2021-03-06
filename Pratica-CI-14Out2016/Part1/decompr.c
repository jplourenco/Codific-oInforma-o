#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port.h"
#include "compress.h" 

int main( int argc, char *argv[] ){

	int fr, fw, n;
        struct stat st;
	unsigned char *src, *dst;
	compress_identity *id;
	long len, out_len;
	unsigned char *warea;
	char message[128];

        if( argc != 3){
		sprintf(message,"%s file1 file2\n", argv[0]);
		perror(message);
		exit(1);
	}

	fr = open(argv[1], O_RDONLY);
	if( fr < 0 ) {
		sprintf(message, 
			"ficheiro %s nao pode ser aberto para leitura\n", 
                        argv[1]);
		 perror(message);
		exit(1);
	}

        if ( fstat( fr, &st) < 0) {
		sprintf(message, "stat sobre ficheiro %s falhou\n", argv[1]);
		perror(message);
		exit(1);
	}

        if ( (src = (unsigned char *)malloc( st.st_size ))  == NULL) {
		perror("falha no malloc\n");
		exit(1);
	}

        if ( read( fr, src, st.st_size ) != st.st_size) {
		perror("falha no read\n");
		exit(1);
	}
	close(fr);

			
        if ( (dst = (unsigned char *)malloc( 9 * st.st_size ))  == NULL) {
		perror("falha no malloc\n");
		exit(1);
	}
	compress( COMPRESS_ACTION_IDENTITY, 
			NULL, NULL, 0, NULL, (ULONG *)&id); 
        len = id->memory;

        if ( (warea = (unsigned char *)malloc( len ))  == NULL) {
		perror("falha no malloc\n");
		exit(1);
	}

	/* a completar */ 
	compress( COMPRESS_ACTION_DECOMPRESS,  warea, src, len, dst, &out_len);

	printf("length of decompressed file = %ld\n", out_len);

	fw = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC , 0660);
	if( fw < 0 ) {
		printf("ficheiro %s nao pode ser escrito\n", 
                       argv[2]);
		exit(1);
	}
			
        if ( (n = write( fw, dst, out_len ))  != out_len) {
		perror("falha no write\n");
		exit(1);
	}
	close(fr);

}

