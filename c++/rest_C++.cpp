/*..................................
.....@ Vivek Ranjan ................
..................................*/

//Templates, Standard c++ library, STL, Some useful functions in algorithm header file
#include <bits/stdc++.h>
using namespace std;
void traverse(vector <int> vec);
void traverselist(list <int> ls);
void traverseset(set <int> st);
void traversemap(map <int,char> mp);
void traversemultiset(multiset <int> ms);
void traversearray(int n, int x[]);

template <typename T>					//template doesnot restrict to a particular datatype. It will adjust itself aq to datatype provided. This is the way to define a template.
T bigger(T a, T b){						//here template T is used instead of any datatype.
	return (a > b ? a : b);
}

template <typename T>	
class Vivek{
	T v1,v2;
public:
	Vivek(T a, T b){					//here in whole class, template T is irrespective of the datatype
		v1 = a;
		v2 = b;
	}
	T Bigger();							//this method is defined outside(below)
};

template <typename T>					//here we are defining the Bigger method of class Vivek. Whenever we are defining any method(outside) of any class which has used a particular template then we have to again define the used template.
T Vivek <T> :: Bigger(){				//Whenever classname is written, it is wriiten with the template parameter like <name>
	return (v1 > v2 ? v1 : v2);
}

int main(){

	//template functions
	cout << "TEMPLATE FUNCTIONS :-" << endl;
	double x = 78.56, y = 96.87;
	cout << "Bigger of the two is :" << bigger(x,y) << endl;		//here both double and int type parameters are passed to the function above and it will work for both without any change.
	int x11 = 9, y11 = 3;
	cout << "Bigger of the two is :" << bigger(x11,y11) << endl;


	//template classes
	cout << "TEMPLATE CLASSES :-" << endl;
	int x1 = 45, y1 = 69;
	Vivek <int> obj1(x1, y1);										//here object of class type Vivek is created but we are using template so we have to pass the parameter of the template
	cout << "Bigger of the two is :" << obj1.Bigger() << endl;


	//writing in file                                               //In c++, we can't access a file without creating a file object. So here fout1 object is created in 'out' mode to write in file.
	cout << "WRITING IN FILE :-" << endl;							//here ofstream class is used to write in the file. Its default mode is out(to write)
	ofstream fout1;													//we can also use fstream class for both writing and reading(any other) purpose but we have to specify the mode there
	fout1.open("myFile.txt");										//here open method is called to open file. We can also do it by constructor like ofstream fout1("myFile.txt")
	fout1 << "Let's talk!!" << endl;						//here 'fout1 <<' writes in file. So there will be no console output.
	fout1 << "Do or Die!" << endl;				
	cout << "No output bcoz we are writing in file" << endl;
	fout1.close();													//file is closed by close method


	//reading file
	cout << "READING IN FILE :-" << endl;                           //fin1 object is created in 'in' mode to read file.
	ifstream fin1;													//ifstream class is used to read file. Its default mode is in(to read). fin1 file object is created to handle file
	fin1.open("myFile.txt");										//myFile.txt is opened to read by open method
	string s1;
	while(getline(fin1,s1)){										//here while continues till end of file. Getline function reads whole line from file fin1. For console input, we write getline(cin,s1)
		cout << s1 << endl;
	}
	fin1.close();													//file is closed. Here in ifstream class, there's no need to write 'file.close' bcoz it automatically closes the file when the file is completely read.


	//Standard template library(STL)
	cout << "STL :-----------------------" << endl;

	//String and its some functions
	cout << "STRING  :-" << endl;
	string str0("Hello");																		//string str0 is given value through a constructor
	cout << str0 << endl;
	string str1(str0);																			//str1 is given value of str0("Hello")
	cout << str1 << endl;
	string str2(str0,1,3);																		//here values of str0 from index 1 to 3 will be given to str2. But there's a problem. When first index becomes 0, then it takes value from index 0 to (secondindex-1).
	cout << str2 << endl;
	string str3("Hello World",5);																//str3 will take initial 5 characters of the given string, i.e, Hello
	cout << str3 << endl;
	string str4(5,'#');																			//here str4 becomes #####, i.e, it takes given character 5 times
	cout << str4 << endl;
	string str5(str0.begin(),str0.begin()+3);													//str5 will take characters from index 0 to 2(that is 3 characters) of string str0. Here begin() returns an iterator pointing to the first character of string str0.
	cout << str5 << endl;
	cout << str1.append("World!") << " or " << str1 + "World!" << endl;							//append function will add given string at the last of string. It can also be done by '+'.
	string str6;
	cout << str6.assign(str0) << endl;															//assign function assigns the value of one string to other. It can also be done by '='. 
	cout << str6.at(1) << " or " << str6[1] << endl;											//at function gives the value at the particular index. It can also be done by [].
	if(str0.compare(str6) == 0)																	//compare function compares the value of two strings and returns an integer. It can also be done by '=='.
		cout << "Strings are same" << endl;
	else
		cout << "Strings are different" << endl;
	printf("%s\n",str1.c_str());																//c_str function converts the string into c string(null terminated string)
	if(str0.empty() == true)																	//empty function checks whether string is empty or not. It returns boolean ,i.e, true(1) for empty else false(0) for non-empty
		cout << "String is empty" << endl;
	else
		cout << "String is not empty" << endl;
	cout << str1.erase(6) << endl;																//erase function deletes all characters after the given index in a string
	string str7("my name is Laden");
	cout << str7.find("is") << endl;															//find function searches the given string in the main string from beginning and returns the index of the first character of the given string
	cout << str7.rfind("is") << endl;															//rfind function searches the given string in the main string from end and returns the index of the first character of the given string
	cout << str7.insert(11,"Mister ") << endl;													//insert function inserts given string at the given index in the main string  
	cout << str7.length() << endl;																//length function gives the length of the string
	cout << str7.replace(18,5,"Don") << endl;													//replace function replaces a particular substring of the main string with the string provided. It takes three arguments- first is the starting index, second is the number of characters to be replaced and third is the replacement string   
	cout << str7.size() << endl;																//Also size function gives the length of the string
	cout << str7.substr(11,20) << endl;															//substr function prints a particular section of the string between the given indeces


	//Vector and its some functions
	cout << "VECTOR  :-" << endl;
	vector <int> vec1 (5,10);																	//vector vec1 is given value of 10, 5 times 
	traverse(vec1);																				//printing vec1
	vector <int> vec2 (vec1);																	//vector vec2 is coping vector vec1
	traverse(vec2);
	vector <int> vec3;
	for(int i=0; i<10; i++){
		vec3.push_back(i);																		//push_back function is used to insert a value at back of vector
	}																							//here value of i is given to vector vec3
	traverse(vec3);
	cout << vec3.at(3) << endl;																	//at function gives the value of particular index
	cout << vec3.front() << endl;																//front function gives the value of starting index 
	cout << vec3.back() << endl;																//back function gives the value of last index 
	cout << vec3.empty() << endl;																//empty function checks whether vector is empty or not and returns boolean value accordingly	
	vec3.pop_back();																			//pop_back function is used to delete a value from back of vector
	traverse(vec3);
	vector <int> :: iterator itv;																//here a vector iterator is defined which is made to point at 2nd index below
	itv = vec3.begin()+2;
	vec3.insert(itv,2,9);																		//insert function inserts value at given index. It takes three arguments- first iterator,second number of times to insert, third value
	traverse(vec3);
	cout << vec3.size() << endl;																//size function gives the length or size of the vector


	//List and its some functions
	cout << "LIST  :-" << endl;	
	list <int> ls1(5,3);																		//list ls1 is given value of 3 five times
	traverselist(ls1);
	cout << ls1.empty() << endl;																//empty function checks whether list is empty or not and returns boolean value accordingly	 
	list <int> ls2;
	ls2.assign(ls1.begin(),ls1.end());															//list ls2 is given(assigned) all values of ls1. Here we cannot just pass the list name bcoz it needs pointer from beginning to end to traverse
	traverselist(ls2);
	list <int> ls3;
	for(int i=0;i<10;i++){																		//list ls3 is given values of i by push_back function
		ls3.push_back(i);
	}
	traverselist(ls3);
	cout << ls3.front() << endl;																//front function gives the value of starting index
	cout << ls3.back() << endl;																	//back function gives the value of last index
	ls3.remove(4);																				//remove function deletes all elements which are equal to given value in the list
	traverselist(ls3);
	ls3.push_front(4);																			//push_front function inserts value in the beginning  
	traverselist(ls3);
	ls3.pop_back();																				//pop_back function deletes last element of list
	traverselist(ls3);
	ls3.pop_front();																			//pop_front function deletes first element of list 
	traverselist(ls3);
	list <int> :: iterator itl;																	//a iterator(pointer) of list type is created 
	itl = ls3.begin();																			//iterator is pointing to first index
	itl++;																						//here we cannot write 'itl = ls3.begin()+2' to point the iterator at 2 index bcoz list is not continous. We have to increment its pointer one by one .
	itl++;																						//now it will point to index 2	
	ls3.insert(itl,3,9);																		//insert function inserts value at given index. It takes three arguments- first iterator, number of times to insert, third value
	traverselist(ls3);
	ls3.reverse();																				//in list reverse function reverses all its elements
	traverselist(ls3);
	cout << ls3.size() << endl;																	//size function gives length of list


	//Pair and its some functions
	cout << "PAIR  :-" << endl;	
	pair <int, char> pr1(69,'V');																//pair pr1 is given value through a constructor
	cout << pr1.first << " " << pr1.second << endl;												//both elements of pair are printed
	pair <int, string> pr2;													
	pr2 = make_pair(7, "James!");																//pair pr2 is given value through make_pair function
	cout << pr2.first << " " << pr2.second << endl;
	pair <int, char> pr3(pr1);																	//pair pr3 is given value of pair pr1
	cout << pr3.first << " " << pr3.second << endl;


	//Set and its some functions
	cout << "SET  :-" << endl;	
	int arr1[8] = {0,0,1,2,3,3,4,5};															//an array is declared to fill value in set
	set <int> st1(arr1,arr1+8);																	//here set st1 is given value through constructor 
	traverseset(st1);																			//set is printed by traverseset function declared below
	set <int> st2(st1);																			//set st2 is given value(copying) of st1 through constructor
	traverseset(st2);
	set <int> st3(st1.begin(),st1.end());														//set st3 is copying st1 
	traverseset(st3);
	cout << st2.count(4) << endl;																//count function gives the number of given value in the set. We know that in set no element can repeat. So if the element is present then it will return 1 else 0.
	cout << st3.empty() << endl;																//empty function checks whether set is empty or not
	set <int> :: iterator its;																	//iterator its of set type is defined 
	its = st3.begin();
	its++;																						//iterator is incremented to point to 2nd index
	its++;
	st3.erase(st3.begin(),its);																	//erase function will delete all elements between the given indices (inclusive of 1st index)
	traverseset(st3);
	st3.insert(1);																				//insert function will add a value to set. It goes in sorted order.
	st3.insert(7);
	traverseset(st3);
	cout << st3.size() << endl;																	//size function will give the length of the set


	//Multiset and its some functions
	cout << "MULTISET  :-" << endl;
	int arr2[8] = {0,0,1,2,3,3,4,5};															//multiset is similar to set, with an exception that multiple elements can have same values. 
	multiset <int> ms1(arr2,arr2+8);
	traversemultiset(ms1);


	//Map and its some functions
	cout << "MAP  :-" << endl;	
	map <int,char> mp1;																			//map mp1 is declared. Here key is integer and mapped value is character. Here we cannot give value to map by constructor bcoz it takes both key and mapped value.
	mp1[2] = 'q';
	mp1[4] = 'w';																				//it is one way of assiging value to map. In this character value is given to corresponding key value in map.
	mp1[7] = 'r';
	mp1[2] = 't';
	mp1[4] = 'd';
	mp1[7] = 'o';
	traversemap(mp1);																			//printing map
	map <int,char> mp2;																			//map mp2 is declared
	mp2.insert(pair <int,char> (3,'v'));
	mp2.insert(pair <int,char> (4,'i'));														//it is another way of assigning a map.
	mp2.insert(pair <int,char> (8,'p'));														
	mp2.insert(pair <int,char> (3,'e'));														//Difference between the two ways of assigning is that first one does not take the mapped value if the key is repeated(that is older mapped value will be stored at that key value) but later one will replace the older mapped value with new one if key is repeated  
	mp2.insert(pair <int,char> (4,'s'));
	mp2.insert(pair <int,char> (8,'f'));
	traversemap(mp2);																			//printing map
	cout << mp1.at(4) << endl;																	//at function will print the mapped value to corresponding key value
	cout << mp1.count(8) << endl;																//count function gives the number of given key in the map. We know that in map no key can repeat. So if the key is present then it will return 1 else 0.
	mp1.erase(mp1.begin(),mp1.end());															//erase function will delete all elements within the given range
	traversemap(mp1);																			//nothing will be printed bcoz mp1 is empty
	cout << mp1.empty() << endl;																//empty function returns 1 if map is empty else 0.
	cout << mp2.size() << endl;																	//size function gives the size of map


	//Stack and its some functions
	cout << "STACK  :-" << endl;	
	stack <int> stk1;																			//stack stk1 is declared
	for(int i=0;i<5;i++){
		stk1.push(i);																			//push function inserts elements into stack
	}																							//stack cannot be traversed
	cout << stk1.size() << endl;																//size function gives the size of stack
	cout << stk1.top() << endl;																	//top function returns element at the top of stack
	for(int i=0;i<5;i++){
		stk1.pop();																				//pop function deletes elements from stack
	}
	cout << stk1.empty() << endl;																//empty function returns 1 if stack is empty else 0.
	cout << stk1.size() << endl;																//here stack is empty because all elements are popped up.


	//Queue and its some functions
	cout << "QUEUE  :-" << endl;																//a simple program to understand queue
	queue <int> qu1;
	for(int i=5;i<10;i++){
		qu1.push(i);																			//first some elements are pushed into queue
	}																							//queue will be like {5 6 7 8 9}
	for(int i=0;i<4;i++){
		int val1 = qu1.front();																	//now front value is stored in val1
		qu1.push(val1);																			//it is then again pushed in qu1
		qu1.pop();																				//and now value is popped from front
	}																							//queue will be like {9 5 6 7 8}
	for(;;){																		
		if(qu1.empty() == 1){																	//if queue will be empty, program will stop
			break;
		}
		else{
			cout << qu1.front() << " ";															//here front is printed and then popping is done
			qu1.pop();
		}
	}
	cout << endl;
	cout << qu1.empty() << endl;
	cout << qu1.size() << endl;																	//size function gives the size of queue


	//Priority Queue and its some function
	cout << "PRIORITY QUEUE  :-" << endl;
	priority_queue <int> pq1;																	//here priority queue pq1 is declared
	for(int i=4;i<15;i++){
		pq1.push(i);																			//push function is used to insert elements in pq1
	}
	while(!pq1.empty()){
		cout << pq1.top() << " ";																//here we are printing the top element of pq1 while pq1 is not empty
		pq1.pop();																				//elements are deleted from top using pop function
	}
	cout << endl;
	cout << pq1.size() << endl;																	//size function gives the size of pq1
	

	//Some useful functions in algorithm header file
	cout << "USEFUL FUNCTIONS :-----------------------" << endl;

	//sort function 
	cout << "SORT FUNC  :-" << endl;
	int a[10] = {3,9,1,4,6,0,5,7,2,4};															//sort function takes initial address and last address
	sort(a,a+10);																				//sort function sorts the array or any other container like vector,queue,etc
	traversearray(10,a);																		//here array is sorted
	vector <int> g1;																			//now we will sort a vector
    for (int i = 1; i <= 5; i++){
    	g1.push_back(2*i);
    	g1.push_back(5*i);
    }
    sort(g1.begin(),g1.end());
    for(int i = 0; i < g1.size(); i++){															
		cout << g1[i] << " ";
	}
	cout << endl; 


	//binary search function
	cout << "BINARY SEARCH FUNC  :-" << endl;													//binary search is the quickest search and is appliable on sorted array or any container. It returns 1 if element is found else 0.
	cout << binary_search(a,a+10,8) << endl;				 									//it takes 3 arguments - starting address, end address and value to find
	cout << binary_search(g1.begin(),g1.end(),10) << endl;										//here above sorted array 'a' and above sorted vector 'g1' is used


	//reverse funuction 
	cout << "REVERSE FUNC  :-" << endl;															//reverse function reverses an array or vector
	reverse(a,a+10);																			//reverse function takes two arguments - starting address and ending address
	traversearray(10,a);																		//above array is used to reverse 
	reverse(g1.begin(),g1.end());																//here above vector is used to reverse 
	traverse(g1);


	//max_element and min_element function 														//these finds maximum and minimum element in an array or vector 
	cout << "MAX_ELEMENT AND MIN_ELEMENT FUNC  :-" << endl;										//max_element and min_element function takes two arguments- starting address and ending address 
	cout << *max_element(a,a+10) << endl;														//max_element and min_element function returns a pointer to the maximum and minimum element. So to priint the value we dereference it.														
	cout << *min_element(a,a+10) << endl;														//here above array is used 
	cout << *max_element(g1.begin(),g1.end()) << endl;											//here above vector is used 
	cout << *min_element(g1.begin(),g1.end()) << endl;


	//accumulate funuction 
	cout << "ACCUMULATE FUNC  :-" << endl;														//accumulate function gives the sum of an array or a vector 
	cout << accumulate(a,a+10,0) << endl;														//it takes three arguments- starting address, ending address and initial sum
	cout << accumulate(g1.begin(),g1.end(),0) << endl;											//above array and vector is used to find their sum


	//count function 
	cout << "COUNT FUNC  :-" << endl;															//count function gives the count of the required element
	cout << count(a,a+10,4) << endl;															//it takes three arguments - starting address, ending address and value to count
	cout << count(g1.begin(),g1.end(),20) << endl;												//above array and vector is used 


	//find function 
	cout << "FIND FUNC  :-" << endl;															//find function finds the given element in the array or vector
	if(find(a,a+10,4) != &a[10])																//it takes three arguments- starting address, ending address and value to find
		cout << "Element is found" << endl;														//it returns the address of the value if present else the address of index where the array or vector just ends
	else
		cout << "Not found" << endl;


	//lower bound and upper bound functions 													//these takes 3 arguments- starting address, ending address and value to find the bounds
	cout << "LOWER BOUND AND UPPER BOUND FUNC  :-" << endl;										//lower_bound function returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’. 
	int arr3[13] = {1,0,9,2,8,3,8,4,7,6,9,2,8};													//upper_bound function returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’.
	sort(arr3,arr3+13);																			//an array 'arr3' is defined and sorted
	traversearray(13,arr3);																		//array is printed 
	cout << *lower_bound(arr3,arr3+13,8) << endl;												//here value at the lower bound is printed(it will be the same element)
	cout << lower_bound(arr3,arr3+13,8) - &arr3[0] << endl;										//index of lower bound
	cout << *upper_bound(arr3,arr3+13,8) << endl;												//here value at the upper bound is printed(it will be the element just greater than the given element)
	cout << upper_bound(arr3,arr3+13,8) - &arr3[0] << endl;										//index of upper bound	


	//vector erase function
	cout << "VECTOR ERASE FUNC  :-" << endl;													//erase function deletes the element at given position 
	g1.erase(g1.begin()+3);																		//it takes the position as an argument
	traverse(g1);


	//erase function for duplicates																//erase_unique function deletes all duplicate elements from a vector
	cout << "DUPLICATE ERASE FUNC  :-" << endl;
	vector <int> g2(arr3,arr3+13);																//vector g2 is created 
	traverse(g2);																				//intial vector is printed 
	g2.erase(unique(g2.begin(),g2.end()),g2.end());												//it is the syntax of writing this function
	traverse(g2);																				//vector after deletion is printed

	//copy_n function copies one array to another. It is not supported by the version of c++ here.Its syntax is like copy_n(source_array, size, dest_array).
	//iota function is used to assign continuous values to array.


	//some very common functions --
	//__gcd(x,y) = it finds gcd of two numbers x and y.
	//__builtin_popcountll(n) = it finds number of 1's in binary form of n that is set bits in n.


	cout << "-----------------------THANK YOU--------------------------" << endl;


	return 0;
}


