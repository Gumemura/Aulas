from datetime import datetime
import math

def Q01():
    quant = 0
    for x in range(1, 2000001):
        if (x % 2 == 0 and x % 23 == 0 and x % 37 == 0):
            quant = quant + 1
    
    print("Questao 01: " + str(quant))

def Q02():
    i = 0
    posicao = 0
    maior = 0
    while i < 100:
        if(i % 2 == 0):
            x = - 2 * (i ** 2) - 30 * i + 3
        else:
            x = - 0.1 * (i ** 2) + 6 * i - 7
    
        if(x > maior):
            posicao = i
            maior = x
            
        i = i + 1
    
    print("Questao 02 a): " + str(round(maior ** 2, 2)))
    print("Questao 02 b): " + str(posicao))

def y(i):
    r = 0.1
    k = 2
    if i == 0:
        return 0.1
    else:
        ym1 = y(i - 1)
        return ym1 * (math.e ** (r * (1 - (ym1/k))))

def Q03():
    print("Questão 3: " + str(round(y(1000), 2)))
    
Q01()
Q02()
Q03()
