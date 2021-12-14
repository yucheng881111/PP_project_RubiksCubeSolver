#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

string Move(string state, int opt);

void CW(vector<int> &v1, vector<int> &v2, vector<int> &v3){
    int t1 = v1[0];
    int t2 = v1[1];
    int t3 = v1[2];
    int t4 = v2[0];
    int t5 = v2[1];
    int t6 = v2[2];
    int t7 = v3[0];
    int t8 = v3[1];
    int t9 = v3[2];

    v1[0] = t7; v1[1] = t4, v1[2] = t1;
    v2[0] = t8; v2[1] = t5, v2[2] = t2;
    v3[0] = t9; v3[1] = t6, v3[2] = t3;
}

// FrontCW
void rotate1(vector<vector<int>> &v){
    CW(v[6], v[7], v[8]);

    int temp1[3];
    temp1[0] = v[2][0];
    temp1[1] = v[2][1];
    temp1[2] = v[2][2];

    int temp2[3];
    temp2[0] = v[9][0];
    temp2[1] = v[10][0];
    temp2[2] = v[11][0];

    int temp3[3];
    temp3[0] = v[15][0];
    temp3[1] = v[15][1];
    temp3[2] = v[15][2];

    int temp4[3];
    temp4[0] = v[3][2];
    temp4[1] = v[4][2];
    temp4[2] = v[5][2];

    v[2][0] = temp4[2];
    v[2][1] = temp4[1];
    v[2][2] = temp4[0];

    v[9][0] = temp1[0];
    v[10][0] = temp1[1];
    v[11][0] = temp1[2];

    v[15][0] = temp2[2];
    v[15][1] = temp2[1];
    v[15][2] = temp2[0];

    v[3][2] = temp3[0];
    v[4][2] = temp3[1];
    v[5][2] = temp3[2];

}
// FrontACW
void rotate2(vector<vector<int>> &v){
    rotate1(v);
    rotate1(v);
    rotate1(v);
}
// UpCW
void rotate3(vector<vector<int>> &v){
    CW(v[0], v[1], v[2]);

    int temp1[3];
    temp1[0] = v[12][0];
    temp1[1] = v[12][1];
    temp1[2] = v[12][2];

    int temp2[3];
    temp2[0] = v[9][0];
    temp2[1] = v[9][1];
    temp2[2] = v[9][2];

    int temp3[3];
    temp3[0] = v[6][0];
    temp3[1] = v[6][1];
    temp3[2] = v[6][2];

    int temp4[3];
    temp4[0] = v[3][0];
    temp4[1] = v[3][1];
    temp4[2] = v[3][2];

    v[12][0] = temp4[0];
    v[12][1] = temp4[1];
    v[12][2] = temp4[2];

    v[9][0] = temp1[0];
    v[9][1] = temp1[1];
    v[9][2] = temp1[2];

    v[6][0] = temp2[0];
    v[6][1] = temp2[1];
    v[6][2] = temp2[2];

    v[3][0] = temp3[0];
    v[3][1] = temp3[1];
    v[3][2] = temp3[2];

}
// UpACW
void rotate4(vector<vector<int>> &v){
    rotate3(v);
    rotate3(v);
    rotate3(v);
}
// DownCW
void rotate5(vector<vector<int>> &v){
    CW(v[15], v[16], v[17]);

    int temp1[3];
    temp1[0] = v[8][0];
    temp1[1] = v[8][1];
    temp1[2] = v[8][2];

    int temp2[3];
    temp2[0] = v[11][0];
    temp2[1] = v[11][1];
    temp2[2] = v[11][2];

    int temp3[3];
    temp3[0] = v[14][0];
    temp3[1] = v[14][1];
    temp3[2] = v[14][2];

    int temp4[3];
    temp4[0] = v[5][0];
    temp4[1] = v[5][1];
    temp4[2] = v[5][2];

    v[8][0] = temp4[0];
    v[8][1] = temp4[1];
    v[8][2] = temp4[2];

    v[11][0] = temp1[0];
    v[11][1] = temp1[1];
    v[11][2] = temp1[2];

    v[14][0] = temp2[0];
    v[14][1] = temp2[1];
    v[14][2] = temp2[2];

    v[5][0] = temp3[0];
    v[5][1] = temp3[1];
    v[5][2] = temp3[2];

}
// DownACW
void rotate6(vector<vector<int>> &v){
    rotate5(v);
    rotate5(v);
    rotate5(v);
}
// LeftCW
void rotate7(vector<vector<int>> &v){
    CW(v[3], v[4], v[5]);

    int temp1[3];
    temp1[0] = v[0][0];
    temp1[1] = v[1][0];
    temp1[2] = v[2][0];

    int temp2[3];
    temp2[0] = v[6][0];
    temp2[1] = v[7][0];
    temp2[2] = v[8][0];

    int temp3[3];
    temp3[0] = v[15][0];
    temp3[1] = v[16][0];
    temp3[2] = v[17][0];

    int temp4[3];
    temp4[0] = v[12][2];
    temp4[1] = v[13][2];
    temp4[2] = v[14][2];

    v[0][0] = temp4[2];
    v[1][0] = temp4[1];
    v[2][0] = temp4[0];

    v[6][0] = temp1[0];
    v[7][0] = temp1[1];
    v[8][0] = temp1[2];

    v[15][0] = temp2[0];
    v[16][0] = temp2[1];
    v[17][0] = temp2[2];

    v[12][2] = temp3[2];
    v[13][2] = temp3[1];
    v[14][2] = temp3[0];

}
// LeftACW
void rotate8(vector<vector<int>> &v){
    rotate7(v);
    rotate7(v);
    rotate7(v);
}
// RightCW
void rotate9(vector<vector<int>> &v){
    CW(v[9], v[10], v[11]);

    int temp1[3];
    temp1[0] = v[0][2];
    temp1[1] = v[1][2];
    temp1[2] = v[2][2];

    int temp2[3];
    temp2[0] = v[12][0];
    temp2[1] = v[13][0];
    temp2[2] = v[14][0];

    int temp3[3];
    temp3[0] = v[15][2];
    temp3[1] = v[16][2];
    temp3[2] = v[17][2];

    int temp4[3];
    temp4[0] = v[6][2];
    temp4[1] = v[7][2];
    temp4[2] = v[8][2];

    v[0][2] = temp4[0];
    v[1][2] = temp4[1];
    v[2][2] = temp4[2];

    v[12][0] = temp1[2];
    v[13][0] = temp1[1];
    v[14][0] = temp1[0];

    v[15][2] = temp2[2];
    v[16][2] = temp2[1];
    v[17][2] = temp2[0];

    v[6][2] = temp3[0];
    v[7][2] = temp3[1];
    v[8][2] = temp3[2];

}
// RightACW
void rotate10(vector<vector<int>> &v){
    rotate9(v);
    rotate9(v);
    rotate9(v);
}
// BackCW
void rotate11(vector<vector<int>> &v){
    CW(v[12], v[13], v[14]);

    int temp1[3];
    temp1[0] = v[0][0];
    temp1[1] = v[0][1];
    temp1[2] = v[0][2];

    int temp2[3];
    temp2[0] = v[3][0];
    temp2[1] = v[4][0];
    temp2[2] = v[5][0];

    int temp3[3];
    temp3[0] = v[17][0];
    temp3[1] = v[17][1];
    temp3[2] = v[17][2];

    int temp4[3];
    temp4[0] = v[9][2];
    temp4[1] = v[10][2];
    temp4[2] = v[11][2];

    v[0][0] = temp4[0];
    v[0][1] = temp4[1];
    v[0][2] = temp4[2];

    v[3][0] = temp1[2];
    v[4][0] = temp1[1];
    v[5][0] = temp1[0];

    v[17][0] = temp2[0];
    v[17][1] = temp2[1];
    v[17][2] = temp2[2];

    v[9][2] = temp3[2];
    v[10][2] = temp3[1];
    v[11][2] = temp3[0];

}
// BackACW
void rotate12(vector<vector<int>> &v){
    rotate11(v);
    rotate11(v);
    rotate11(v);
}

