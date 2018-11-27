#!/usr/bin/env python3

import cv2 as cv
import sys

if __name__ == '__main__':

    # arguments
    if len(sys.argv) != 2:
        print("usage:", sys.argv[0], "<filename>")
        sys.exit(-1)
    FILENAME = sys.argv[1]

    # load input image

    cap = cv.VideoCapture("bmx.mkv")


    while(cap.isOpened()):
        ret, frame = cap.read()
        if not ret:
            break
        cv.imshow('bmx', frame)
        if cv.waitKey(30) == 27:
            break


