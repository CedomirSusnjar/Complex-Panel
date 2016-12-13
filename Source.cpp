#include "ComplexPanel.h"
int main()
{
	std::cout << "Hello!"<<std::endl<<std::endl<<"This is graphic viewer of complex panel!" << std::endl;
	
	int n;	
	ComplexPanel a(401);
	std::cout << "Enter number of complexes: "; std::cin >> n; std::cout << std::endl;
	Complex* arr = new Complex[n];
	for (int i = 0; i < n; i++) { std::cout << i + 1<<") "; std::cin >> arr[i]; }
	
	std::cout << std::endl << std::endl<<"Complex numbers you entered: " << std::endl;
	
	for (int i = 0; i < n; i++)  {  std::cout <<i+1<<". number: "<<std::setw(3)<<std::left<< arr[i];}
	for (int i = 0; i < n; i++)  {  a.markComplex(arr[i]);}
	
	a.connectNComplex(arr,n);
	
	delete[] arr;
	
	a.SaveImage(std::wstring(L"Complex.png")); 
	
	std::cout << std::endl<<"*Program connects all complex numbers you entered." << std::endl;
	std::cout <<std::endl<< "Check in folder for graphics!!";
	
	getchar();
	getchar();
}