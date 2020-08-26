#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;
        try{
            cout << Server::compute(A,B) << "\n";
        } catch(bad_alloc& err){
            cout << "Not enough memory\n";
        } catch(exception& err){
            cout << "Exception: " << err.what() << "\n";
        } catch(...){
            cout << "Other Exception\n";
        }
	}
	cout << Server::getLoad() << endl;
	return 0;
}