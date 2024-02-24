// Nguyen Dinh Ut Biu 20215317
// Bai4.11: Bao ve lau dai

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// struct represent data at i_th wall
// enemies and soldierPower is what come with the problem
// efficiency is defined as min of enemies and soldierPower
// 		the wall is considered better if it has higher efficiency
// if 2 walls has the same efficiency we use range to compare them
// range is defined as soldier power - enemies
struct Node{
	int enemies;
	int soldierPower;
	int efficiency;
	int range;
	Node(int a, int k): enemies(a), soldierPower(k), efficiency(min(a, k)), range(k - a) {}
};

int n, s; // number of walls and number of soldiers
vector<Node> wallData; // information at i_th wall
vector<int> offset; // number of enemies could leak 
					// if we decrease an soldier 
					// from overprotected wall
vector<int> leakEnemies;


// sort wallData according to efficiency and range
void sortWallData(){
	auto sortByEfficiency = [&](Node a, Node b){
		if (a.efficiency > b.efficiency) return true;
		else if (a.efficiency == b.efficiency && a.range > b.range) return true;
		return false;
	};
	sort(wallData.begin(), wallData.end(), sortByEfficiency);
}

// prepare input and sort input
void prepare(){
	cin >> n >> s;
	offset.resize(n, 0);
	for(int i = 0; i < n; i++){
		int a, k;
		cin >> a >> k;
		wallData.push_back(Node(a, k));
	}
	sortWallData();
	// set leak enemies of each wall to that wall enemies at first
	for(int i = 0; i < n; i++){
		leakEnemies.push_back(wallData[i].enemies);
	}
}

// try to dispatch 1 soldier from higher defensed wall
bool tryDispatch(int j){
	for(int i = 0; i < j; i++){
		if(offset[i] == -1) continue; // -1 mean this wall has dispatched a soldier before
		if(offset[i] == 0) break; // 0 mean this wall hasn't had any soldier dispatched
		// if this wall has more meaningful use for 1 soldier, dispatch it
		if(min(wallData[j].soldierPower, wallData[j].enemies) > min(offset[i], wallData[i].soldierPower)){
			leakEnemies[i] = offset[i];
			offset[i] = -1;
			return true;
		}
	}
	return false;
}

// return solution
int leastLeakEnemies(){
	int i = 0;
	while(i < n){
		int enemies = wallData[i].enemies;
		int soldierPower = wallData[i].soldierPower;
		// calculate soldier even if it overflow the enemies
		if(s > 0){
			int soldierNumber = enemies / soldierPower + 1;
			if(s - soldierNumber >= 0){
				s -= soldierNumber;
				leakEnemies[i] = enemies - soldierNumber*soldierPower;
				if(leakEnemies[i] + soldierPower == 0){
					leakEnemies[i] = 0;
					offset[i] = -1;
					s++;
				}
				else{
					offset[i] = soldierPower + leakEnemies[i];
					leakEnemies[i] = 0;
				}
				i++;
			}
			else{
				leakEnemies[i] -= s*soldierPower;
				offset[i] = leakEnemies[i] + soldierPower;
				if(leakEnemies[i] == 0){
					offset[i] = -1;
					i++;
				}
				s = 0;
			}
		}
		else{
			if(tryDispatch(i)){
				if(soldierPower > leakEnemies[i]){
					offset[i] = leakEnemies[i];
					leakEnemies[i] = 0;
					i++;
				}
				else{
					leakEnemies[i] -= soldierPower;
					if(leakEnemies[i] == 0){
						offset[i] = -1;
						i++;
					}
				}
			}
			else{
				i++;
			}
		}
	}
	int totalLeak = 0;
	for(auto x:leakEnemies) totalLeak += x;
	return totalLeak;
}

int main(){
	prepare();
	cout << "Least Leak = " << leastLeakEnemies();
	//cout << endl;
	//for(auto x:wallData) cout << x.soldierPower << " ";
	//cout << endl;
	//for(auto x:wallData) cout << x.enemies << " ";
	//cout << endl;
	//for(auto x:leakEnemies) cout << x << " ";
	//cout << endl;
	//for(auto x:offset) cout << x << " ";
}
