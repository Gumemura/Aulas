import random
import numpy as np
import math 
import statistics

def q01():
    N = 50
    a = -0.005
    f = []
    maxValor = -10000
    minValor = 100000
    somaTotal = 0
    valor = 0
    for x in range(N):
        for y in range(N):
            valor = math.e ** (a * (5*x - y)**2) * math.cos(math.pi * (0.2 * x - y))
            
            if valor > maxValor:
                maxValor = valor
            if valor < minValor:
                minValor = valor
            
            somaTotal = somaTotal + valor
            f.append(valor)
    
    valorMedio = somaTotal / N**2
            
    print(maxValor)
    print(minValor)
    print(valorMedio)
    print(statistics.pstdev(f))

def q02():
    N = 50000000
    valor = 0
    for x in range(N + 1):
        valor = valor + ( 1/math.sqrt(2 - random.random()**2))
    
    print(valor * 3/N+1)

def q04():
    N = 5000
    w = -0.001
    y = []
    z = []
    
    for i in range(N):
        valor = 50 * math.cos(0.1 * i) + 100 * math.e**(w * i)
        
        if (i + 1) % 3 == 0:
            y.append(valor)
        elif (i + 1) % 11 == 0:
            z.append(valor)
    
    for i in range(len(y)):
        y[i] = y[i]*2
        
    print(y)
    print(z)

    
    
    print(np.amax(y))
    print(np.amin(y))

q04()

def q05():
    x=[][]
    
    for l in range(8):
        for c in ra
        
    


    