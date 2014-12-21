import numpy as np
import argparse
import cv2

# construct parse argument and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-i","--image", required = True, help = "path to the img file")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

gradX = cv2.Sobel(gray, ddepth = cv2.cv.CV_32F, dx = 1, dy = 0, ksize = -1)
gradY = cv2.Sobel(gray, ddepth = cv2.cv.CV_32F, dx = 0, dy = 1, ksize = -1)

gradient = cv2.subtract(gradX ,gradY)
gradient = cv2.convertScaleAbs(gradient)

#blur the image image
blurred = cv2.blur(gradient, (9,9))
(_, thresh) = cv2.threshold(blurred, 255, 255, cv2.THRESH_BINARY)


# construct a closing kernel and apply it to the thresholded image
kernel = cv2.getStructuringElement(cv2.MORPH_RECT,(21,7))
closed = cv2.morphologyEx(thresh, cv2.MORPH_CLOSE, kernel)


closed = cv2.erode(closed,None, iterations = 4)
closed = cv2.dilate(closed, None, iterations = 4)

(cnts , _) = cv2.findContours(closed.copy(), cv2.RETR_EXTERNAL,
        cv2.CHAIN_APPROX_SIMPLE)
c = sorted(cnts, key = cv2.contourArea, reverse = True)[0]

# compute the rotated bounding box of the largest contour
rect = cv2.minAreaRect(c)
box = np.int0(cv2.cv.BoxPoints(rect))

# draw a bounding box
cv2.drawContours(image, [box], -1, (0,255,0), 3)
cv2.imshow("Image", image)
cv2.waitkey(0)


