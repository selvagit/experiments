import matplotlib.pyplot as plt

from sklearn import datasets

from sklearn import svm

digits = datasets.load_digits()

clf = svm.SVC(gamma=0.001,C=100)

x,y =digits.data[:-1], digits.traget[:-1]

