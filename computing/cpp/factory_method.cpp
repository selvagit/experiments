#include <iostream>
#include <string>

class Shape {
	public :
		virtual void draw (void) = 0;
		static Shape *Create (std::string type);
};

class circle : public Shape {
	public :
		void draw(void){
			std::cout << "circle" << std::endl;
		}
};

class square : public Shape {
	public :
		void draw(void){
			std::cout << "square" << std::endl;
		}
};

Shape * Shape::Create (std::string type){
	if(type == "circle"){
		std::cout << "creating circle" << std::endl;
		return new circle();
	}

	if(type == "square") {
		std::cout << "creating circle" << std::endl;
		return new square();
	}

	return NULL;
};


int main (){

	Shape *cir = Shape::Create("circle");
	if ( cir != NULL ) cir->draw();
	return 0;
}
