import matplotlib.pyplot as plt

labels = ['Apple', 'Banana', 'Cherry', 'Date']
values = [30, 20, 25, 25]
explode = (0.1, 0, 0, 0)

plt.pie(values, explode=explode, labels=labels, autopct='%1.1f%%', startangle=90)
plt.axis('equal')
plt.show()