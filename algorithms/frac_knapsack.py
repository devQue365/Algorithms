class ITEM(object):
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
        self.ratio = value/weight
def fractionalKnapsack(items, capacity):
    items.sort(key = lambda x: x.ratio, reverse = True)
    total_profit = 0
    for i in items:
        if(i.weight <= capacity):
            capacity-=i.weight
            total_profit+=i.value
        else:
            total_profit+=(i.ratio * capacity)
            break
    return total_profit

# __main__ segment
items = [
    ITEM(60, 10),
    ITEM(100, 20),
    ITEM(120, 30)
]

capacity = 50
max_profit = fractionalKnapsack(items, capacity)
print('Max profit :',max_profit)