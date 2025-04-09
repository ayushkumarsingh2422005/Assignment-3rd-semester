import cv2

# Read the image
image = cv2.imread('C:/Users/ayush/OneDrive/Desktop/Class Work/python/09-04-2025/comp-vision/logo.jpg')

# Convert to Grayscale
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Convert to HSV
hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# Display the images
cv2.imshow('Original Image', image)
cv2.imshow('Grayscale Image', gray_image)
cv2.imshow('HSV Image', hsv_image)

cv2.waitKey(0)
cv2.destroyAllWindows()

