#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findNextSeniors(const vector<int> &ranks)
{
    int n = ranks.size();
    vector<int> nextSeniors(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && ranks[i] > ranks[st.top()])
        {
            nextSeniors[st.top()] = ranks[i];
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int i = st.top();
        st.pop();
        if (st.empty())
            break;
        int j = st.top();
        nextSeniors[j] = ranks[i];
    }

    return nextSeniors;
}

int main()
{
    while (true)
    {
        vector<int> ranks;
        int rank;
        while (cin >> rank)
        {
            if (rank == -1)
                break;
            ranks.push_back(rank);
        }

        if (ranks.empty())
            break;

        vector<int> nextSeniors = findNextSeniors(ranks);

        for (int i = 0; i < nextSeniors.size(); i++)
        {
            cout << nextSeniors[i];
            if (i < nextSeniors.size() - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
