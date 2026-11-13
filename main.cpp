#include <iostream> 
#include <string> 
#include <vector> 
#include "product.h" 


using namespace std; 

void show_products(const vector<Product>& products) {
	cout << "PRODUCTS\n"; 
	int number = 0; 
	for (Product p : products) {
		cout << number++ << ") " << p.name << endl;
	} 
	cout << endl;
	
}

void show_product(const Product& p) {
	cout << "PRODUCT DATA\n" 
		<< "Name: " << p.name << endl 
		<< "Price: " << p.get_price() << endl 
		<< "Discount  percent: " << p.get_discount() << endl 
		<< "Discount amount: " << p.get_discount_amount() << endl 
		<< "Discount price: " << p.get_discount_price() << endl << endl;
}



int main() {

	cout << "Welcome to the Product Viewer!\n\n"; 

	vector<Product> products; 
	products.push_back(Product("Canon EOS R7", 899.99, 20));
	products.push_back(Product("DJI OSMO MOBILE 8", 29.99, 0));
	products.push_back(Product("Logitech", 80.99, 0));


	show_products(products); 

	char choice = 'y'; 
	while (choice == 'y') {

	int number; 
	cout << "Enter product number: "; 
	cin >> number;

	if (number > 0 && number <= products.size()){
		Product p = products[number - 1]; 
		show_product(p); 
	} else {
		cout << "There is no product with that number!\n\n";
	}

	cout << "View another product? (y/n): "; 
	cin >> choice;
	
	}

}
