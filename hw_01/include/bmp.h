#pragma once
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <stdint.h>

#pragma pack(push, 1)

typedef struct {
    uint16_t type;              // Type
    uint32_t size;              // File size in bytes
    uint16_t reserved1;         // Not used
    uint16_t reserved2;         // Not used
    uint32_t offset;            // Offset to image data in bytes from beginning of file
    uint32_t dib_header_size;   // DIB Header size in bytes
    int32_t width_px;          // Width of the image
    int32_t height_px;         // Height of image
    uint16_t num_planes;        // Number of color planes
    uint16_t bits_per_pixel;    // Bits per pixel
    uint32_t compression;       // Compression type
    uint32_t image_size_bytes;  // Image size in bytes
    int32_t x_resolution_ppm;  // Pixels per meter
    int32_t y_resolution_ppm;  // Pixels per meter
    uint32_t num_colors;        // Number of colors
    uint32_t important_colors;  // Important colors
}BMPHeader;

#pragma pack(1)
#pragma pack(pop)

typedef struct{
    BMPHeader header;
    unsigned char *data;
}BMPImage;

void load_bmp(const char *filename, BMPImage *image);

FILE *open_file(const char *filename, const char *mode);

void save_bmp(const char *filename, BMPImage *image);

int init_image(BMPImage *image, BMPImage *new_image, int w, int h);

int crop(BMPImage *image, BMPImage *new_image, int x, int y, int w, int h);

void rotate(BMPImage *image, BMPImage *new_image);

void delete_image(BMPImage *image);
