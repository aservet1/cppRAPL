#Assuming a line in the data file (.data extension) will be given as "SORT_NAME NUM_ELEMENTS TIME(ms) DRAM_ENERGY(J) CORE_ENERGY(J) PACKAGE_ENERGY(J)"

from os import listdir
from collections import defaultdict
import matplotlib.pyplot as plt

info = defaultdict(list)

for file in listdir():
    if file.endswith("out.data"):
        with open(file) as fh:
            for line in fh:
                words = line.split()
                tup = (int(words[1]), float(words[2]), (float(words[3]), float(words[4]), float(words[5])))
                info[words[0]].append(tup)

for key in info.keys():
    print(key, info[key], "\n\n")
#input()
energy_plot1 = plt.figure()
dram_plot = energy_plot1.add_subplot(111)
energy_plot2 = plt.figure()
core_plot = energy_plot2.add_subplot(132)
energy_plot3 = plt.figure()
package_plot = energy_plot3.add_subplot(133)
time_plot = plt.figure()
ax2 = time_plot.add_subplot(111)


for key in info.keys():
    lengths = []
    drams = []
    cores = []
    packages = []
    times = []
    for value in info[key]:
        lengths.append(value[0])
        times.append(value[1])
        drams.append(value[2][0])
        packages.append(value[2][1])
        cores.append(value[2][2])
    
    dram_plot.plot(lengths, drams, label = key)
    core_plot.plot(lengths, cores, label = key)
    package_plot.plot(lengths, packages, label = key)
    ax2.plot(lengths, times, label = key)


dram_plot.set_xlabel("Array length (n)")
dram_plot.set_ylabel("Energy (J)")
dram_plot.set_title("DRAM Energy Plot")
#dram_plot.set_yscale('log')
dram_plot.legend()

core_plot.set_xlabel("Array length (n)")
core_plot.set_ylabel("Energy (J)")
core_plot.set_title("CORE Energy Plot")
#core_plot.set_yscale('log')
core_plot.legend()

package_plot.set_xlabel("Array length (n)")
package_plot.set_ylabel("Energy (J)")
package_plot.set_title("PACKAGE Energy Plot")
#package_plot.set_yscale('log')
package_plot.legend()

ax2.set_xlabel("Array length (n)")
ax2.set_ylabel("Time (ms)")
#ax2.set_yscale('log')
ax2.legend()

energy_plot.savefig("energy_plot")
time_plot.savefig("time_plot")