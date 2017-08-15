
from sklearn import datasets
import numpy as np

iris = datasets.load_iris()

x = iris.data[:, :2]
y = iris.target

number_of_samples = len(y)
random_indices = np.random.permutation(number_of_samples)
num_training_sets = int(number_of_samples*0.70)

x_train = x[random_indices[:num_training_sets]]
y_train = y[random_indices[:num_training_sets]]

y_test = x[random_indices[num_training_sets:]]
x_test = y[random_indices[num_training_sets:]]

model.fit(x_train,y_train)

query_point = x_test[0]
true_class_of_query_point = y_test[0]

predict_class = model.predict([query_point])