//string final_state = "111111111222222222333333333444444444555555555666666666";

string to_state(vector<vector<int>> &v){
    string s = "";
    for(int i=0;i<18;++i){
        for(int j=0;j<3;++j){
            s += to_string(v[i][j]);
        }
    }
    return s;
}

vector<vector<int>> to_node(string &s){
    int tmp[3];
    vector<vector<int>> v;
    for(int i=0;i<54;++i){
        if(i % 3 == 0){
            tmp[0] = s[i] - '0';
        }else if(i % 3 == 1){
            tmp[1] = s[i] - '0';
        }else{
            tmp[2] = s[i] - '0';
            vector<int> temp(tmp,tmp+3);
            v.push_back(temp);
        }
    }

    return v;
}

bool goal(string s){
    for(int i=0;i<54;i+=9){
        char tmp = s[i];
        for(int j=0;j<9;j++){
            if(s[i+j] != tmp){
                return 0;
            }
        }
    }
    return 1;
}

unordered_map<string,int> used_state;
string final_state = "";

int manhattan_distance(string &state, int i, int z, bool corner){
	string arr = "002102202001101201000100200002012022001011021000010020000100200010110210020120220200201202210211212220221222202102002212112012222122022020120220021121221022122222";
	int c1_0 = arr[9*i + 3*z] - '0';
 	int c1_1 = arr[9*i + 3*z + 1] - '0';
 	int c1_2 = arr[9*i + 3*z + 2] - '0';

    int center = -1;
    int d1, d2, d3 ,d4, minimum;
    int c2_0, c2_1, c2_2;
    vector<vector<int>> cube = to_node(state);
    for(int c=1; c<=16; c+=3){
    	if( cube[i][z] == cube[c][1] ){
    		center = c;
    		break;
    	}
    }

    if(corner){
        //c2 = array[center - 1, 0]
        c2_0 = arr[9*(center-1) + 3*0] - '0';
 		c2_1 = arr[9*(center-1) + 3*0 + 1] - '0';
 		c2_2 = arr[9*(center-1) + 3*0 + 2] - '0';
        d1 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        minimum = d1;
        //c2 = array[center - 1, 2]
        c2_0 = arr[9*(center-1) + 3*2] - '0';
 		c2_1 = arr[9*(center-1) + 3*2 + 1] - '0';
 		c2_2 = arr[9*(center-1) + 3*2 + 2] - '0';
        d2 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d2<minimum){ minimum = d2; }
        //c2 = array[center + 1, 0]
        c2_0 = arr[9*(center+1) + 3*0] - '0';
 		c2_1 = arr[9*(center+1) + 3*0 + 1] - '0';
 		c2_2 = arr[9*(center+1) + 3*0 + 2] - '0';
        d3 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d3<minimum){ minimum = d3; }
        //c2 = array[center + 1, 2]
        c2_0 = arr[9*(center+1) + 3*2] - '0';
 		c2_1 = arr[9*(center+1) + 3*2 + 1] - '0';
 		c2_2 = arr[9*(center+1) + 3*2 + 2] - '0';
        d4 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d4<minimum){ minimum = d4; }
    }else{
        //c2 = array[center - 1, 1]
        c2_0 = arr[9*(center-1) + 3*1] - '0';
 		c2_1 = arr[9*(center-1) + 3*1 + 1] - '0';
 		c2_2 = arr[9*(center-1) + 3*1 + 2] - '0';
        d1 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        minimum = d1;
        //c2 = array[center, 0]
        c2_0 = arr[9*center + 3*0] - '0';
 		c2_1 = arr[9*center + 3*0 + 1] - '0';
 		c2_2 = arr[9*center + 3*0 + 2] - '0';
        d2 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d2<minimum){ minimum = d2; }
        //c2 = array[center, 2]
        c2_0 = arr[9*center + 3*2] - '0';
 		c2_1 = arr[9*center + 3*2 + 1] - '0';
 		c2_2 = arr[9*center + 3*2 + 2] - '0';
        d3 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d3<minimum){ minimum = d3; }
        //c2 = array[center + 1, 1]
        c2_0 = arr[9*(center+1) + 3*1] - '0';
 		c2_1 = arr[9*(center+1) + 3*1 + 1] - '0';
 		c2_2 = arr[9*(center+1) + 3*1 + 2] - '0';
        d4 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d4<minimum){ minimum = d4; }
    }

    return minimum;
}

