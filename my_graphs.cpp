#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct Graph {
	unordered_map<int, vector<int>> graphedges;
    /*
    Constructs a Graph with the given set of graphedges, where startingingpoint and theendingpoint represent the ordered list of
    edges’ starting and theendpoints. throws an error if size of strart and theend don't match*/
	Graph(const vector<int> startingingpoint, const vector<int>& theendingpoint) {
		if (startingingpoint.size() != theendingpoint.size()) {
			throw invalid_argument("Sizes of starting and theend don't match!");
		}
		else {
			for (int i = 0; i < startingingpoint.size(); i++) {
				int k = startingingpoint.at(i);
				if (graphedges.count(k)) {
					graphedges[k].push_back(theendingpoint.at(i));
				}
				else {
					graphedges.insert(pair<int, vector<int>>(k, { theendingpoint.at(i) }));
				}
			}
		}
	}

   /*
   Returns the number of outgoing graphedges from IDofnodes
 – that is, graphedges with IDofnodes
 as the starting point.
 */
int numOutgoing(const int IDofnodes) {
		if (graphedges.count(IDofnodes)) {
			return(graphedges[IDofnodes].size());
		}
		else {
			cout << "This node doesn't exist";
			return -1;
		}
	}
    /*
    accepts as parameter an int representing the IDofnodes
 and
    returns a reference to the list of nodes to which IDofnodes
 has outgoing graphedges*/
	const vector<int>& adjecnt(const int IDofnodes) {
		if (graphedges.count(IDofnodes)) {
			return graphedges[IDofnodes];
		}
		else {
			cout << "This node doesn't exist";
		}
	}
    public:
/*
    accepts as parameter an int representing the IDofnodes
 and
    returns a reference to the list of nodes to which IDofnodes
 has outgoing graphedges*/
    const vector<int> &adjacent(const int IDofnodes)
    {
        if (graphedges.find(IDofnodes) == graphedges.end())
        throw invalid_argument("There exists no such node");
        return graphedges[IDofnodes];
    }

public:
    bool isCyclic(){

        if (graphedges.size() == 0)
        {
            cout << "There are no cycles in this graph" << endl;
            return false;
        }

        unordered_map<int, bool> isvisited;
        int num = 0;
        for (auto i : graphedges) {
            isvisited[i.first] = false;
            num= i.first;
        }

        for (auto i : graphedges) 
            isCyclicHelper(graphedges, i.first, isvisited);

        bool isfound = cycle;
        if (isfound) {
            cout << "starting at node'" << starting << endl;
        } else {
            cout << "no cycle" << endl;
        }


        cycle = false;
        return isfound;
    }

    bool cycle = false;
    int starting = -1;

private:
    void isCyclicHelper(unordered_map<int, vector<int> > adjacencyList, int n, unordered_map<int, bool> isvisited){
        isvisited[n] = true;
        for (int i = 0; i < adjacencyList[n].size(); i++) {
            vector<int> curr = adjacencyList[n];
            if (!isvisited[curr[i]]) {
                isvisited[curr[i]] = true;
                isCyclicHelper(adjacencyList, curr[i], isvisited);
            } else if (curr[i] != n){
                cycle = true;
                starting = n;
            }
        }
    }

};


int main(){
	vector<int> starting;
	starting.push_back(1);
	starting.push_back(9);
	starting.push_back(15);
	starting.push_back(2);
	starting.push_back(4);
	starting.push_back(2);
	vector<int> theend;
	theend.push_back(3);
	theend.push_back(2);
	theend.push_back(6);
	theend.push_back(1);
	theend.push_back(3);
	theend.push_back(7);
	Graph g(starting, theend);
    cout << g.numOutgoing(1) << endl;
    cout << g.numOutgoing(3) << endl;
    vector<int> c = g.adjacent(4);
    g.isCyclic();
	return 0;
}