def q01():
    n = 112406
    total = 0
    for i in range(1, n):
        if n % i == 0:
            total = total + i
    
    print("Soma dos divisores = " + str(total))
    if total > n:
        print("é abundante")
    else:
        print("não é abundante")

import random
import numpy as np
import math 
import statistics

def q02():
    N = 1000000
    x = np.zeros(N)
    y = np.zeros(N)
    x2 = np.zeros(N)
    y2 = np.zeros(N)
    
    for i in range(N):
        x[i] = random.uniform(0,1)
        y[i] = random.uniform(0,1)
    
    n = 0
    
    for i in range(N):
        func1 =  2 * x[i]**2 + 3 * y[i]
        func2 = x[i]**2 +  y[i]
        
        if func1 <= 1 and func2 <= 1:
            n = n + 1
            x2[n] = x[i]
            y2[n] = y[i]
    
    print(1 * n / N)

def q03():
    y = np.array([-2, 3, 4, 2, -1 , -5, -7, -3, 5 ,8, 9, 1, -8, -4, -3, -2, 2, 5, 8, 9, 10, 3, 2, -5])
    n = len(y)
    x = np.linspace(0, n, n)
    
    p = np.polyfit(x, y, 1)
    
    s = math.cos(p[0]**2) + math.cos(p[1]**2)
    
    print(n)
    print(x)
    print(p)
    print(s)

def q03_neto():
    y = np.array([3, 3, 6, 2, -1, -5, -7, -3, 5, 8, 9, 10, 8, 4, -3, -2, 2, 5, 8, 9, 10 ,3, 2, -5])
    n = len(y)
    x = np.linspace(0, n, n)
    
    p = np.polyfit(x, y, 3)
    
    s = p[0]**3 + p[1]**3 + p[2]**3 + p[3]**3
    print(p)
    print(s)

def modelo(i):
    if i == 0:
        return 0.8
    
    a = modelo(i - 1)
    return 3.92 * a * (1 - (0.81 * a))
    
def q04():
    N = np.zeros(60)

    for i in range(0, 60):
        N[i] = modelo(i)

    print("média")
    print(N.sum()/len(N))
    
    print("mediana")
    print(np.median(N))
    
    print("devio padrao")
    print(statistics.pstdev(N))
    
def modelo_neto(i):
    if i == 0:
        return 0.9
    
    a = modelo_neto(i - 1)
    return 3.94 * a * (1 - (0.81 * a))
    
def q04_neto():
    N = np.zeros(40)

    for i in range(0, 40):
        N[i] = modelo_neto(i)

    print("média")
    print(N.sum()/len(N))
    
    print("mediana")
    print(np.median(N))
    
    print("devio padrao")
    print(statistics.pstdev(N))


        