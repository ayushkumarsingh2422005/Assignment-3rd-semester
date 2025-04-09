import cv2

# Read the image
image = cv2.imread('C:/Users/ayush/OneDrive/Desktop/Class Work/python/09-04-2025/comp-vision/logo.jpg')

# Resize the image to 400x400 pixels
resized_image = cv2.resize(image, (400, 400))

# Crop the region from (100, 100) to (300, 300)
cropped_image = image[100:300, 100:300]

# Display the resized and cropped images
cv2.imshow('Resized Image', resized_image)
cv2.imshow('Cropped Image', cropped_image)

cv2.waitKey(0)
cv2.destroyAllWindows()
