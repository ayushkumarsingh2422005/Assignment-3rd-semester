class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
        self.ratio = value / weight
def knapsack_greedy(W, val, wt):
    n = len(val)
    items = [Item(val[i], wt[i]) for i in range(n)]
    items.sort(key=lambda x: x.ratio, reverse=True)
    for i in items:
        print(i.value, i.weight, i.ratio)
    
    total_value = 0
    for item in items:
        if item.weight <= W:
            W -= item.weight
            total_value += item.value
        else:
            break
    
    return total_value

# Example 1
W1 = 4
val1 = [1, 2, 3]
wt1 = [4, 5, 1]
print(knapsack_greedy(W1, val1, wt1))
