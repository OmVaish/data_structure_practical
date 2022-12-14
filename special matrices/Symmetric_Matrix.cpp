#include <iostream>

using namespace std;

template<class T>
class Symmetric_Matrix{
	public:
		Symmetric_Matrix(int theN = 3);
		~Symmetric_Matrix(){
			delete[] element;
		}
		T get(int, int) const;
		void set(int, int, const T&);
		void input();
		void display();
	private:
		int n;
		T *element;
};

template<class T>
Symmetric_Matrix<T> :: Symmetric_Matrix(int theN){
	if(theN < 1){
		cout<<"Matrix size must be > 0.";
	}
	n = theN;
	element = new T[n];
}

template<class T>
T Symmetric_Matrix<T> :: get(int i, int j) const{
	if(i < 1 || j < 1 || i > n || j > n){
		cout<<"Matrix size out of bound.\n";
	}
	if(i<=j){
		return element[j*(j-1)/2+i-1];
	}
	else{
		return 0;
	}
}

template<class T>
void Symmetric_Matrix<T> :: set(int i, int j, const T& newValue){
	if(i < 1 || j < 1 || i > n || j > n){
		cout<<"Matrix size out of bound.\n";
	}
	if(i<=j){
		element[j*(j-1)/2+i-1] = newValue;
	}
	else{
		if(element[j][i]!=val){
			cout<<"Element at position "<<i<<","<<j<<"must be equal to element at "<<j<<","<<i;
		}
	}
}

template<class T>
void Symmetric_Matrix<T> :: input(){
	T val;
	cout<<"Enter the elements of the Symmetric_matrix: \n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>val;
			set(i,j,val);
		}
	}
}

template<class T>
void Symmetric_Matrix<T> :: display(){
	cout<<"\nElements of the Diagonal metric array are: \n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			T val = get(i,j);
			cout<<val<<"\t";
		}
		cout<<"\n";
	}
}

//int main(){
//	Symmetric_Matrix<int> obj;
//	obj.input();
//	obj.display();
//	return 0;
//}
