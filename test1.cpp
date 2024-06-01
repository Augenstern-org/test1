#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<unsigned int> prime_vec{ 2 };
string YesOrNo("y");

 bool judgePrime(unsigned int num, vector<unsigned int> vec)
{
    auto beg = vec.begin();
    auto end = vec.end();
    auto mid = vec.begin() + (end - beg) / 2;
    while (*mid != num && beg != end)
    {
        mid = beg + (end - beg) / 2;
        if (num < *mid)
            end = mid;
        else
            beg = mid + 1;
    }
    return (*mid == num ? true : false);
}

 void fill_prime_vec(unsigned int num, vector<unsigned int> &vec)
{
    if (num > *(vec.cend() - 1))
    {
        for (unsigned int i = *(vec.end() - 1); i <= num; ++i)
        {
            int p = 1;
            for (unsigned int j = 2; j != i; ++j)
            {
                if (i % j == 0)
                    p = 0;
            }
            if (p == 1 && i != *(vec.end() - 1))
                vec.push_back(i);
        }
    }
}

int main()
{
    unsigned int input = 0;
    while (YesOrNo == "y" || YesOrNo == "Y")
    {
        cout << "Please print a natrual number:" << endl;
        cin >> input;
        fill_prime_vec(input, ::prime_vec);
        //for (vector<unsigned int>::size_type i = 0; i != prime_vec.size(); ++i)
        //{
        //    cout << prime_vec[i] << endl;
        //}
        if (input >= 2)
        {
            if (judgePrime(input, ::prime_vec)) 
            {
                cout << "It is a prime number." << endl;
                cout << "Try again? Y/N" << endl;
                cin >> YesOrNo;
            }
            else
            {
                for (auto pval : ::prime_vec)
                {
                    while (input % pval == 0)
                    {
                        input /= pval;
                        cout << pval << endl;
                    }
                }
            }
        }
        else
        {
            cout << "Undefined." << endl;
            cout << "Try again? Y/N" << endl;
            cin >> YesOrNo;
        }
    }
    return 0;
}