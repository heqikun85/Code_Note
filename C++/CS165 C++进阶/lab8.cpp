	#include <iostream>
	#include <ctime>
	#include <iomanip>
	using namespace std;
	void printtrafficinfo( struct Month month);
	int getHighest(double array[], int a);


	struct Month {
		
		int gbridge;
		int bbridge;
		int sbridge;	
		
	};




	void printtrafficinfo( struct Month month){
		cout << month.gbridge << endl;
		cout << month.bbridge << endl;
		cout << month.sbridge << endl;
		

	}



	int main() {
		struct Month month;
		const int MAX_MONTH = 3;
		Month monthData[MAX_MONTH];
		double sum[3];
		double ave[3];
		int largenumber;
		int highest = 0;
		
		
		
		for (int i = 0; i < 3; i++) {
	       cout << "Enter month " << i+1 << " traffic across the Golden Gate Bridge: " << fixed << setprecision(2);
		   cin >> monthData[i].gbridge;
		
		   cout << "Enter month " << i+1 << " traffic across the Bay Bridge: " << fixed << setprecision(2);
		   cin >> monthData[i].bbridge;
		
		   cout << "Enter month " << i+1 << " traffic across the San Mateo Bridge: " << fixed << setprecision(2);
		   cin >> monthData[i].sbridge;
		   cout << endl;

		}
		

		  sum[0]= monthData[0].gbridge + monthData[0].bbridge + monthData[0].sbridge;
		  sum[1]= monthData[1].gbridge + monthData[1].bbridge + monthData[1].sbridge;
		  sum[2]= monthData[2].gbridge + monthData[2].bbridge + monthData[2].sbridge;
		  ave[0]= sum[0]/3;
		  ave[1]= sum[1]/3;
		  ave[2]= sum[2]/3;


	       cout << "The average traffic for the month1 is: " << ave[0] <<  endl;
		   cout << "The average traffic for the month2 is: " << ave[1] <<  endl;
		   cout << "The average traffic for the month3 is: " << ave[2]  << endl;
		  
		 
		  for(int i = 0; i<3; i++){
			if(monthData[i].gbridge > highest){
				highest = monthData[i].gbridge;
			}
			if(monthData[i].bbridge > highest){
				highest = monthData[i].bbridge;
			}
			if(monthData[i].sbridge > highest){
				highest = monthData[i].sbridge;
			}
		}
		
		   cout << "The largest traffic count of any bridge in any one month is: " << highest << endl;
		
	}
