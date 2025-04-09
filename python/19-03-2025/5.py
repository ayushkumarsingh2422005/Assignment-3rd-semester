from itertools import chain

def knapsack_with_groups(items, groups, W):
    n = len(items)
    group_map = {i: {i} for i in range(n)}
    
    for group in groups:
        merged = set(chain.from_iterable(group_map[i] for i in group))
        for i in merged:
            group_map[i] = merged
    
    unique_groups = list({frozenset(group) for group in group_map.values()})
    
    dp = [0] * (W + 1)
    
    for group in unique_groups:
        group_weight = sum(items[i][0] for i in group)
        group_value = sum(items[i][1] for i in group)
        
        for w in range(W, group_weight - 1, -1):
            dp[w] = max(dp[w], dp[w - group_weight] + group_value)
    
    return dp[W]

# Example Usage
items = [(2, 4), (3, 5), (1, 3)]
groups = [{0, 2}]
W = 5
print(knapsack_with_groups(items, groups, W)) 