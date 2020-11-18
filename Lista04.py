import statistics as st
import matplotlib.pyplot as fig
import numpy as np

x = [5,5,5,4,3,2,4,1,1,1,3,3,3,3,3,3,2,3,1,2,1,2,5,4,3,1,3]

'''fig.subplot(2, 1, 1)
fig.plot(x)
fig.subplot(2, 1, 2)
fig.hist(x, 5, normed = True)
fig.clear()'''

'''p=[6,7,8,7,5,5,6,4,7,10,10,11,10,11,10,12,9,8,7,8,6,7]
p = np.array(p)
n = len(p)
ret = (p[1:n] - p[0:n - 1])/p[0:n - 1]
fig.subplot(2, 2, 1)
fig.plot(p)

fig.subplot(2, 2, 2)
fig.plot(ret)

fig.subplot(2, 2, 3)
fig.hist(ret, 5)'''

'''dados = [-2, -3, -1, -1, -1, 1, 2, 1, -1, -2, 1, 1,2, 2, 1, 1, 2, 2, 3, 2, 1, 1, -1, -1, 2, 3, 2, 1, 2, -1, -3, 2]
dados = np.array(dados)
n = len(dados)
ret = (dados[1:n] - dados[0:n - 1])/dados[0:n-1]
fig.subplot(3, 1, 1)
fig.plot(dados)
fig.subplot(3, 1, 2)
fig.plot(ret)
fig.subplot(3, 1, 3)
fig.hist(ret, 5)'''

'''pts = [5, 6, 7, 6, 7, 5, 6, 4, 5, 6, 4, 5, 6, 4, 9, 10, 8, 7, 9, 2, 1, 0, 2, 3, 2, 3, 1, 1, 2, 3, 4, 3, 1, 2, 3, 5, 4, 3]
fig.subplot(3, 1, 1)
fig.plot(pts)
fig.subplot(3, 1, 2)
fig.hist(pts, 5)

fig.show()'''