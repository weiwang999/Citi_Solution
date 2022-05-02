#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include  <queue>
#include <stack>
using namespace std;


struct Node
{
public:
    Node()
    {

    }
    Node(int num)
    {
        val = num;
    }
    int val;

    vector<Node > buf;


    bool isInteger() const
    {
        if (buf.empty())
        {
            return true;
        }
        return false;
    }

    int getInteger()
    {
        return val;
    }


    const vector<Node>& getList()
    {
        return buf;
    }



};


class Flatten {
public:
    Flatten(vector<Node>& nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--)
        {
            st.push(nestedList[i]);
        }
    }

    int next() {
        auto res = st.top(); st.pop();
        return res.getInteger();
    }

    bool hasNext() {

        while (!st.empty())
        {
            auto node = st.top();
            if (node.isInteger())
                return true;


            st.pop();

            for (int i = node.getList().size() - 1; i >= 0; i--)
            {
                st.push(node.getList()[i]);
            }
        }
        return false;

    }

private:
    stack<Node> st;
};


string reversePage(string input)
{

    istringstream is(input);

    vector<string> buf;
    string tmp;
    while (getline(is, tmp, '\b'))
    {

        istringstream iss(tmp);
        vector<string> buf1;
        string tmpn;
        while (getline(iss, tmpn, '\n'))
        {
            istringstream isss(tmpn);

            vector<string> buf2;

            string tmps;

            while (isss >> tmps)
            {
                buf2.push_back(tmps);
            }
            reverse(buf2.begin(), buf2.end());

            string ntmp;

            for (auto str : buf2)
            {
                ntmp += str + " ";
            }
            ntmp.pop_back();
            ntmp += '\n';
            buf1.push_back(ntmp);
        }

        reverse(buf1.begin(), buf1.end());
        string btmp;
        for (auto str : buf1)
        {
            btmp += str;
        }
        btmp += '\b';

        buf.push_back(btmp);
    }
    reverse(buf.begin(), buf.end());

    string output1;
    for (auto str : buf)
    {
        output1 += str;
    }

    return output1;
}




int main()
{
    //Solution p;

   // solution p;

   // input = [[4, 5], [[1, 2, 3]], 6, 7]

    Node l31(6);
    Node l32(7);

    Node l21(4);
    Node l22(5);

    Node l23;
    l23.buf.push_back(l21);
    l23.buf.push_back(l22);


    Node l41(1);
    Node l42(2);
    Node l43(3);
    Node l33;
    l33.buf.push_back(l41);
    l33.buf.push_back(l42);
    l33.buf.push_back(l43);

    vector<Node> l1;
    l1.push_back(l23);
    l1.push_back(l33);
    l1.push_back(l31);
    l1.push_back(l32);

    Flatten s(l1);
    vector<int> ans;
    while (s.hasNext())
    {
        ans.push_back(s.next());
    }

    for (auto num : ans)
    {
        cout << num << endl;
    }



    string inputstr = "the brown fox jumped over the fence\nthe brown bear fell down the hill\n\bThe big lion chased the deer\nThe monkey ate the bananas\n\b";

    string output1 = reversePage(inputstr);

    cout << output1 << endl;

}