#!/usr/bin/env python

import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from datetime import datetime
import numpy as np    


def minstodays( mins ):
    m=mins/(24.0*60.0)
    return m
# Converter function
datefunc = lambda x: mdates.date2num(datetime.strptime(x, '%d %m %Y %H %M'))

# Read data from 'file.dat'
dates, counts = np.genfromtxt('counts.dat',    # Data to be read
                              delimiter=16,  # First column is 14 characters wide
                              converters={0: datefunc}, # Formatting of column 0
                              dtype=float,
                           unpack=True)   # All values are floats

#print dates
fig = plt.figure()
ax = fig.add_subplot(111)
#print counts
# Configure x-ticks
n=dates.shape[0]-1
indexes=[]
for i in range(0,n):
    dif=dates[i+1]-dates[i]
    if (dif <= minstodays(5)):
        indexes.append(i)
dates2=np.delete(dates,indexes)
counts2=np.delete(counts,indexes)
print dates
print dates2.shape
ax.set_xticks(dates2) # Tickmark + label at every plotted point
ax.xaxis.set_major_formatter(mdates.DateFormatter('%d/%m/%Y %H:%M'))

ax.plot_date(dates2, counts2, ls='-', marker='o')
ax.set_title('Mid Term word count as a function of time')
ax.set_ylabel('Words')
ax.grid(True)

# Format the x-axis for dates (label formatting, rotation)
fig.autofmt_xdate(rotation=45)
#fig.tight_layout()

fig.show()
plt.show(fig)

