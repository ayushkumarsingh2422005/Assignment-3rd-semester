import matplotlib.pyplot as plt
import numpy as np

numbers = np.random.normal(loc=0, scale=1, size=100)

plt.hist(numbers, bins=10)
plt.show()