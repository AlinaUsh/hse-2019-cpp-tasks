#include "bmp.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

void load_bmp(const char *filename, BMPImage *image) {
    FILE *input = fopen(filename, "rb");
    if (input == NULL) {
        printf("Could not open file %s", filename);
        fclose(input);
        return;
    }
    unsigned int correct = fread(&image->header, 54, 1, input);
    if (correct != 1) {
        fclose(input);
        return;
    }
    image->data = malloc(image->header.image_size_bytes);
    if (image->data == NULL) {
        fclose(input);
        return;
    }
    correct = fread(image->data, 1, image->header.image_size_bytes, input);
    if (correct != image->header.image_size_bytes) {
        fclose(input);
        return;
    }
    fclose(input);
}

void save_bmp(const char *filename, BMPImage *image) {
    FILE *output = fopen(filename, "wb");
    if (output == NULL) {
        printf("Could not open file %s", filename);
        fclose(output);
        return;
    }
    unsigned int correct = fwrite(&image->header, sizeof(image->header), 1, output);
    if (correct != 1) {
        fclose(output);
        return;
    }
    correct = 0;
    correct = fwrite(image->data, image->header.image_size_bytes, 1, output);
    if (correct != 1) {
        fclose(output);
        return;
    }
    fclose(output);
}

void delete_image(BMPImage *image) {
    free(image->data);
}

int ciel(int x) {
    return 3 * x + (4 - (3 * x % 4)) % 4;
}

uint32_t position_y(int y, int x) {
    return y * (3 * x + (4 - (3 * x) % 4) % 4);
}

uint32_t position_x(int x) {
    return x * 3;
}

int crop(BMPImage *image, BMPImage *new_image, int x, int y, int w, int h) {
    y = image->header.height_px - (y + h);
    if (x + w > image->header.width_px || y + h > image->header.height_px ||
        x < 0 || y < 0) {
        printf("This area can not be croped");
        return 1;
    }
    new_image->header = image->header;
    new_image->header.width_px = w;
    new_image->header.height_px = h;
    new_image->header.image_size_bytes = h * ciel(w);
    new_image->header.size = sizeof(new_image->header) + new_image->header.image_size_bytes;
    new_image->data = malloc(new_image->header.image_size_bytes);
    if (new_image->data == NULL) {
        printf("Not enough memory");
        return 1;
    }
    int new_index = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < 3; k++) {
                new_image->data[new_index] = image->data[position_y(i + y, image->header.width_px) + position_x(x + j) + k];
                new_index++;
            }
        }
        int padding = (4 - (3 * w) % 4) % 4;
        for (int j = 0; j < padding; j++) {
            new_image->data[new_index] = 0x00;
            new_index++;
        }
    }
    return 0;
}

void rotate(BMPImage *image, BMPImage *new_image) {
    int32_t w = image->header.width_px;
    int32_t h = image->header.height_px;
    new_image->header = image->header;
    new_image->header.width_px = h;
    new_image->header.height_px = w;
    new_image->header.image_size_bytes = w * ciel(h);
    new_image->header.size = sizeof(new_image->header) + new_image->header.image_size_bytes;
    new_image->data = malloc(new_image->header.image_size_bytes);
    if (new_image->data == NULL) {
        printf("Not enough memory");
        return;
    }
    int new_index = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < 3; k++) {
                new_image->data[position_y(w - j - 1, image->header.height_px) + position_x(i) + k] = image->data[new_index];
                new_index++;
            }
        }
        int padding = (4 - (3 * h) % 4) % 4;
        for (int j = 0; j < padding; j++) {
            new_image->data[new_index] = 0x00;
            new_index++;
        }
    }
}
