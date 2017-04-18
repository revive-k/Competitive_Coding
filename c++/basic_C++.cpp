/*..................................
.....@ Vivek Ranjan ................
..................................*/

//program to practice basic c++ 
#include <bits/stdc++.h>		//this header combines all necessary headers like cstdio,iostream,etc.
#include "quick.h"				//this header has been added for quicksort function used below
using namespace std;			//C++ library routines are kept in the standard namespace(declarative region) that includes cout,cin,map,vector,etc. So this line is written.

#define MAX(a, b) ( a > b ? a : b )							//this is a macro defining MAX variable
#define SWAP(x, y) { x = x + y; y = x - y; x = x - y; } 	//this is a macro defining SWAP variable
enum week{ sunday, monday, tuesday, wednesday, thursday, friday, saturday};		//enum data type declares its each member with a constant. Here default value of constant is 0. So Sunday will print 0. But we can change the value as required.

int cbv(int cv);
int cbr(int &cr);
void stf();
string & func1();
double fnovl(int a);
double fnovl(double a);
double average(int count,...);
struct St{							
	int ia;						//each member of structure is public by default
	int ib;						
	int ic;
};	
typedef string str;				//typedef helps us define datatype of our own like str and no are defined datatypes here
typedef int no;
struct Student{
	str name;					//name is a variable of str type(which is defined as string above)
	no id;						//id is a variable of no type(which is defined as int above)
};	
class Class1{
	int c1;						//each member of class is private by default
public:							//to access members of a class outside it, members must be declared public 
	void setvalue(int sv){		//here setvalue method and getvalue method are declared public to access them in main
		c1 = sv;				//it is more convenient to declare methods inside the class and define them outside the class unlike here.
	}
	int getvalue(){
		cout << "Value of 'this' in getvalue func is :" << this << endl;	//this line is to check 'this' pointer. It gives the address of the object which invokes(calls) the method.
		return c1;
	}
};
class Cube{						
public:
	int side1;						
	Cube(){}					//an example of default constructor
	Cube(int x){
		side1 = x;				//an example of parametrised constructor
	}
	Cube(Cube & copy){
		side1 = copy.side1;		//an example of copy constructor
	}
};
class Opt{									//class for operator overloading
    public:
    int val;
    void setvalue(int x){
        val = x;
    }
    /*Opt operator+(Opt obj){				//this method returns object as a sum
        Opt temp;							//here it takes only one argument as an object bcoz here operator function is a member function. So it will take left hand argument automatically.  
        temp.val = val + obj.val;			//here val is for left hand argument and obj.val is for right hand argument
        return temp;						//it returns object which contains the sum of c11 and c21
    }*/										//In case of member function and friend function, it happens like here. But with non-member function, it will take both arguments. If there is unary operator then no argument for member and friend function and one argument for non-member function.
    //OR(below code instead of upper one)
    int operator+(Opt obj){					//this method returns integer as sum			
    	return val + obj.val;				//here it takes only one argument as an object bcoz the left hand argument is automatically passed.
    } 										//it returns integer which is the required sum of c11 and c21
};
namespace first_space{							 	//namespace refers to a declarative region
	void func(){									//here function 'func' is declared in both the regions or namespaces(first_space & second_space)
		cout << "Inside First namespace" << endl;	//Using namespace(defined below here), we can define the context in which names are defined
	}												
}
namespace second_space{
	void func(){
		cout << "Inside Second namespace" << endl;
	}
}	
using namespace first_space;						//So here we have cleared the context of space of function 'func', i.e it is called from first_space. We can also use an alternate to clarify the context which is mentioned below. 


