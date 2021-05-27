#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed May 26 16:03:38 2021

@author: walberto

Graficas de la eficiencia Detector de Cl2
"""

from scipy.stats import norm
import matplotlib.pyplot as plt
import numpy as np
import scipy as sp
import scipy.optimize 

# Eficiencia Energetica

Eng = [] # energia en MeV
Even = [] # Numero de eventos
Elec = [] # electrones detectados
EnEff =[] # Eficiencia de energia

with open('Eficiencia_Energia.txt') as file1:
    for line in file1:
        part = line.split(",")
        Eng.append(float(part[0]))
        Even.append(float(part[2]))
        Elec.append(float(part[3]))
        EnEff.append(float(part[3])/float(part[2]))
        
plt.clf()

fig1 = plt.figure()
ax1 = fig1.add_subplot()

l1 = ax1.plot(Eng,Elec,'-o')
ax1.legend((l1),('Electrones detectados'),loc='upper right')
ax1.set(xlabel=r'Energia [$MeV$]',ylabel=r'Electrones detectados $e^-$')
# plt.savefig('Electrones.pdf')
plt.show() 

plt.clf()
fig2 = plt.figure()
ax2= fig2.add_subplot()

l2 = ax2.plot(Eng,EnEff,'o')

ax2.legend((l1),('Eficiencia'),loc='upper right')
ax2.set(xlabel=r'Energia [$MeV$]',ylabel=r'Eficiencia $\varepsilon (E)$')
# plt.savefig('Eficiencia_energetica.pdf')
plt.show() 

# Calculando eficiencia geometrica

Even2 = []  # eventos de rayos gamma
Gamma = []  # rayos gamma detectados
GeoEff = [] # eficiencia en la geometria

with open('Eficiencia_geometrica.txt') as file2:
    for line in file2:
        part = line.split(",")
        Even2.append(float(part[2]))
        Gamma.append(float(part[4]))
        GeoEff.append((float(part[4])/float(part[2]))*10000)
        
# Histograma
fig, ax = plt.subplots()

n, bins, patches = ax.hist(GeoEff,25, density = False)
        
# fit

(mu, sigma) = norm.fit(GeoEff)

# y = ((1 / (np.sqrt(2 * np.pi) * sigma)) **np.exp(-0.5 * (1 / sigma * (bins - mu))**2))
        
y = norm.pdf( bins, mu, sigma)

# figura
plt.clf()

fig3 = plt.figure()
ax3 = fig3.add_subplot()
ax3.hist(GeoEff,bins,normed =1)
ax3.plot(bins,y, '--')
ax3.set(ylabel=r'Densidad de Probabilidad',xlabel=r'Eficiencia Geometrica $\varepsilon_g \times 10 ^ {-4}$')
# plt.savefig('Eficiencia_geometrica.pdf')

plt.show()

# Eficiencia total

EffT = []

for value in EnEff:
    EffT.append(value*mu)

plt.clf()
fig4 = plt.figure()
ax4= fig4.add_subplot()

l5 = ax4.plot(Eng,EffT,'-o')

ax4.legend((l1),('Eficiencia'),loc='upper right')
ax4.set(xlabel=r'Energia [$MeV$]',ylabel=r'Eficiencia Total $\varepsilon _T (E) \times 10 ^ {-4}$')
plt.savefig('Eficiencia_Total.pdf')
plt.show() 

