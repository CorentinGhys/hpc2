#!/usr/bin/env python3

import cv2 as cv
import sys

if __name__ == '__main__':

    # arguments
    if len(sys.argv) != 4:
        print("usage:", sys.argv[0], "<filename> <coef> <outfile>")
        sys.exit(-1)
    FILENAME = sys.argv[1]
    COEF = float(sys.argv[2])
    OUTFILE = sys.argv[3]

    # load input image
    imgIn = cv.imread(FILENAME)
    if imgIn.size == 0:
        print("failed to load", FILENAME)
        sys.exit(-1)

    # compute output image


    imgMult = imgIn * COEF / 255.0
    
    cv.imwrite(OUTFILE, imgMult)
    cv.imshow("image", imgMult)
    
    while True:
        k = cv.waitKey() & 0xFF
        if (k == 27):
            break



