import cv2
import numpy as np

# Read the image
image = cv2.imread('C:/Users/ayush/OneDrive/Desktop/Class Work/python/09-04-2025/comp-vision/img.png')

gaussian_blur = cv2.GaussianBlur(image, (5, 5), 0)
median_blur = cv2.medianBlur(image, 5)

cv2.imshow('Normal Image', image)
cv2.imshow('Gaussian Blur', gaussian_blur)
cv2.imshow('Median Blur', median_blur)

cv2.waitKey(0)
cv2.destroyAllWindows()