int main(){
	
	//pointers
	cout << "POINTERS:-" << endl;
	int p, *ip;
	p = 9;
	ip = &p;
	cout << "the value of x is :" << p << endl << "the value of *ip is :" << *ip << endl;


	//references
	cout << "REFERENCES:-" << endl;
	int r;
	r = 7;
	int &rf = r;																		//references must be initialised at the time of declartion
	cout << "the value of r is :" << r << endl << "the value of rf is :" << rf << endl; 
	rf = 1;
	cout << "the value of r is :" << r << endl << "the value of rf is :" << rf << endl;	//On changing the value of reference, the value of variable also changes


	//print array string using pointers
	cout << "PRINT ARRAY STRING USING POINTERS:-" << endl;
	char str[] = "string";										//it can also be scanned as char str[] = { 's','t','r','i','n','g',0 };
	for( char *cp1 = str; *cp1; cp1++ ){						//here char datatype stores the address of string
		cout << *cp1;
	}
	cout << endl;


	//stl string printings
	cout << "STL STRING:-" << endl;
	string s = "Vivek";				//here unlike array string, last element is not null character
	cout << s << endl;				//printing using cout
	printf("%s\n", s.c_str());		//printing using printf
	int l1 = s.length();
	for( int i1 = 0; i1 < l1; i1++ ){
		cout << s[i1];
	}
	cout << endl;					//printing using for loop


	//call by value & call by reference
	cout << "CALL BY VALUE & CALL BY REFERENCE:-" << endl;
	int cv = 2;	
	cout << "the value of variable returned from func is :" << cbv(cv) << endl;	//call by value(in this, actual variable declared in main does not change its value.Just a copy is created in function called.)
	cout << "the actual value of variable remains same :" << cv << endl;
	int cr = 2;
	cout << "the value of variable returned from func is :" << cbr(cr) << endl;	//call by reference(in this, actual variable declared in main changes its value bcoz the address of variable is copied in function called.)
	cout << "the actual value of variable changes :" << cr << endl;	


	//static variable
	cout << "STATIC VARIABLE:-" << endl;
	stf();		//static variable is allocated memory only once in the beginning before main is called.It behaves as a global variable which is given memory in the very beginning.
	stf();


	//returning string from a function 
	cout << "RETURNING STRING:-" << endl;
	cout << "String returned is :" << func1() << endl;


	//function overloading
	cout << "FUNCTION OVERLOADING:-" << endl;
	double fo = 12.876;			
	cout << "Value of fo is :" << fnovl(fo) << endl;	//see explanation below near overloading functions
	

	//variable number of arguments
	cout << "VARIABLE ARGUMENTS:-" << endl;											//variadic functions take variable number of arguments
	cout << "Average value of 4, 7, 9 is :" << average(3, 4,7,9) << endl;			//here first parameter(3) is count of number of arguments and then others are arguments.
	cout << "Average value of 5, 6, 7, 8, 1 is :" << average(5, 5,6,7,8,1) << endl;


	//including desired header file
	cout << "INCLUDING HEADER FILE:-" << endl;
	int hf[5] = {7, 4, 9, 0, 3};
	quicksort(hf, 0, 4);			//this function has been used from the header file 'quick.h'
	cout << "Sorted array is :" ;	
	for(int i2= 0; i2 < 5; i2++){
		cout << hf[i2] << " ";
	}
	cout << endl;


	//defining macros
	cout << "MACROS:-" << endl;
	int mac1 = 5;
	int mac2 = 9;
	cout << "Maximum is :" << MAX(mac1,mac2) << endl;	//here MAX is a macro to find maximum of two numbers
	cout << "Value of mac1 is :" << mac1 << " Value of mac2 is :" << mac2 << endl;
	SWAP(mac1,mac2);									//here SWAP macro swaps values 
	cout << "Value of mac1 is :" << mac1 << " Value of mac2 is :" << mac2 << endl;


	//defining structures
	cout << "STRUCTURE:-" << endl;																					// members of a structure are public by default
	St z = { 3, 6, 9 };																								//z is a variable of structure 'St' type declared above OR object of structure 'St' is created
	cout << "Value of ia is :" << z.ia << " Value of ib is :"  << z.ib << " Value of ic is :"  << z.ic << endl; 	//here variables of structure are called by element selection operator(.)
	St *po;																											//a pointer of type St is created which points the address of z
	po = &z;
	cout << "Value of ia is :" << po->ia << " Value of ib is :"  << po->ib << " Value of ic is :"  << po->ic << endl;//here variables of structure are called by referring pointers


	//defining class
	cout << "CLASS:-" << endl;
	int cls = 23;									//members of a class are private by default
	Class1 obj1;									//object of Class1 is created 
	obj1.setvalue(cls);								//method setvalue() of Class1 is called
	cout << "Value is :" << obj1.getvalue() << endl;//method getvalue() of Class1 is called

	//Note:-In C++, structure and class are very similar instead of the fact that members of a structure are public by default whereas members of a class are private by default


	// Default Constructors 
	cout << "DEFAULT CONSTRUCTORS:-" << endl;
	Cube c0;												//As soon as the object is created, the constructor(here default constructor) is called which initialises it's data members
	cout << "Value is :" << c0.side1 << endl;				//side1 variable of Class Cube is called(here it should print the default value of the datatype(int) of side variable which is 0 but it is printing 36. It's compiler problem.)


	//Parametrised constructor
	cout << "PARAMETRISED CONSTRUCTORS:-" << endl;
	Cube c1(20);										   //By using parameterized construcor, we have initialized 3 objects with user defined values(20, 40, 70)
	Cube c2(40);
	Cube c3(70);
	cout << "Value of sides are :" << c1.side1 << " " << c2.side1 << " " << c3.side1 << endl;


	//Copy constructor
	cout << "COPY CONSTRUCTORS:-" << endl;
	Cube copy = c1;										   //here object copy is initialised with previous defined object c1. So all its member is copied in object copy.
	cout << "Value is :" << copy.side1 <<endl;


	//Using Namespace
	cout << "USING NAMESPACE:-" << endl;
	func();												   //here context has been cleared by using namespace written above(this func is of first_space)
	second_space :: func();								   //alternate way of clearing the context(this func is of second_space)


	//this pointer
	cout << "THIS POINTER:-" << endl;
	Class1 object1;
	Class1 object2;
	cout << "Address of object which invokes the method getvalue is :" << &object1 << endl;	//the address printed here and the address printed on calling getvalue func is same.
	object1.getvalue();																		// So we can conclude that 'this' pointer gives the address of the object which invokes the method.
	cout << "Address of object which invokes the method getvalue is :" << &object2 << endl;
	object2.getvalue();


	//A class has 3 type of functions- 1.Member functions  2.Non-member functions  3.Friend functions
	//Member functions are those functions which are a part of the class or lies inside the class. These are identified by 'classname :: functionname' when defined outside the class.
	//Non-member functions are those functions which are not a part of the class. These are simply written without any scope resolution( :: )
	//Friend functions are those functions which are neither member nor non-member. These functions are written with keyword 'friend' and are outside the class. It has the right to access all private and protected members of the class.


	//Operator Overloading
	cout << "OPERATOR OVERLOADING:-" << endl;
	Opt c11;
    Opt c21;
    c11.setvalue(5);
    c21.setvalue(7);
    /*Opt c = c11 + c21;								//method 1 as stated above
    cout << "Value of a+b is :" << c.val << endl;*/
    	//OR(below code instead of upper one)
    cout << "Value of a+b is :" << c11 + c21 << endl;	//method 2 as stated above


    //new and delete keyword
    cout << "NEW AND DELETE:-" << endl;			//new keyword creates a specialized memory and makes it permanent unless we use delete keyword to delete the memory. On not using new, we were using dynamically allocated random memory which was collapsed as soon as the class collapsed.
    Opt *cb1 = new Opt;							//the cb1 pointer stores the address of the specialized memory(here Opt class is used to demonstrate)
    cb1->setvalue(3);							//new helps us to keep track of memory allocated
    cout << "Value is :" << cb1->val << endl;
    delete cb1;									//delete keyword deletes the memory allocated


    //checking size of different data types
    cout << "SIZE OF DATA TYPES:-" << endl;
    cout << "Size of char in bytes :" << sizeof(char) << endl;				//multiply by 8 to get size in bits
    cout << "Size of int in bytes :" << sizeof(int) << endl;
    cout << "Size of short int in bytes :" << sizeof(short int) << endl;
    cout << "Size of long int in bytes :" << sizeof(long int) << endl;
    cout << "Size of long long int in bytes :" << sizeof(long long int) << endl;
    cout << "Size of float in bytes :" << sizeof(float) << endl;
    cout << "Size of double in bytes :" << sizeof(double) << endl;


    //converting octal, hexadecimal, binary numbers in decimal form
    cout << "CONVERTING OCTAL, HEXADECIMAL AND BINARY NUMBERS IN DECIMAL FORM:-" << endl;
    long long int x;
    x = 0221;													//number with 0 in the beginning represents octal(every digit should be less than 8) 
    cout << "Decimal of given octal is :" << x << endl;			//Compiler will print decimal number so it converts this into decimal
    x = 0xf46;													//number with 0x in the beginning represents hexadecimal
    cout << "Decimal of given hexadecimal is :" << x << endl;
    x = 0b1101;													//number with 0b in the beginning represents binary
    cout << "Decimal of given binary is :" << x << endl;


    //bug in floating numbers
    cout << "BUG IN FLOATING NUMBERS:-" << endl;
    float x1;
    x1 = 0.1 + 0.1 + 0.1;
    cout << "Value of number is :" << x1 << endl;						//here value of x1 is 0.3 but it will print false
    if(x1 == 0.3)														//it is bcoz the floating point numbers are rounded off. If we will print it upto 15-20 decimal places then we will get to know.
    	cout << "true" << endl;		
    else
    	cout << "false" << endl;
    printf("Value of number upto 15 decimal places is :%0.15f\n",x1);	//here it shows that floating numbers are not exact. They are rounded off.


    //There are various character escape sequences like '\n','\t','\\' and many others. Google them to know there functionality.
    //The variables defined with a predefined width are called bit fields. We can adjust the size of a variable defined by using bit field. Syntax is :struct{datatype  member_name : width ;}; ex - struct Age{unsigned int age : 3;};
    //int main() and int main(void) has no difference in C++. It shows that main cannot take any argument. But both are not the same in C. In C, if a function signature doesn’t specify any argument, it means that the function can be called with any number of parameters or without any parameters. So it is necessary to add void for no parameter in C.
    //The 'auto' keyword creates variable of required type. If a function returns a string and a variable is defined as auto then it will print a string. If func returns an integer, then it will print an integer. Auto variable must be intialised at the time of declaration.
    //Pre-increment(++x) is more efficient than post-increment(x++).Google for details. 
    //Left-shift(<<) multiplies the number by (2^n) where n is the number of shifts while right-shift (>>) divides the number by (2^n). 


	//Enumeration
	cout << "ENUMERATION:-" << endl;
	enum week today;										//enum is defined above
	today = wednesday;										//today will take the value of wednesday
	cout << "Today is " << today + 1 << "th day" << endl;	//So it prints 4th day.


	//Typedef 
	cout << "TYPEDEF:-" << endl;
	Student s11 = { "Ram", 006 };
	cout << s11.name << " has ID No :" << s11.id << endl;


	//Typeid operator
	cout << "TYPEID:-" << endl;
	Cube t1;						//here above defined class 'Cube' is used
	Opt t2;							//here above defined class 'Opt' is used
	if(typeid(t1) == typeid(t2)){	//typeid operator checks the type of a variable. Here it matches types of both objects variable.
		cout << "same" << endl;
	}
	else{
		cout << "different" << endl;
	}
	cout << "Variable is of type :" << typeid(t2).name() << endl;		//generally it returns some random things. So typeid is basically familiar with equality comparablity or it checks equality as above.


	//some cool string functions
	cout << "STRING FUNCTIONS:-" << endl;
	string str1("My name is Vivek. ");
	string str2;
	string str3;
	str2 = str1;																										//here str1 is copied to str2
	str3.assign(str1);																									//assign function does the same as above. It will copy str1 to str3.
	cout << "To check 'assign' function : " << str1 << str2 << str3 << endl;
	cout << "To check 'at' function : " << str1[3] << " " << str1.at(3) << endl;										//here at function does the same as str1[3]
	cout << "To check 'substring' function : " << str1.substr(3,7) << endl;												//'substr' prints a particular section of the string. It takes two parameters. First the index to start from and second the number of characters to print.
	string str4("I love to code. ");
	cout << "To check 'swap' function : " << endl;
	cout << "Before swapping : " << str3 << str4 << endl;
	str3.swap(str4);																									//here swap function interchanges the value of two variables
	cout << "After swapping : " << str3 << str4 << endl;
	cout << "To check 'find & rfind' functions : " << endl;
	cout << "Index of 'e' from beginning is :" << str1.find('e') << " ";												//here find function prints the index of the element(from beginning) which is to be found.
	cout << "Index of 'e' from end is :" << str1.rfind('e') << endl;													//here rfind function prints the index of the element(from end) which is to be found.
	cout << "Index of 'Vivek' from beginning and end :" << str1.find("Vivek") << " " << str1.rfind("Vivek") << endl;	//here index of element 'Vivek' remains same from beginning and from end bcoz there is a single word 'Vivek'. If there have been two or more words then find function will print the index of first 'Vivek'(i.e index of V) and rfind will print index of last 'Vivek'(i.e index of V)
	string str5("Hi My name is Ranjan  and i love to code.");
	cout << "To check 'erase' function : " << endl;
	cout << str5 << endl;
	cout << str5.erase(20) << endl;																						//here 'erase' function deletes all string after the provided index.
	cout << "To check 'replace' function : " << endl;
	str5.replace(14,6,"Vivek Ranjan");																					//here 'replace' function takes 3 arguments. First the index from where we start, second the number of letters to replace from that index and third the string to replace with.
	cout << "After replacing string str5 :" << str5 << endl;
	cout << "To check 'insert' function : " << str5.insert(14,"Mister ") << endl;										//insert function inserts a particular string at the given index


	cout << "-----------------------THANK YOU--------------------------" << endl;
	

	return 0;
}


