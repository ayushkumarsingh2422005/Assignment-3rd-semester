import matplotlib.pyplot as plt

categories = ["Math", "Science", "English"]
scores = [88, 75, 90]

colors = ['blue' if score < max(scores) else 'green' for score in scores]

plt.bar(categories, scores, color=colors)
plt.show()