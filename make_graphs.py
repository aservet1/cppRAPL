#Assuming a line in the data file (.data extension) will be given as "SORT_NAME NUM_ELEMENTS TIME(ms) ENERGY(J)"

from os import listdir
from collections import defaultdict
import matplotlib.pyplot as plt

info = defaultdict(list)

for file in listdir():
    if file.endswith("test.data"):
        with open(file) as fh:
            for line in fh:
                words = line.split()
                tup = (int(words[1]), int(words[2]), float(words[3]))
                info[words[0]].append(tup)
energy_plot = plt.figure()
time_plot = plt.

for key in info.keys():
    lengths = []
    energies = []
    times = []
    for value in info[key]:
        lengths.append(value[1])
        times.append(value[2])
        energies.append(value[3])
    plt.plot()