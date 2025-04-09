import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0, 11)
y = 2*x+1
print(y[5])
plt.plot(x,y)
plt.show()