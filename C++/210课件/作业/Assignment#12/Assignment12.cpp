#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

struct RecType
{
    int id;
    string f_name;
    string l_name;
};

/// declare the class StudentHT
class StudentHT
{
public:
    struct NodeType
    {
        int id;
        string fname;
        string lname;
        NodeType *next;
    };
    struct NodeType **hashPtr;

    /// hash table size
    int t_Size;
    int node_Search;
    int id_Search;
    double avg_Search;

    /// constructor to initialize the hash table
    StudentHT(int htSize)
    {
        t_Size = htSize;

        /// create array to initialize the table
        hashPtr = new NodeType *[t_Size];

        /// initialize pointer with NULL values
        for(int i = 0; i < t_Size; i++)
        {
            hashPtr[i] = NULL;
        }
    }

    /// compute hash value for the student_ID
    int hashFunction(int studentID)
    {
        /// hash function
        int hashValue = studentID % t_Size;
        return hashValue;
    }

    /// insert node into hash table
    void insert(RecType item)
    {
        /// calculate hash
        int hashValue = hashFunction(item.id);

        /// store the item in hash table
        struct NodeType *newData = new struct NodeType;

        /// copy item to NodeType item
		newData-> id = item.id;
		newData-> fname = item.f_name;
		newData-> lname = item.l_name;
		newData-> next = NULL;

        /// if it is first entry in the hash table position
        if(hashPtr[hashValue] == NULL)
        {
            hashPtr[hashValue] = newData;
        }
        else
        {
            /// insert node in the linked list
            struct NodeType *temp = hashPtr[hashValue];
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newData;
        }
    }

    /// implement function search for node in hash table
    RecType search(RecType item)
    {
        id_Search++;
        int hashValue = hashFunction(item.id);

        /// search the item
        RecType *DataSearch = new RecType;
        if(hashPtr[hashValue] != NULL)
        {
            struct NodeType *temp = hashPtr[hashValue];

            temp = hashPtr[hashValue];
            while(temp != NULL)
            {
                /// increment number of node searches
                node_Search++;
                if(temp -> id == item.id)
                {
					DataSearch-> id = temp -> id;
					DataSearch-> f_name = temp -> fname;
					DataSearch-> l_name = temp -> lname;
                    return *DataSearch;
                }
                temp = temp -> next;
            }
        }

        /// return item with id -1
		DataSearch-> id = -1;
        return *DataSearch;
    }

    /// implement startStatistics to set variables to 0
    void startStatistics()
    {
        /// initialization
        id_Search = 0;
        node_Search = 0;
        avg_Search = 0;
    }

    /// implement method to end the statistics compute average
    void endStatistics()
    {
        /// calculate avg searches
        avg_Search = (double)node_Search / id_Search;
    }

    /// display statistics
    void displayStatistics()
    {
        cout << "\n Total number if id's searched: " << id_Search << endl;
        cout << " Total number of node's searched: " << node_Search << endl;
        cout << " Average number of node's search per id searched: " << avg_Search << endl;
    }
};

/// main method
int main()
{
    /// declare local variables
    ifstream infile;
    int student_id;

    /// create array of hash table objects
    StudentHT hashobj(100);
    struct RecType studentRec;

    /// starting statistics
    hashobj.startStatistics();

    /// open the file
    infile.open("Add-1.txt");

    /// display message if the file is not open
    if(!infile)
    {
        cerr << " Not able to open Add-1.txt file " << endl;
        system("pause");
        return 1;
    }

    /// open the file
    while(!infile.eof())
    {
        /// read the data id from the file
        infile >> student_id;

        /// create RecType obj
        struct RecType Data;

        /// populate the structure with data
		Data.id = student_id;

        /// item.fname item.lname
        /// insert the item in hash table
        hashobj.insert(Data);
    }

    /// close the input file
    infile.close();

    /// open the search-1 file
    infile.open("Search-1.txt");
    if(!infile)
    {
        cerr << " Not able to open Search-1.txt file " << endl;
        system("pause");
        return 1;
    }

    while(!infile.eof())
    {
        /// reading student id from file
        infile >> student_id;

        /// create rectype obj
        struct RecType item;

        /// populate the structures with data
        item.id = student_id;

        /// item.fname item.lname
        /// search the item in hash table
        studentRec = hashobj.search(item);

        /// if record found display message
        if(studentRec.id == -1)
        {
            cout << " Record not found for student ID: "<< student_id << endl;
        }

        /// otherwise record not found
        else
        {
            cout << " The student record found is: " << student_id << endl;
        }
    }

    /// close the search-1.txt file
    infile.close();

    /// call the method with the obj to calculate
    /// avg of searches
    hashobj.endStatistics();

    /// display statistics
    hashobj.displayStatistics();

	system("pause");
    return 0;
}