//if function is created above main then there is no need of declaration there, But here the function is created below main so we have to declare it above

//call by value function
int cbv(int cv){
	cv++;
	return cv;
}

//call by reference function
int cbr(int &cr){
	cr++;
	return cr;
}

//static function 
void stf(){
    static int x = 9;	//here in the 2nd call of the function 'stf' in main, value of x will remain same because this line will be skipped(static variable is declared only once.). But when x is initialised below this line instead with declaration then x will change.  
    cout << "Value of x is :" << ++x << endl;
    x = 6;
    cout << "Value of x is :" << ++x << endl;
}

//string function 
string & func1(){
    static string s = "I am Vivek ";	//here 3 cases arise: 1.Remove reference(&) and static, then also it will work bcoz string will behave as a datatype.
    return s;							// 2.Removing & and keeping static is fine and similar as 1 bcoz it will just make variable static.
										// 3.Removing static and keeping & will create a problem bcoz we cannot return reference of a local variable(s will become local then). Search in google the reason!
}										// 4.Keeping both is also OK! Bcoz then address of static variable will be returned.

//overloading function 1
double fnovl(int a){
	a++;
	return a;				//here one function overloads the other. In C++, function is not only seen by its name or return type. The whole signature matters.
}							//Whereas in C, function is seen only by its name so this program will not compile in C.It will give conflicting type error in C.

//overloading function 2 
double fnovl(double a){
	a--;
	return a;
}

//variable arguments function 
double average(int count,...){	//count is total number of arguments and ... refers variable arguments
	va_list x;					//va_list,va_start,va_end,va_arg are included in library 'cstdarg'
	double sum = 0;
	int i;
	va_start(x, count);
	for (i = 0; i < count; i++) {
      sum = sum + va_arg(x, int);
   }
   va_end(x);
   return sum/count;
}
