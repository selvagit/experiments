
x = range(101,1,-1)
y = range(101)

X = np.array (x)
Y = np.array (y)


number_of_samples = len(Y)
random_indices = np.random.permutation(number_of_samples)
num_training_sets = int(number_of_samples*0.70)

x_train = X[random_indices[:num_training_sets]]
y_train = Y[random_indices[:num_training_sets]]

y_test = Y[random_indices[num_training_sets:]]
x_test = X[random_indices[num_training_sets:]]

model.fit(x_train,y_train)
query_point = x_test[0]
true_class_of_query_point = y_test[0]

predict_class = model.predict([query_point])

# principal component analysis

import sklearn.cross_validation 

x_train , x_test , y_train , t_test = train_test_split(
x,y,test_size=0.25 ,random_state=42)

n_components = 150

pca = RandomizedPCA(n_components=n_components, whiten=true).fit(x_train)

eigenfaces = pca.components_.reshape((n_compoenets, heigth,width))

x_train_pca = pca.transform(X_train)
x_test_pca = pca.transform(X_test)

Knn_classifier = KNeighbourClassifier(n_neighbors = 5)
knn_classifier.fit (X_train_pca,y_train)

y_pred_test = knn_classifier.predict(x_test_pca)