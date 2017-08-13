# coding: utf-8
from sklearn import datasets
iris = datasets.load_iris()
iris
digits = datasets.load_digits()
digits
digits.target
digits.target_names
digits.data
digits.images
import numpy as np
number_of_samples = len(10)
y = range(100)
number_of_samples = len(y)
random_indices = np.random.permutation(number_of_samples)
num_training_sets = int(number_of_samples*0.70)
num_training_sets
x = range(100,1,-1)
x_train = x[random_indices[:num_training_sets]]
x_train = x[random_indices[:10]]
x_train = x[10]
x_train = x[:num_training_sets]
type(random_indices)
random_indices
random_indices[10]
random_indices[:num_training_sets]
x[random_indices[:num_training_sets]]
x[random_indices[:num_training_sets].tolist()]
x[random_indices[:num_training_sets]]
x[random_indices[:num_training_sets].asscalar()]
random_indices[:num_training_sets]
random_indices[:num_training_sets].asscalar()
random_indices[:num_training_sets]
random_indices[:num_training_sets]
int(random_indices[:num_training_sets])
type (random_indices[:num_training_sets])
