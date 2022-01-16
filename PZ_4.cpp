#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

int main() 
{

	//map

    map <string, int> mp;
    string line;
    string word;

    cout << "Enter string: " << endl;

    getline(cin, line);
    stringstream ss(line);

    while (getline(ss, word, ' ')) 
	{
        if (mp.find(word) == mp.end())
        {
            mp.emplace(word, 1);
        }
        else
        {
            mp[word]++;
        }
    }


    map <string, int> ::iterator it = mp.begin();

    for (int i = 0; it != mp.end(); it++, i++)
    {
        cout << i << "  " << it->first << ": " << it->second << endl;
    }

	//vector

	ostream& operator << (ostream & out, const vector<int>&v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			out << v[i] << " ";
		}
		return out;
	}

	double aver(vector<int> v) {
		double buf = 0;

		for (int i = 0; i < v.size(); i++)
			buf += (double)v[i];

		return buf / v.size();
	}

	vector<int> cross(vector<int> v1, vector<int> v2) {
		vector<int>buf;
		for (int i = 0; i < v1.size(); i++)
		{
			for (int j = 0; j < v2.size(); j++)
			{
				if (v1[i] == v2[j])
					buf.push_back(v2[j]);
			}
		}
		return buf;
	}

	int main()
	{
		int v1_size = 0;
		int v2_size = 0;

		cout << "Enter a vector size:";
		cin >> v1_size >> v2_size;

		random_device rd;
		mt19937 generator(rd());
		uniform_int_distribution<> distribution(-100, 100);

		vector<int> v1;
		vector<int> v2;

		for (int i = 0; i < v1_size; i++)
			v1.push_back(distribution(generator));

		for (int i = 0; i < v2_size; i++)
			v2.push_back(distribution(generator));

		cout << v1 << endl << v2 << endl << aver(v1) << endl << aver(v2) << endl << cross(v1, v2);

        //stack

        class Graph
        {
        public:
            Graph()
            {
                cout << "Enter a num of vertex: ";
                cin >> numVer;
                cin.ignore(256, '\n');
                links.assign(numVer, vector<int>(numVer));
            }

            void full()
            {
                string line;
                string n;
                for (int i = 0; i < numVer; i++)
                {
                    cout << "Enter links for " << i + 1 << ": ";

                    getline(cin, line);
                    stringstream ss(line);
                    while (getline(ss, n, ' '))
                    {
                        this->links[i][stoi(n) - 1] = 1;
                    }
                }
                cout << endl;
            }

            void DFS(int ver)
            {
                for (int j = 0; j < numVer; j++)
                {
                    if (lastVer.empty())
                    {
                        if (links[ver][j] == 1)
                        {
                            stk.push(j);
                            lastVer.push(ver);
                            DFS(j);
                            lastVer.pop();
                        }
                    }
                    else
                    {
                        if (links[ver][j] == 1 && j != lastVer.top())
                        {
                            stk.push(j);
                            lastVer.push(ver);
                            DFS(j);
                            lastVer.pop();
                        }
                    }
                }
            }

            void DFSTable()
            {
                for (int i = 0; i < numVer; i++)
                {
                    DFS(i);
                    while (stk.size())
                    {
                        links[i][stk.top()] = 1;
                        stk.pop();
                    }
                }
            }

            void show()
            {
                for (int i = 0; i < numVer; i++)
                {
                    links[i][i] = 1;
                    for (int j = 0; j < numVer; j++)
                    {
                        cout << links[i][j] << " ";
                    }
                    cout << endl;
                }
            }

        private:
            int numVer;
            stack <int> lastVer;
            stack <int> stk;
            vector<vector<int> > links;
        };

        int main()
        {
            Graph graph;
            graph.full();
            graph.DFSTable();
            graph.show();

		return 0;
	}

    return 0;
