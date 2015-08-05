#!/usr/bin/env python

import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from datetime import datetime
import numpy as np    

# Converter function
datefunc = lambda x: mdates.date2num(datetime.strptime(x, '%d %m %Y %H %M'))

# Read data from 'file.dat'
dates, counts = np.genfromtxt('counts.dat',    # Data to be read
                              delimiter=16,  # First column is 14 characters wide
                              converters={0: datefunc}, # Formatting of column 0
                              dtype=float,
                           unpack=True)   # All values are floats

print dates
fig = plt.figure()
ax = fig.add_subplot(111)
print counts
# Configure x-ticks
ax.set_xticks(dates) # Tickmark + label at every plotted point
ax.xaxis.set_major_formatter(mdates.DateFormatter('%d/%m/%Y %H:%M'))

ax.plot_date(dates, counts, ls='-', marker='o')
ax.set_title('Mid Term word count as a function of time')
ax.set_ylabel('Words')
ax.grid(True)

# Format the x-axis for dates (label formatting, rotation)
fig.autofmt_xdate(rotation=45)
#fig.tight_layout()

fig.show()
plt.show(fig)

