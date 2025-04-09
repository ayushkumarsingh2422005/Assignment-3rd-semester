import cv2

# Load the image
image = cv2.imread('C:/Users/ayush/OneDrive/Desktop/Class Work/python/09-04-2025/comp-vision/logo.jpg')

cv2.imshow('Image', image)

cv2.waitKey(0)
cv2.destroyAllWindows()
