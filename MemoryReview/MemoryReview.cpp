#include <iostream>
using namespace std;
struct Person
{
	char name[32];
	int id;
};

int square(int& number) {
	number *= number;
	return number;
}
int Double(int* number) {
	*number *= 2;
	return *number;
}
int main()
{
	// ** REFERENCE **
	//
	// declare an int variable and set the value to some number (less than 10)
	int number = 7;
	// declare a int reference and set it to the int variable above
	int& numberRef = number;
	// output the int variable
	cout << number << endl;
	// set the int reference to some number
	numberRef = 20;
	// output the int variable
	cout << number << endl;
	// what happened to the int variable when the reference was changed? 
	// The int variable changed.
	
	// output the address of the int variable
	cout << &number << endl;
	// output the address of the int reference
	cout << &numberRef << endl;
	// are the addresses the same or different? 
	// They are the same. 
	
	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter(i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	// output the int variable to the console
	
	//square(number);
	cout << number << endl;
	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	square(numberRef);
	cout << number << endl;
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
	
	// ** POINTER VARIABLE **
	//
	// declare an int pointer, set it to nullptr (it points to nothing)
	int* numberPointer = nullptr;
	// set the int pointer to the address of the int variable created in the REFERENCE section
	numberPointer = &number;
	// output the value of the pointer
	cout << numberPointer << endl;
	// what is this address that the pointer is pointing to? (insert answer)
	// 00000010B40FF954
	
	// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << *numberPointer << endl;

	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(numberPointer);
	// output the dereference pointer
	cout << *numberPointer << endl;
	// output the int variable created in the REFERENCE section
	cout << number << endl;
	// did the int variable's value change when using the pointer?
	//Yes, yes it did.
}