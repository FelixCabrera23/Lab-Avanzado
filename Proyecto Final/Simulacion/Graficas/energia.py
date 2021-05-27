#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed May 26 16:03:38 2021

@author: walberto

Graficas de la eficiencia Detector de Cl2
"""

import matplotlib.pyplot as plt

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
ax1.set(xlabel=r'Energia [$MeV$]',ylabel=r'Electrones')
#plt.savefig('Electrones.pdf')
plt.show() 


plt.clf()
fig2 = plt.figure()
ax2= fig2.add_subplot()

l2 = ax2.plot(Eng,EnEff,'-o')
ax2.legend((l1),('Eficiencia'),loc='upper right')
ax2.set(xlabel=r'Energia [$MeV$]',ylabel=r'Eficiencia')

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
        GeoEff.append(float(part[4])/float(part[2]))
        
plt.clf()

fig3 = plt.figure()
ax3 = fig3.add_subplot()
ax3.hist(GeoEff,bins=20)

plt.show()





