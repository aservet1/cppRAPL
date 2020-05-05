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
power_plot1 = plt.figure()
dram_pplot = power_plot1.add_subplot(111)
power_plot2 = plt.figure()
core_pplot = power_plot2.add_subplot(111)
power_plot3 = plt.figure()
package_pplot = power_plot3.add_subplot(111)
energy_plot1 = plt.figure()
dram_plot = energy_plot1.add_subplot(111)
energy_plot2 = plt.figure()
core_plot = energy_plot2.add_subplot(111)
energy_plot3 = plt.figure()
package_plot = energy_plot3.add_subplot(111)

time_plot = plt.figure()
ax2 = time_plot.add_subplot(111)


for key in info.keys():
    lengths = []
    drams = []
    cores = []
    packages = []
    times = []
    dpowers = []
    cpowers = []
    ppowers = []
    nonzerolens = []
    flag = False
    for value in info[key]:
        lengths.append(value[0])
        times.append(value[1])
        drams.append(value[2][0])
        packages.append(value[2][1])
        cores.append(value[2][2])
        if(value[1] != 0):
            nonzerolens.append(value[1])
            ppowers.append(value[2][1] / value[1])
            cpowers.append(value[2][2] / value[1])
            dpowers.append(value[2][0] / value[1])
        else:
            flag = True
    dram_plot.plot(lengths, drams, label = key)
    core_plot.plot(lengths, cores, label = key)
    package_plot.plot(lengths, packages, label = key)
    package_pplot.plot(nonzerolens, ppowers, label = key)
    dram_pplot.plot(nonzerolens, dpowers, label = key)
    core_pplot.plot(nonzerolens, cpowers, label = key)
    ax2.plot(lengths, times, label = key)


dram_pplot.set_xlabel("Array length (n)")
dram_pplot.set_ylabel("Power (W)")
dram_pplot.set_title("DRAM Power Plot")
#dram_plot.set_yscale('log')
dram_pplot.legend()

core_pplot.set_xlabel("Array length (n)")
core_pplot.set_ylabel("Power (W)")
core_pplot.set_title("CORE Power Plot")
#core_plot.set_yscale('log')
core_pplot.legend()

package_pplot.set_xlabel("Array length (n)")
package_pplot.set_ylabel("Power (W)")
package_pplot.set_title("PACKAGE Power Plot")
#package_plot.set_yscale('log')
package_pplot.legend()



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


power_plot1.savefig("dram_power_plot")
power_plot2.savefig("core_power_plot")
power_plot3.savefig("package_power_plot")
energy_plot1.savefig("dram_plot")
energy_plot2.savefig("core_plot")
energy_plot3.savefig("package_plot")
time_plot.savefig("time_plot")