#include <iostream>
#include <string>

using namespace std;


void listStudents(string *array, int arraySize){
	
	cout<< "\n" << "Student Roster" << endl;
	cout<< "---------------" << endl;
	for(int i=0; i < arraySize; i++){
		 cout << array[i] << endl;
	}
}


void addStudent(string* &array, int & capacity, int & arraySize, string name){
  
	
	if(arraySize == capacity){
		 capacity *= 2;
		 string *temp = array;
		 array = new string[capacity];
		 
		 for(int i=0;i<arraySize;i++){
			  array[i] = temp[i];
		}
		 delete[] temp;
	}
  
	
	array[arraySize] = name;
	arraySize++;
}


void deleteStudent(string *array, int & arraySize, string name){
	
	int increase = arraySize;
	for(int i = 0;i < arraySize; i++){
		 if(array[i] == name){
			  increase = i;
			  break;
		 }
	}
	
	for(int i = increase + 1; i < arraySize; i++){
		 array[i-1] = array[i];
	}
	
	arraySize--;
}

int main(){
	
	int capacity = 2;
	int arraySize = 0;
    char choice;
	string *arr = new string[capacity];
	
	
  
	
	while(choice !='q' && choice !='Q'){
		                                                                                                                                         cout << endl;
		 cout << "Array size: " << arraySize << ", Capacity: " << capacity << endl;
		 cout << "A - Add a student" << endl;
		 cout << "D - Delete a student" << endl;
		 cout << "L - List all students" << endl;
		 cout << "Q - Quit" << endl;
		 cout << "Enter your choice: ";
		 cin >> choice;
		 
		
		
  
		 string name;
		 cin.ignore();
	
		 if(choice =='a' || choice == 'A'){
					cout << "Enter the student name to add: ";
					getline(cin, name);
					addStudent(arr, capacity, arraySize, name);
				
					
					
		}
			 
		 if(choice =='d' || choice == 'D'){
					cout << "Enter the student name to delete: ";
					getline(cin, name);
					deleteStudent(arr, arraySize, name);
					
					
		}
			 
		 if(choice =='l' || choice == 'L'){
					listStudents(arr, arraySize);
					
					
		}	
		 
	}
	return 0;
}