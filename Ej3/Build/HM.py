import numpy as np
import matplotlib.pyplot as plt
import pandas 

data = np.loadtxt("dDep.txt", comments="#", delimiter=',')
# columnas: [ir, iphi, iz, dose, error]
x, y, z = data[:,0], data[:,1], data[:,2]
dose = data[:,3]

xi = x.astype(int)
yi = y.astype(int)

nx = np.max(xi) + 1
ny = np.max(yi)+ 1

mapa_dosis = np.zeros((ny, nx))

for i in range(len(dose)):
    mapa_dosis[yi[i], xi[i]] += dose[i]

plt.figure(figsize=(8, 6))
plt.imshow(mapa_dosis, origin='lower', cmap='jet', interpolation='nearest',)  
plt.colorbar(label='Dosis absorbida [Gy]')
plt.title('Mapa de dosis absorbida en el plano XY')
plt.xlabel('X [cm]')
plt.ylabel('Y [cm]')
plt.savefig("MapaDosis.png",transparent=None, dpi='figure', format="png")
#plt.show()
