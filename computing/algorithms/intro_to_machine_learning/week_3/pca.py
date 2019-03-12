   
from sklearn.model_selection import train_test_split
from sklearn.decomposition import RandomizedPCA
from sklearn.decomposition import PCA
from sklearn import datasets
from sklearn.neighbors import KNeighborsClassifier

iris = datasets.load_iris()

x = iris.data[:, :2]

y = iris.target

x_train, x_test, y_train, t_test = train_test_split(x,y,test_size=0.25 ,random_state=42)

n_components = 150

pca = RandomizedPCA(n_components=n_components, whiten=True).fit(x_train)

# eigenfaces = pca.components_.reshape((n_compoenets, heigth,width)) 

x_train_pca = pca.transform(x_train)
x_test_pca = pca.transform(x_test)

knn_classifier = kNeighborsClassifier(n_neighbors = 5)
knn_classifier.fit (x_train_pca, y_train)

y_pred_test = knn_classifier.predict(x_test_pca)



