import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 2 * np.pi, 100)

fig, axs = plt.subplots(2, 1)

axs[0].plot(x, np.sin(x), label='sin(x)', color='blue')
axs[0].set_title('Sine Function')
axs[0].legend()

axs[1].plot(x, np.cos(x), label='cos(x)', color='orange')
axs[1].set_title('Cosine Function')
axs[1].legend()

plt.tight_layout()
plt.show()