#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>

#define BLOCK_WIDTH  3 // Change this if you want a different block size
#define BLOCK_HEIGHT 2 // Change this if you want a different block size

void write_subimage(unsigned char *image, int width, int height, const char *prefix) {
    int sub_width  = width  / BLOCK_WIDTH;
    int sub_height = height / BLOCK_HEIGHT;
    int x, y;

    for (int i = 0; i < BLOCK_WIDTH * BLOCK_HEIGHT; ++i) {
        char filename[100];
        sprintf(filename, "%s_%d.jpg", prefix, i);
        FILE *outfile = fopen(filename, "wb");
        if (!outfile) {
            fprintf(stderr, "Error opening output file %s\n", filename);
            exit(1);
        }

        struct jpeg_compress_struct cinfo;
        struct jpeg_error_mgr jerr;
        cinfo.err = jpeg_std_error(&jerr);
        jpeg_create_compress(&cinfo);
        jpeg_stdio_dest(&cinfo, outfile);

        cinfo.image_width = sub_width;
        cinfo.image_height = sub_height;
        cinfo.input_components = 3;
        cinfo.in_color_space = JCS_RGB;
        jpeg_set_defaults(&cinfo);
        jpeg_start_compress(&cinfo, TRUE);

        JSAMPROW row_pointer[1];
        row_pointer[0] = (JSAMPROW)malloc(3 * sub_width * sizeof(JSAMPLE));

        int row_offset = (i / BLOCK_WIDTH) * sub_height;
        int col_offset = (i % BLOCK_WIDTH) * sub_width;

        for (y = 0; y < sub_height; ++y) {
            for (x = 0; x < sub_width; ++x) {
                int image_x = col_offset + x;
                int image_y = row_offset + y;
                row_pointer[0][x * 3] = image[(image_y * width + image_x) * 3];
                row_pointer[0][x * 3 + 1] = image[(image_y * width + image_x) * 3 + 1];
                row_pointer[0][x * 3 + 2] = image[(image_y * width + image_x) * 3 + 2];
            }
            jpeg_write_scanlines(&cinfo, row_pointer, 1);
        }

        jpeg_finish_compress(&cinfo);
        jpeg_destroy_compress(&cinfo);
        fclose(outfile);
        free(row_pointer[0]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_image.jpg>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    FILE *infile = fopen(input_filename, "rb");
    if (!infile) {
        fprintf(stderr, "Error opening input file %s\n", input_filename);
        return 1;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int width = cinfo.output_width;
    int height = cinfo.output_height;
    int channels = cinfo.output_components;
    unsigned char *image = (unsigned char *)malloc(width * height * channels);

    JSAMPROW row_pointer[1];
    row_pointer[0] = (JSAMPROW)malloc(width * channels * sizeof(JSAMPLE));

    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
        for (int x = 0; x < width * channels; ++x) {
            image[(cinfo.output_scanline - 1) * width * channels + x] = row_pointer[0][x];
        }
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
    free(row_pointer[0]);

    write_subimage(image, width, height, "output");

    free(image);

    return 0;
}
