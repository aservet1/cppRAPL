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
ax1 = energy_plot.add_subplot(111)
time_plot = plt.figure()
ax2 = time_plot.add_subplot(111)

for key in info.keys():
    lengths = []
    energies = []
    times = []
    for value in info[key]:
        lengths.append(value[0])
        times.append(value[1])
        energies.append(value[2])
    print(lengths, energies, times, key)
    ax1.plot(lengths, times, label = key)
    ax2.plot(lengths, energies, label = key)

ax1.set_xlabel("Array length (n)")
ax1.set_ylabel("Energy (J)")
ax1.legend()
ax2.set_xlabel("Array length (n)")
ax2.set_ylabel("Energy (J)")
ax2.legend()
energy_plot.savefig("energy_plot")
time_plot.savefig("time_plot")