int corner_edge_sum_max(string &state){
	int corners = 0;
	int edges = 0;
	for(int i=0; i<18; i++){
		if(i % 3 == 0 || i % 3 == 2){
			corners = corners + manhattan_distance(state, i, 0, true) + manhattan_distance(state, i, 2, true);
            edges = edges + manhattan_distance(state, i, 1, false);
		}else{
			edges = edges + manhattan_distance(state, i, 0, false) + manhattan_distance(state, i, 2, false);
		}
	}

	int sum_max;
	if( (corners/12) >= (edges/8) ){
		sum_max = (corners/12);
	}else{
		sum_max = (edges/8);
	}
	return sum_max;
}


int IDA(vector<vector<int>> &v){
    used_state.clear();
	vector<vector<int>> start_node = v;
    string start_state = to_state(start_node);
    queue<string> q;
    queue<int> q_cnt;
    queue<int> q_g;

 	int minimum = -1;
 	int cost_limit = corner_edge_sum_max(start_state);
 	//cout << cost_limit << endl;
    q.push(start_state);
    used_state[start_state] = -1;
    q_cnt.push(1);
    q_g.push(0);

    while(1){
    	minimum=-1;
    	q.push(start_state);
    	used_state[start_state] = -1;
    	q_cnt.push(1);
    	q_g.push(0);

	    while(!q.empty()){
	        string curr_state = q.front();
	        string next_state = "";
	        int cnt = q_cnt.front();
	        int curr_g = q_g.front();
	        q.pop();
	        q_cnt.pop();
	        q_g.pop();

	        for(int i=1;i<=12;++i){
	            next_state = Move(curr_state, i);

	            if(goal(next_state)){
	                used_state[next_state] = i;
	                final_state = next_state;
	                return cnt;
	            }else{

	            	int new_g = curr_g + 1;
	            	int new_h = corner_edge_sum_max(next_state);

	            	if( new_g + new_h > cost_limit){
	            		if (minimum == -1 || (new_g + new_h < minimum) ){
	            			minimum = new_g + new_h;
	            		}
	            		continue;
	            	}

	            	if(used_state.count(next_state) == 1){
	            		continue;
	            	}

	                used_state[next_state] = i;
	                q.push(next_state);
	                q_cnt.push(cnt + 1);
	                q_g.push(new_g);
	            }
	        }

	    }

	    used_state.clear();
	    cost_limit = minimum;
	}

    return 0;


}