//function to traverse a vector 
void traverse(vector <int> vec){
	vector <int> :: iterator it;																//here iterator it of vector type is defined
	for(it = vec.begin(); it != vec.end(); ++it){												//vector is traversed from its beginning to end
		cout << *it << " ";																		//begin and end functions point the index of starting and index of next to last element respectively 
	}
	cout << endl;
	/* OR
	for(int i=0; i<vec.size(); i++){															//alternate way of printing a vector
		cout << vec[i] << " ";
	}
	cout << endl;  */
}


//function to traverse a list
void traverselist(list <int> ls){																//traverse function for list
	list <int> :: iterator it1;																	
	for(it1 = ls.begin(); it1 != ls.end(); ++it1){
		cout << *it1 << " ";
	}
	cout << endl;
}


//function to traverse a set
void traverseset(set <int> st){																	//traverse function for set
	set <int> :: iterator it1;																	
	for(it1 = st.begin(); it1 != st.end(); ++it1){
		cout << *it1 << " ";
	}
	cout << endl;
}


//function to traverse a multiset
void traversemultiset(multiset <int> ms){														//traverse function for multiset
	multiset <int> :: iterator it1;																	
	for(it1 = ms.begin(); it1 != ms.end(); ++it1){
		cout << *it1 << " ";
	}
	cout << endl;
}


//function to traverse a map
void traversemap(map <int,char> mp){															//traverse function for map
	map <int,char> :: iterator it;
	for(it = mp.begin(); it != mp.end(); ++it){
		cout << it->first << " " << it->second << endl;
	}
}


//function to traverse an array
void traversearray(int n, int x[]){																//traverse function for array
	for(int i=0;i<n;i++){																		//here it is taking two arguments- one is size of array and other is array
		cout << x[i] << " ";
	}
	cout << endl;
}