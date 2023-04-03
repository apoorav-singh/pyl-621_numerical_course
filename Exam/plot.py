import pandas as pd
import matplotlib.pyplot as plt 
import numpy as np
import math
import time

h = float(input("Enter the value of the step: "))

grid = int((60-(0))/h)



df_txt_1 = pd.read_csv('RK4.txt',delimiter='\s+')


x_1 = np.array(df_txt_1.iloc[0:grid,0])
y_1 = np.array(df_txt_1.iloc[0:grid,1])
y_2 = np.array(df_txt_1.iloc[0:grid,2])

print(x_1)


plt.xlabel(r"$t\ \rightarrow$")
plt.ylabel(r"$\vec{x}\ \rightarrow$")

plt.grid("on")

    
plt.plot(x_1,y_1,"r")

#plt.plot(x_1,y_2,"x")

i=0

plt.xticks(np.arange(0, 60, 5))
plt.yticks(np.arange(250, 4000, 500))
plt.title("Solving Equation of Motion (h={})".format(h))


filename = "race_car_h_" + str(h) + ".png"

while(i<(grid-1)):

    plt.plot(x_1[i],y_2[i],"x")
    #print(i)
    plt.pause(0.01)
    i += 1

plt.legend(["Analytical Solution","Numerical Solution"])
#plt.savefig(filename, dpi=900)
plt.show()