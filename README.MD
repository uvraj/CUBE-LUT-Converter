# CUBE-LUT-Converter
This utility convers an Adobe CUBE color grading lookup table into a binary 3d texture, for
use with OptiFine in Minecraft or other OpenGL applications where binary dumps of 3d textures are pratical.


NOTE: The header of the .CUBE file has to be cleared! It should be a plaintext file consisting of a series of floats.

USAGE: lutConverter.exe DIM_XYZ NUM_CHANNELS FILENAME FILENAME_OUT
