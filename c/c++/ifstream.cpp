//1 bai lien quan den input tu` file


#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main () {
	string s;
	int b[3][3]={{0,0,0},{0,0,0},{0,0,0}},t=0;
	ifstream a;
	a.open("RainOrShine.txt");
	while(getline(a,s)){
		for(int i=0;i<s.size();i++){
			if(s[i]=='R') b[t][0]++;
			else if(s[i]=='C')b[t][1]++;
			else if(s[i]=='S')b[t][2]++;
		}
		t++;
	}
	a.close();
	for(int i=0;i<3;i++){
		cout<<"Thang "<<i+6<<":"<<endl;
		cout<<"So ngay mua la: "<<b[i][0]<<endl;
		cout<<"So ngay co may la: "<<b[i][1]<<endl;
		cout<<"So ngay nang la: "<<b[i][2]<<endl;
	}
	if(b[0][0]>b[1][0]){
		if(b[0][0]>b[2][0]){
			cout<<"thang 6 co nh` ngay mua nhat";
		}
		else cout<<"thang 8 co nh` ngay mua nhat";
	}
	else if(b[1][0]>b[2][0]){
		cout<<"thang 7 co nh` ngay mua nhat";
	}
	else cout<<"thang 8 co nh` ngay mua nhat";
	return 0;
}
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

/*int main () {
	char filename[100];
	int arr[1000];
	cout<<"nhap ten file(bao gom phan mo rong (.txt)): "<<endl;
	cin>>filename;
	ifstream a;
	a.open(filename);
	if (!a) {
    cout << "Unable to open file";
    exit(1);   // call system to stop
	}
	int n=0,t,sum=0;
	while(a>>t){
		arr[n]=t;n++;sum+=t;
	}
	a.close();
	sort(arr,arr+n);
	cout<<"so thap nhat la: "<<arr[0]<<endl;
	cout<<"so cao nhat la: "<<arr[n-1]<<endl;
	cout<<"tong cac so la: "<<sum<<endl;
	cout<<"gia tri trung binh la: "<<sum/n<<endl;
	return 0;
}*\