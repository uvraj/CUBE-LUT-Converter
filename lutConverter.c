#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 5){
        puts("Not enough arguments.\n")
        puts("USAGE: lutConverter.exe DIM_XYZ NUM_CHANNELS FILENAME FILENAME_OUT");
        exit(EXIT_FAILURE);
        return 0;
    }

    size_t lutDimensions = atoi(argv[1]) * 3;
    size_t lutChannels = atoi(argv[2]);
    size_t totalLutElem = lutDimensions * lutChannels;

    FILE *lut = fopen(argv[3], "r");
    float *lutValues = (float*) malloc(totalLutElem * sizeof(float));

    if(!lut) {
        puts("3D LUT Loading failed. Exiting.");
        exit(EXIT_FAILURE);
        return 1;
    }

    float num;
    size_t i = 0;
    while(fscanf(lut, "%f", &num) == 1) {
        lutValues[i] = num;
        // printf("%f\n", lutValues[i]);
        i++;
    }

    printf("Total Array Size: %d Bytes.\n", totalLutElem * sizeof(float));

    FILE *lutBinary = fopen(argv[4], "wb");
    size_t numDataWritten = 0;

    puts("Created file.");

    numDataWritten = fwrite(lutValues, sizeof(float), totalLutElem, lutBinary);
    printf("Number of values written to FILE: %d", numDataWritten);

    // puts("Debug Stuff:\n");
    // for(size_t i = 0; i < LUT_DIM * LUT_DIM * LUT_DIM * 3; i += 3) 
    //    printf("%f %f %f\n", lutValues[i], lutValues[i + 1], lutValues[i + 2]);

    free(lutValues);
    exit(EXIT_SUCCESS);
    return 0;
}