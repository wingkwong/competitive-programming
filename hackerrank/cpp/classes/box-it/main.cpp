#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);
class Box{
    public:
        Box(){
            l=b=h=0;
        };

        Box(int x, int y, int z){
            l=x;
            b=y;
            h=z;
        };
        // int getLength(); // Return box's length
        int getLength(){ 
            return l;
        }

        // int getBreadth (); // Return box's breadth
        int getBreadth(){
             return b;
        }

        // int getHeight ();  //Return box's height
        int getHeight(){
            return h;
        }
        
        // long long CalculateVolume(); // Return the volume of the box
        long long CalculateVolume(){
            return 1LL*l*b*h;
        }
        
    //Overload operator < as specified
    friend bool operator<(Box& A, Box& B){
        return (A.l<B.l || (A.b<B.b&&A.l==B.l) || (A.h<B.h&&A.b==B.b&&A.l==B.l));
    }

    //Overload operator << as specified
    friend ostream& operator<<(ostream& out, Box& B){
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }

    private:
        int l,b,h;
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}