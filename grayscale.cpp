// grayscale.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
// 원본인 24비트 이미지 파일을 8비트인 그레이(흑백)으로 변환해줍니다.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXBUFF 230400
#define GRAYBUFF 76800
#define width 320
#define height 240

int main(void) {
	int x, y, cnt, idx;
	unsigned char r, g, b;
	FILE *fp_source, *fp_target;
	unsigned char source_data[MAXBUFF];
	unsigned char target_data[GRAYBUFF];
	cnt = 0; idx = 0;
	if ((fp_source = fopen("cat2.dat", "rb")) == NULL) {
		printf("Open Error or File not exit. \n");
		exit(0);
	}
	fread(source_data, 1, MAXBUFF, fp_source);
	fclose(fp_source);

	for (y = 0; y < width; y++) {
		for (x = 0; x < width; x++) {
			if (idx < (MAXBUFF)) {
				r = source_data[idx++];
				g = source_data[idx++];
				b = source_data[idx++];
			}
			target_data[cnt++] = (r + g + b) / 3;
		}
	}

	idx = 0;
	cnt = 0;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			source_data[idx++] = target_data[cnt];
			source_data[idx++] = target_data[cnt];
			source_data[idx++] = target_data[cnt];
			cnt++;
		}
	}

	if ((fp_target = fopen("icat2.dat", "wb")) == NULL) {
		printf("New File create failure. \n");
		exit(0);
	}
	fwrite(source_data, 1, MAXBUFF, fp_target);
	fclose(fp_target);
	
	
	return 0;

}
