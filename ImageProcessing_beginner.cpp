// ImageProcessing_beginner.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXBUFF 230400
#define width 320
#define height 240

int main(void)
{
	int x, y, max, idx = 0;
	unsigned char r, g, b;

	FILE *fp_source, *fp_target;
	unsigned char source_data[MAXBUFF];
	unsigned char target_data[MAXBUFF];
	max = MAXBUFF - 1;

	if ((fp_source = fopen("cat.png", "rb")) == NULL) {
		printf("Open Error or Fine not exist! \n");
		exit(0);
	}
	fread(source_data, 1, MAXBUFF, fp_source);
	fclose(fp_source);

	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			if (idx < (MAXBUFF)) {
				r = source_data[idx++];
				g = source_data[idx++];
				b = source_data[idx++];

				target_data[max--] = b;
				target_data[max--] = g;
				target_data[max--] = r;
			}
		}
	}

	if ((fp_target = fopen("icat.dat", "wb")) == NULL) {
		printf("New file create failure!! \n");
		exit(0);
	}

	fwrite(target_data, 1, MAXBUFF, fp_target);
	fclose(fp_target);

    return 0;
}