int BFS(vector<vector<int>> &v){
    vector<vector<int>> start_node = v;
    string start_state = to_state(start_node);
    queue<string> q;
    queue<int> q_cnt;

    q.push(start_state);
    used_state.clear();
    used_state[start_state] = -1;
    q_cnt.push(1);

    while(!q.empty()){
        string curr_state = q.front();
        string next_state = "";
        int cnt = q_cnt.front();
        q.pop();
        q_cnt.pop();

        for(int i=1;i<=12;++i){
            next_state = Move(curr_state, i);

            if(goal(next_state)){
                used_state[next_state] = i;
                final_state = next_state;
                return cnt;
            }else if(used_state.count(next_state) != 1){
                used_state[next_state] = i;
                q.push(next_state);
                q_cnt.push(cnt + 1);
            }
        }
    }

    return 0;
}

class node{
public:
    string state;
    int f, g, h;
    node(string s, int g_in){
        state = s;
        g = g_in;
        h = corner_edge_sum_max(state);
        f = g + h;
    }
};

struct cmp{
    bool operator()(node &a, node &b){
        return a.f > b.f;
    }
};

int A_star(vector<vector<int>> &v){
    vector<vector<int>> start_node = v;
    string start_state = to_state(start_node);
    priority_queue<node, vector<node>, cmp> pq;

    node node_start(start_state, 0);
    pq.push(node_start);
    used_state.clear();
    used_state[start_state] = -1;
    

    while(!pq.empty()){
        string curr_state = pq.top().state;
        int curr_g = pq.top().g;
        string next_state = "";
        pq.pop();
        int next_g = curr_g + 1;

        for(int i=1;i<=12;++i){
            next_state = Move(curr_state, i);

            if(goal(next_state)){
                used_state[next_state] = i;
                final_state = next_state;
                return next_g;
            }else if(used_state.count(next_state) != 1){
                used_state[next_state] = i;
                node next_node(next_state, next_g);
                pq.push(next_node);
            }
        }
    }
    return 0;

}


string Move(string state, int opt){
    vector<vector<int>> vec = to_node(state);
    if(opt == 1){
        rotate1(vec);
    }else if(opt == 2){
        rotate2(vec);
    }else if(opt == 3){
        rotate3(vec);
    }else if(opt == 4){
        rotate4(vec);
    }else if(opt == 5){
        rotate5(vec);
    }else if(opt == 6){
        rotate6(vec);
    }else if(opt == 7){
        rotate7(vec);
    }else if(opt == 8){
        rotate8(vec);
    }else if(opt == 9){
        rotate9(vec);
    }else if(opt == 10){
        rotate10(vec);
    }else if(opt == 11){
        rotate11(vec);
    }else if(opt == 12){
        rotate12(vec);
    }

    return to_state(vec);
}

