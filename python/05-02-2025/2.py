tpl = (
    (1, 2, 3, 3),
    (1, 2, 3),
    (1, 2, 3, 4),
    (5, 6, 7),
    (5, 2)
)
tpl = sorted(tpl, key=sum, reverse=True)
print(tpl[1])
