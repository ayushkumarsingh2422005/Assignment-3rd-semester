import matplotlib.pyplot as plt
x = [1, 2, 3, 4]
y = [2, 4, 6, 8]

plt.plot(x, y, label="Linear Growth")
plt.xlabel("X-axis Label")
plt.ylabel("Y-axis Label")
plt.title("Plot Title")
plt.legend()
plt.show()