#ifndef ASSINGMENT3_H
#define ASSINGMENT3_H
template <class T>
class DynamicArray
{
public:
	DynamicArray();
	int getSize()const;
	void addEntry(T);
	bool deleteEntry(T);
	T getEntry(int);
	DynamicArray(const DynamicArray<T>&);
	DynamicArray<T>& operator=(const DynamicArray<T>&);
	~DynamicArray();

private:
	T *dynamicArray; // A private member variable called dynamicArray that references a dynamic array of type string.
	int Size; // A private member variable called size that holds the number of entries in the array.

};


#endif