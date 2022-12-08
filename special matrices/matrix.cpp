#include <iostream>
#include "Diagonal matrix.cpp"
#include "Tridiagonal matrix.cpp"
#include "LowerTriangular matrix.cpp"
#include "UpperTriangular matrix.cpp"


using namespace std;

int main(){
	cout<<"-------------MENU-------------\n";
	cout<<"  1) Tri-Diagonal matrix.     \n";
	cout<<"  2) Diagonal matrix.         \n";
	cout<<"  3) Lower Triangular matrix. \n";
	cout<<"  4) Upper Triangular matrix. \n";
        cout<<"  5) Upper Triangular matrix. \n";
	cout<<endl;
	int k;
	do{
		cout<<"Enter the choice : ";
		cin>>k;
		switch(k){
			case 1:{Tridiagonal_Matrix<int> obj;
				obj.input();
				obj.display();
				cout<<endl;
				break;
			}
			case 2:{diagonalMatrix<int> obj;
				obj.input();
				obj.display();
				cout<<endl;
				break;
			}
			case 3:{LowerTri_Matrix<int> obj;
				obj.input();
				obj.display();
				cout<<endl;
				break;
			}
			case 4:{UpperTri_Matrix<int> obj;
				obj.input();
				obj.display();
				cout<<endl;
				break;
			}
                        case 5:{Symmetric_Matrix<int> obj;
				obj.input();
				obj.display();
				cout<<endl;
				break;
			}
		}
	}while(k!=0);
	return 0;
}
