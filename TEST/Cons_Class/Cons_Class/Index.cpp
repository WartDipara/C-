#include <iostream>
#include <string>
using namespace std;

//成员模板-----成员模板不能是虚函数
class OutArray {
private:
    ostream& os;
public:
    OutArray(ostream& o = cout) :os(o) {}
    template <typename T> void operator()(T* a, int n) {
        for (int i = 0; i < n; i++)
        {
            os << a[i] << "\t";
            os << endl;
        }
    }
};

int main()
{
    cout << 5 % 2 << endl;
    return 0;
}