import matplotlib.pyplot as plt

categories = ['A', 'B', 'C', 'D', 'E']
values = [5, 7, 3, 8, 6]

plt.bar(categories, values)
plt.xticks(rotation=45)
plt.show()