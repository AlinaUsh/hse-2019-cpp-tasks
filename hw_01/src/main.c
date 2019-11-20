#include "bmp.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

BMPImage image;
BMPImage crop_image;
BMPImage rotate_image;

int main(int argc, char *argv[]) {
    if (argc < 2) 
        return 0;
    load_bmp(argv[2], &image);
    if (strcmp("crop-rotate", argv[1]) == 0) {
        int correct = crop(&image, &crop_image, atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]));
	if (correct == 1) {
	        delete_image(&crop_image);
	        delete_image(&image);
		delete_image(&rotate_image);
		return 0;	
	}
	rotate(&crop_image, &rotate_image);
	save_bmp(argv[3], &rotate_image);	
        delete_image(&crop_image);
	delete_image(&rotate_image);
    }
    delete_image(&image);
    return 0;
}