int main(){
    string s;
    vector<vector<int>> vec_input;
    vector<vector<int>> vec1;
    vector<vector<int>> vec2;
    vector<vector<int>> vec3;
    vector<vector<int>> vec4;
    for(int i=0;i<9;++i){
        cin >> s;
        if(i>=0 && i<3){
            int tmp[3];
            tmp[0] = s[3] - '0';
            tmp[1] = s[4] - '0';
            tmp[2] = s[5] - '0';
            vec_input.push_back(vector<int>(tmp,tmp+3));
        }else if(i>=3 && i<6){
            int tmp1[3]; tmp1[0] = s[0] - '0'; tmp1[1] = s[1] - '0'; tmp1[2] = s[2] - '0';
            int tmp2[3]; tmp2[0] = s[3] - '0'; tmp2[1] = s[4] - '0'; tmp2[2] = s[5] - '0';
            int tmp3[3]; tmp3[0] = s[6] - '0'; tmp3[1] = s[7] - '0'; tmp3[2] = s[8] - '0';
            int tmp4[3]; tmp4[0] = s[9] - '0'; tmp4[1] = s[10] - '0'; tmp4[2] = s[11] - '0';
            vec1.push_back(vector<int>(tmp1,tmp1+3));
            vec2.push_back(vector<int>(tmp2,tmp2+3));
            vec3.push_back(vector<int>(tmp3,tmp3+3));
            vec4.push_back(vector<int>(tmp4,tmp4+3));
        }else{
            if(i == 6){
                for(const auto &v: vec1){
                    vec_input.push_back(v);
                }
                for(const auto &v: vec2){
                    vec_input.push_back(v);
                }
                for(const auto &v: vec3){
                    vec_input.push_back(v);
                }
                for(const auto &v: vec4){
                    vec_input.push_back(v);
                }
            }
            int tmp[3];
            tmp[0] = s[3] - '0';
            tmp[1] = s[4] - '0';
            tmp[2] = s[5] - '0';
            vec_input.push_back(vector<int>(tmp,tmp+3));
        }
    }

    
    rotate1(vec_input);
    rotate12(vec_input);
    rotate3(vec_input);
    //rotate9(vec_input);
    //rotate7(vec_input);
    //rotate2(vec_input);
    //rotate4(vec_input);

    for(int i=0;i<18;++i){
        for(int j=0;j<3;++j){
            cout << vec_input[i][j] << " ";
        }
        cout << endl;
    }

    /*
    {
        double s = clock();
        int steps = BFS(vec_input);
        double e = clock();
        cout << "\nsteps: " << steps << endl;
        cout << "time: " << e - s << " ms" << endl;
    }
    cout << endl;
    */
    {
        double s = clock();
        int steps = A_star(vec_input);
        double e = clock();
        cout << "\nsteps: " << steps << endl;
        cout << "time: " << e - s << " ms" << endl;
    }
    cout << endl;
    
    {
        double s = clock();
        int steps = IDA(vec_input);
        double e = clock();
        cout << "\nsteps: " << steps << endl;
        cout << "time: " << e - s << " ms" << endl;
    }
    

    /*
    int opt;
    string state = final_state;
    fstream file;
    file.open("cube_states.txt", ios::out);

    while(1){
        cout << state << endl;
        file << state << endl;
        opt = used_state[state];
        if(opt == -1){
            break;
        }
        if(opt % 2){
            opt++;
        }else{
            opt--;
        }
        cout << opt << endl;
        file << opt << endl;

        state = Move(state, opt);
    }*/


    //cout << "\nsteps: " << steps << endl;


    //file.close();
	return 0;
}

/*
3

000315000000
000315000000
000315000000
222631444651
222631444651
222631444651
000563000000
000563000000
000563000000

000511000000
000511000000
000511000000
222133444556
222133444556
222133444556
000366000000
000366000000
000366000000

000515000000
000515000000
000322000000
224111544636
224133644656
113233644654
000122000000
000563000000
000563000000

2
1
5

initial:

000111000000
000111000000
000111000000
222333444555
222333444555
222333444555
000666000000
000666000000
000666000000
*/
