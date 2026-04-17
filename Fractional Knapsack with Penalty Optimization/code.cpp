#include<bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cout << "Enter the number of Elements: " << endl;
    cin >> m;
    vector<vector<int>>mat;
    mat.resize(m , vector<int>(3 , 0));

    cout << "Enter the Elements in order: Weight , Value , Penalty (in a line). " << endl;
    for(int i = 0 ; i < m ; i++){
        int w , v , p;
        cin >> w >> v >> p;
        mat[i][0] = w;
        mat[i][1] = v;
        mat[i][2] = p;
    }

    int maxW;
    cout << "Enter the weight of Knapsack: " << endl;
    cin >> maxW;


    sort(mat.begin() , mat.end() , [&](auto& a , auto& b){
        return (double)(a[1] - a[2]) / a[0] > (double)(b[1] - b[2]) / b[0];
    });

    double maxV = 0;

    for(auto& it : mat){
        int weight = it[0];
        int value = it[1];
        int penalty = it[2];

        int net = value - penalty;

        if(net <= 0) continue;

        if(weight <= maxW){
            maxW -= weight;
            maxV += net;
        }
        else{
            maxV += net * ((double)maxW / weight);
            break;
        }
    }

    cout << "The maximum Value that can be obtained while minimising the penalty is : " << maxV << endl;

    return 0;
}
