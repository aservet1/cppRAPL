import random
names = ["quicksort", "mergesort", "bubblesort"]
with open("simulate.data", 'w+') as fh:
    for i in range(30):
        fh.write("{} {} {} {} {} {}\n".format(names[random.randrange(3)], random.randrange(1000, 1000000, 10000), random.randrange(200), random.random(), random.random(), random.random()))
