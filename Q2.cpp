#include<iostream>

using namespace std;

struct employ{
	string jobID;
	int deadline;
	long int profit;
};

//find the max profit from the each slot
employ find_max(employ max, employ job){
	
	if(max.profit> job.profit){
		return max;
	}
	else{
		return job;
	}
}

void compare( employ arr[], int n){
	int max_deadline =arr[n-1].deadline;
	int j=0;
	for(int i=1; i<=max_deadline; i++){
		
		employ max;
		max.profit=0;
		while(arr[j].deadline<=i){
			max=find_max(max,arr[j]);
			j++;
		}
		cout<<max.jobID<<endl;
	}
}


int main(){
	employ arr[]={{"J1",2,90},{"J2",2,20},{"J3",1,40},{"J4",1,30},{"J5",4,65},{"J6",1,35},{"J7",3,50}};
	cout<<"Job Schedulling"<<endl;
	int n=sizeof(arr)/sizeof(arr[0]);
	
	//sorting
	employ temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[j+1].deadline<arr[j].deadline){
				temp.deadline=arr[j+1].deadline;
				temp.jobID=arr[j+1].jobID;
				temp.profit=arr[j+1].profit;
				arr[j+1].deadline=arr[j].deadline;
				arr[j+1].jobID=arr[j].jobID;
				arr[j+1].profit=arr[j].profit;
				arr[j].deadline=temp.deadline;
				arr[j].jobID=temp.jobID;
				arr[j].profit=temp.profit;	
			}
		}
	}
	cout<<"The output is :"<<endl;
	compare(arr,n);
	
	
}
