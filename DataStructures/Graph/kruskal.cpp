#include <bits/stdc++.h>

using namespace std;

// Making of adjancy list
void add_to_list(vector<vector<pair<int,int>>> &adlist,int edges){
	int sorc,dest,w;
	for (int i=0;i<edges;i++){
		cin >> sorc >>dest >> w;
		adlist[--sorc].push_back({--dest,w});
		// adlist[dest].push_back({sorc,w});
	}
}

// Print the adjancy list
void Print(vector<vector<pair<int,int>>> &adlist, int nodes){
	for (int i=0;i<adlist.size();i++){
		if (adlist[i].size() > 0){
			auto it = adlist[i].begin();
			cout << " " << i;
			// cout << "[";
			while (it != adlist[i].end()){
				cout << " -> " << (*it).first << " " << "(w:" << (*it).second << ")";
				++it;
			}
			// cout << "]\n";
		}else {
			cout << "[]\n";
		} cout << "\n";
	}
}

void make_set(vector<int>& parent,vector<int>& sz,int v){
	parent[v] = v;
	sz[v] = 1;
}

int find_sets(vector<int>& parent,vector<int>& sz,int v){
	if (v==parent[v]) return v;
	else parent[v] = find_sets(parent,sz,parent[v]);
}


void union_sets(vector<int>& parent,vector<int>& sz,int a,int b){
	a = find_sets(parent,sz,a);
	b = find_sets(parent,sz,b);
	if (a!=b){
		if (sz[a] < sz[b]) swap(a,b);
		parent[b] = a;
		sz[a] += sz[b];
	}
}

void KruskalAlgorithm(vector<vector<int>> E_V,int nodes){
	// cout << "FUCK IIT\n";
	vector<int> parent(nodes);
	vector<int> sz(nodes);
	int w,u,v,cost,x,y;

	// Initailize parent and size for each node
	for (int i=0;i<nodes;i++) make_set(parent,sz,i);

	// Sort edges via their edges
	sort(E_V.begin(),E_V.end());
	
	// Set cost to make MST equals zero
	cost = 0;
	for (auto i:E_V){
		w = i[0];	// weight
		u = i[1];	// source
		v = i[2];	// edges
		x = find_sets(parent,sz,u);
		y = find_sets(parent,sz,v);
		if (x==y) continue;
		else {
			cout << u << " " << v << "\n";
			cost += w;
			union_sets(parent,sz,u,v);
		}
	}cout << "Cost:- " << cost << "\n";
}

int main(){
    int nodes,edges,i,j;
	cout << "Enter no. of node:- \n";
	cin >> nodes;
	vector<vector<pair<int,int>>> adlist(nodes);

	cout << "Enter no. of edges:- \n";
	cin >> edges;

	cout << "\nEnter graph (edges) in form (source destination weight)\n";
	add_to_list(adlist,edges);

	// Print(adlist,nodes);

	// E_V :- <(w,u,v)> 
	vector<vector<int>> E_V;
	for (i=0;i<nodes;i++){
		for (j=0;j<adlist[i].size();j++){
			E_V.push_back({adlist[i][j].second,i,adlist[i][j].first});
		}
	}
	// cout << "FUCK IIT\n";
	KruskalAlgorithm(E_V,nodes);

    return 0;
}