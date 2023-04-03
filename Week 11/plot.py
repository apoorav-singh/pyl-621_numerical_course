import pandas as pd
import matplotlib.pyplot as plt 
import numpy as np
import math
import time

h = float(input("Enter the value of the step: "))

grid = int((2.5-(-2.5))/h)



df_txt_1 = pd.read_csv('QHO.txt',delimiter='\s+')


x_1 = np.array(df_txt_1.iloc[0:grid,0])
y_1 = np.array(df_txt_1.iloc[0:grid,1])
y_2 = np.array(df_txt_1.iloc[0:grid,2])

print(x_1)


plt.xlabel(r"$x\ \rightarrow$")
plt.ylabel(r"$\Psi_0(x)\ \rightarrow$")

plt.grid("on")

plt.plot(x_1,y_1,"r")
plt.plot(x_1,y_2,"x")

#i=0

#while(i<(grid-1)):
    #plt.plot(x_1[i],y_1[i],"b->")
    #plt.plot(x_1[i],y_2[i],"r->")
    #print(i)
    #time.sleep(0.1)
    #i += 1





plt.xticks(np.arange(-2.5, 2.5, 0.5))
#plt.yticks(np.arange(0, max(y_1), 0.25))
plt.title("Harmonic Osccillator Wavefunction (n=0) (h={})".format(h))

plt.legend(["Analytical Solution","Numerical Solution"])

filename = "n_0_h_" + str(h) + ".png"

plt.savefig(filename, dpi=900)
#plt.show()