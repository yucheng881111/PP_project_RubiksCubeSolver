#include<bits/stdc++.h>
#include "CycleTimer.h"
#include<omp.h>
#include<tbb/concurrent_queue.h>

using namespace std;

typedef long long ll;

string Move(string state, int opt);

void CW(vector<char> &v1, vector<char> &v2, vector<char> &v3){
    char t1 = v1[0];
    char t2 = v1[1];
    char t3 = v1[2];
    char t4 = v2[0];
    char t5 = v2[1];
    char t6 = v2[2];
    char t7 = v3[0];
    char t8 = v3[1];
    char t9 = v3[2];

    v1[0] = t7; v1[1] = t4, v1[2] = t1;
    v2[0] = t8; v2[1] = t5, v2[2] = t2;
    v3[0] = t9; v3[1] = t6, v3[2] = t3;
}

// FrontCW
void rotate1(vector<vector<char>> &v){
    CW(v[6], v[7], v[8]);

    char temp1[3];
    temp1[0] = v[2][0];
    temp1[1] = v[2][1];
    temp1[2] = v[2][2];

    char temp2[3];
    temp2[0] = v[9][0];
    temp2[1] = v[10][0];
    temp2[2] = v[11][0];

    char temp3[3];
    temp3[0] = v[15][0];
    temp3[1] = v[15][1];
    temp3[2] = v[15][2];

    char temp4[3];
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
void rotate2(vector<vector<char>> &v){
    rotate1(v);
    rotate1(v);
    rotate1(v);
}
// UpCW
void rotate3(vector<vector<char>> &v){
    CW(v[0], v[1], v[2]);

    char temp1[3];
    temp1[0] = v[12][0];
    temp1[1] = v[12][1];
    temp1[2] = v[12][2];

    char temp2[3];
    temp2[0] = v[9][0];
    temp2[1] = v[9][1];
    temp2[2] = v[9][2];

    char temp3[3];
    temp3[0] = v[6][0];
    temp3[1] = v[6][1];
    temp3[2] = v[6][2];

    char temp4[3];
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
void rotate4(vector<vector<char>> &v){
    rotate3(v);
    rotate3(v);
    rotate3(v);
}
// DownCW
void rotate5(vector<vector<char>> &v){
    CW(v[15], v[16], v[17]);

    char temp1[3];
    temp1[0] = v[8][0];
    temp1[1] = v[8][1];
    temp1[2] = v[8][2];

    char temp2[3];
    temp2[0] = v[11][0];
    temp2[1] = v[11][1];
    temp2[2] = v[11][2];

    char temp3[3];
    temp3[0] = v[14][0];
    temp3[1] = v[14][1];
    temp3[2] = v[14][2];

    char temp4[3];
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
void rotate6(vector<vector<char>> &v){
    rotate5(v);
    rotate5(v);
    rotate5(v);
}
// LeftCW
void rotate7(vector<vector<char>> &v){
    CW(v[3], v[4], v[5]);

    char temp1[3];
    temp1[0] = v[0][0];
    temp1[1] = v[1][0];
    temp1[2] = v[2][0];

    char temp2[3];
    temp2[0] = v[6][0];
    temp2[1] = v[7][0];
    temp2[2] = v[8][0];

    char temp3[3];
    temp3[0] = v[15][0];
    temp3[1] = v[16][0];
    temp3[2] = v[17][0];

    char temp4[3];
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
void rotate8(vector<vector<char>> &v){
    rotate7(v);
    rotate7(v);
    rotate7(v);
}
// RightCW
void rotate9(vector<vector<char>> &v){
    CW(v[9], v[10], v[11]);

    char temp1[3];
    temp1[0] = v[0][2];
    temp1[1] = v[1][2];
    temp1[2] = v[2][2];

    char temp2[3];
    temp2[0] = v[12][0];
    temp2[1] = v[13][0];
    temp2[2] = v[14][0];

    char temp3[3];
    temp3[0] = v[15][2];
    temp3[1] = v[16][2];
    temp3[2] = v[17][2];

    char temp4[3];
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
void rotate10(vector<vector<char>> &v){
    rotate9(v);
    rotate9(v);
    rotate9(v);
}
// BackCW
void rotate11(vector<vector<char>> &v){
    CW(v[12], v[13], v[14]);

    char temp1[3];
    temp1[0] = v[0][0];
    temp1[1] = v[0][1];
    temp1[2] = v[0][2];

    char temp2[3];
    temp2[0] = v[3][0];
    temp2[1] = v[4][0];
    temp2[2] = v[5][0];

    char temp3[3];
    temp3[0] = v[17][0];
    temp3[1] = v[17][1];
    temp3[2] = v[17][2];

    char temp4[3];
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
void rotate12(vector<vector<char>> &v){
    rotate11(v);
    rotate11(v);
    rotate11(v);
}


string to_state(vector<vector<char>> &v){
    string s = "";
    for(int i=0;i<18;++i){
        for(int j=0;j<3;++j){
            s += v[i][j];
        }
    }
    return s;
}

vector<vector<char>> to_node(string &s){
    char tmp[3];
    vector<vector<char>> v;
    for(int i=0;i<54;++i){
        if(i % 3 == 0){
            tmp[0] = s[i];
        }else if(i % 3 == 1){
            tmp[1] = s[i];
        }else{
            tmp[2] = s[i];
            vector<char> temp(tmp,tmp+3);
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
	char c1_0 = arr[9*i + 3*z];
 	char c1_1 = arr[9*i + 3*z + 1];
 	char c1_2 = arr[9*i + 3*z + 2];

    int center = -1;
    char c2_0, c2_1, c2_2;
    vector<vector<char>> cube = to_node(state);
    for(int c=1; c<=16; c+=3){
    	if( cube[i][z] == cube[c][1] ){
    		center = c;
    		break;
    	}
    }
    
    /*int minimum=INT_MAX, d[4];
    if(corner){
        #pragma omp parallel for
        for(int i =0; i<2; i++){
            c2_0 = arr[9*(center-1) + 3*2*i];
            c2_1 = arr[9*(center-1) + 3*2*i + 1];
            c2_2 = arr[9*(center-1) + 3*2*i + 2];
            d[i] = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        }
        #pragma omp parallel for
        for(int i =0; i<2; i++){
            c2_0 = arr[9*(center+1) + 3*2*i];
            c2_1 = arr[9*(center+1) + 3*2*i + 1];
            c2_2 = arr[9*(center+1) + 3*2*i + 2];
            d[i+2] = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        }
        for(int i=0; i<4; i++){
            if(d[i]<minimum) 
                minimum = d[i];
        }
    }else{
        #pragma omp parallel for
        for(int i =0; i<2; i++){
            c2_0 = arr[9*center + 3*2*i];
            c2_1 = arr[9*center + 3*2*i + 1];
            c2_2 = arr[9*center + 3*2*i + 2];
            d[2*i] = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        }
        #pragma omp parallel for
        for(int i =-1; i<2; i+=2){
            c2_0 = arr[9*(center+i) + 3*1];
            c2_1 = arr[9*(center+i) + 3*1 + 1];
            c2_2 = arr[9*(center+i) + 3*1 + 2];
            d[i+2] = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        }
        for(int i=0; i<4; i++){
            if(d[i]<minimum) 
                minimum = d[i];
        }

    }*/

    
    int d1, d2, d3 ,d4, minimum;
    if(corner){
        //c2 = array[center - 1, 0]
        c2_0 = arr[9*(center-1) + 3*0];
 		c2_1 = arr[9*(center-1) + 3*0 + 1];
 		c2_2 = arr[9*(center-1) + 3*0 + 2];
        d1 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        minimum = d1;
        //c2 = array[center - 1, 2]
        c2_0 = arr[9*(center-1) + 3*2];
 		c2_1 = arr[9*(center-1) + 3*2 + 1];
 		c2_2 = arr[9*(center-1) + 3*2 + 2];
        d2 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d2<minimum){ minimum = d2; }
        //c2 = array[center + 1, 0]
        c2_0 = arr[9*(center+1) + 3*0];
 		c2_1 = arr[9*(center+1) + 3*0 + 1];
 		c2_2 = arr[9*(center+1) + 3*0 + 2];
        d3 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d3<minimum){ minimum = d3; }
        //c2 = array[center + 1, 2]
        c2_0 = arr[9*(center+1) + 3*2];
 		c2_1 = arr[9*(center+1) + 3*2 + 1];
 		c2_2 = arr[9*(center+1) + 3*2 + 2];
        d4 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d4<minimum){ minimum = d4; }
    }else{
        //c2 = array[center - 1, 1]
        c2_0 = arr[9*(center-1) + 3*1];
 		c2_1 = arr[9*(center-1) + 3*1 + 1];
 		c2_2 = arr[9*(center-1) + 3*1 + 2];
        d1 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        minimum = d1;
        //c2 = array[center, 0]
        c2_0 = arr[9*center + 3*0];
 		c2_1 = arr[9*center + 3*0 + 1];
 		c2_2 = arr[9*center + 3*0 + 2];
        d2 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d2<minimum){ minimum = d2; }
        //c2 = array[center, 2]
        c2_0 = arr[9*center + 3*2];
 		c2_1 = arr[9*center + 3*2 + 1];
 		c2_2 = arr[9*center + 3*2 + 2];
        d3 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d3<minimum){ minimum = d3; }
        //c2 = array[center + 1, 1]
        c2_0 = arr[9*(center+1) + 3*1];
 		c2_1 = arr[9*(center+1) + 3*1 + 1];
 		c2_2 = arr[9*(center+1) + 3*1 + 2];
        d4 = abs(c1_0 - c2_0) + abs(c1_1 - c2_1) + abs(c1_2 - c2_2);
        if(d4<minimum){ minimum = d4; }
    }

    return minimum;
}

int corner_edge_sum_max(string &state){
	int corners = 0;
	int edges = 0;

    /*
    //Another method
    int corners_mat[18];
    int edges_mat[18];
    #pragma omp parallel for
    for(int i=0; i<18; i+=3){
        corners_mat[i] = manhattan_distance(state, i, 0, true) + manhattan_distance(state, i, 2, true);
        corners_mat[i+1] = 0;
        corners_mat[i+2] = manhattan_distance(state, i+2, 0, true) + manhattan_distance(state, i+2, 2, true);
        edges_mat[i] = manhattan_distance(state, i, 1, false);
        edges_mat[i+1] = manhattan_distance(state, i+1, 0, false) + manhattan_distance(state, i+1, 2, false);
        edges_mat[i+2] = manhattan_distance(state, i+2, 1, false);        
    }
    #pragma omp parallel for reduction(+:corners, edges)
    for(int i=0; i<18; i++){
        corners = corners + corners_mat[i];
        edges = edges + edges_mat[i];
    }*/

    #pragma omp parallel for reduction(+:corners, edges)
    for(int i=0; i<18; i+=3){
        corners = corners + manhattan_distance(state, i, 0, true) + manhattan_distance(state, i, 2, true);
        corners = corners + manhattan_distance(state, i+2, 0, true) + manhattan_distance(state, i+2, 2, true);
        edges = edges + manhattan_distance(state, i, 1, false);
        edges = edges + manhattan_distance(state, i+1, 0, false) + manhattan_distance(state, i+1, 2, false);
        edges = edges + manhattan_distance(state, i+2, 1, false);        
    }
    
	/*for(int i=0; i<18; i++){
		if(i % 3 == 0 || i % 3 == 2){
			corners = corners + manhattan_distance(state, i, 0, true) + manhattan_distance(state, i, 2, true);
            edges = edges + manhattan_distance(state, i, 1, false);
		}else{
			edges = edges + manhattan_distance(state, i, 0, false) + manhattan_distance(state, i, 2, false);
		}
	}*/

	int sum_max;
	if( (corners/12) >= (edges/8) ){
		sum_max = (corners/12);
	}else{
		sum_max = (edges/8);
	}
	return sum_max;
}

class node{
public:
    string state;
    int f, g, h;
    node(){}
    node(string s, int g_in){
        state = s;
        g = g_in;
        h = corner_edge_sum_max(state);
        f = g + h;
    }
};

int IDA(vector<vector<char>> &v){
    vector<vector<char>> start_node = v;
    string start_state = to_state(start_node);
    node node_start(start_state, 0);
    int thread_num = 12;
    bool finished = 0;
    bool end[thread_num];
    int ans = 0;
    int minimum[thread_num];

    omp_set_num_threads(thread_num);
    tbb::concurrent_queue<node> global_q[thread_num];
    hash<string> H;

    //global_q[H(start_state) % thread_num].push(node_start);

    int cost_limit = node_start.h;

    while(!finished){
        for(int i=0; i<thread_num; i++){
            minimum[i] = INT_MAX;
            end[i]=false;
        }

        global_q[H(start_state) % thread_num].push(node_start);

        #pragma omp parallel
        {
            int id = omp_get_thread_num();
            queue<node> q;
            unordered_set<ll> used;
            hash<string> H1;
            while( !finished && (!end[0] || !end[1] || !end[2] || !end[3] || !end[4] || !end[5] || !end[6] || !end[7] || !end[8] || !end[9] || !end[10] || !end[11]) ){
                while(!global_q[id].empty()){
                    node n;
                    global_q[id].try_pop(n);
                    q.push(n);
                    end[id] = false;
                }

                if(q.empty()){
                    end[id] = true;
                    continue;
                }

                node curr_node = q.front();
                q.pop();
                string curr_state = curr_node.state;

                if(used.count(H1(curr_state))){
                    continue;
                }

                int curr_g = curr_node.g;
                int next_g = curr_g + 1;
                used.insert(H1(curr_state));

                for(int i=1;i<=12;++i){
                    string next_state = Move(curr_state, i);
                    if(goal(next_state)){
                        ans = next_g;
                        finished = 1;
                        break;
                    }else if(used.count(H1(next_state)) != 1){
                        node next_node(next_state, next_g);
                        if( next_node.g + next_node.h > cost_limit){
                            if ( next_node.g + next_node.h < minimum[id] ){
                                minimum[id] = next_node.g + next_node.h;
                            }
                            continue;
                        }

                        global_q[H1(next_state) % thread_num].push(next_node);
                    }
                }
            }
        }
        cost_limit = *min_element(minimum , minimum + thread_num);
    }

    return ans;
}

int BFS(vector<vector<char>> &v){
    vector<vector<char>> start_node = v;
    string start_state = to_state(start_node);

    int thread_num = 12;
    bool finished = false;
    int ans;

    omp_set_num_threads(thread_num);
    tbb::concurrent_queue<pair<string, int>> global_q[thread_num];

    hash<string> H;
    global_q[H(start_state) % thread_num].push(make_pair(start_state, 1));

    #pragma omp parallel
    {   
        int id = omp_get_thread_num();
        queue<pair<string, int>> tq;
        unordered_set<ll> used;
        hash<string> H1;

        while(!finished){
            while(!global_q[id].empty()){
                pair<string, int> bfs_node;
                global_q[id].try_pop(bfs_node);
                tq.push(bfs_node);
            }

            if(tq.empty()){
                continue;
            }
            
            pair<string, int> bfs_node = tq.front();
            tq.pop();
            string curr_state = bfs_node.first;
            int cnt = bfs_node.second;

            if(used.count(H1(curr_state))){
                continue;
            }

            used.insert(H1(curr_state));

            for(int i=1;i<=12;++i){
                string next_state = Move(curr_state, i);
                if(goal(next_state)){
                    final_state = next_state;
                    ans = cnt;
                    finished = true;
                    break;
                }else if(used.count(H1(next_state)) != 1){
                    global_q[H1(next_state) % thread_num].push(make_pair(next_state, cnt + 1));
                }
            }
        }
    }


    return ans;
}

struct cmp{
    bool operator()(node &a, node &b){
        return a.f > b.f;
    }
};


int A_star(vector<vector<char>> &v){
    vector<vector<char>> start_node = v;
    string start_state = to_state(start_node);
    node node_start(start_state, 0);
    int thread_num = 12;
    bool finished = 0;
    int ans = 0;

    omp_set_num_threads(thread_num);
    tbb::concurrent_queue<node> global_q[thread_num];
    hash<string> H;
    global_q[H(start_state) % thread_num].push(node_start);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        priority_queue<node, vector<node>, cmp> pq;
        unordered_set<ll> used;
        hash<string> H1;

        while(!finished){
            while(!global_q[id].empty()){
                node n; 
                global_q[id].try_pop(n);
                pq.push(n);
            }

            if(pq.empty()){
                continue;
            }

            node curr_node = pq.top();
            pq.pop();
            string curr_state = curr_node.state;

            if(used.count(H1(curr_state))){
                continue;
            }

            int curr_g = curr_node.g;
            int next_g = curr_g + 1;
            used.insert(H1(curr_state));

            for(int i=1;i<=12;++i){
                string next_state = Move(curr_state, i);
                if(goal(next_state)){
                    ans = next_g;
                    finished = 1;
                    break;
                }else if(used.count(H1(next_state)) != 1){
                    node next_node(next_state, next_g);
                    global_q[H1(next_state) % thread_num].push(next_node);
                }
            }
        }
    }

    return ans;
}


string Move(string state, int opt){
    vector<vector<char>> vec = to_node(state);
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
    
    int test = 10;
    int input_steps = 9;
    int method = 2; // 1:BFS 2:A_star 3:IDA
    double avg = 0.0;
    srand((unsigned)time(NULL));
    vector<double> all_times;

    for(int times=1;times<=test;){
        string sstart = "111111111222222222333333333444444444555555555666666666";
        
        for(int i=0;i<input_steps;++i){
            int move_opt = rand() % 12 + 1;
            sstart = Move(sstart, move_opt);
        }
        
        vector<vector<char>> vec_input = to_node(sstart);

        if(method == 1){
            double startTime = CycleTimer::currentSeconds();
            int steps = BFS(vec_input);
            if(steps != input_steps){
		cout << "steps " << steps << " not match." <<endl;
                continue;
            }
            double endTime = CycleTimer::currentSeconds();
            cout << times << " times:" << endl;
            times++;
            cout << "\nBFS steps: " << steps << endl;
            printf("time: [%.3f] ms\n", (endTime - startTime) * 1000);
            avg += ((endTime - startTime) * 1000);
            all_times.push_back((endTime - startTime) * 1000);
            cout << endl;
        }else if(method == 2){
            double startTime = CycleTimer::currentSeconds();
            int steps = A_star(vec_input);
            if(steps != input_steps){
		cout << "steps " << steps << " not match." << endl;
                continue;
            }
            double endTime = CycleTimer::currentSeconds();
            cout << times << " times:" << endl;
            times++;
            cout << "\nA star steps: " << steps << endl;
            printf("time: [%.3f] ms\n", (endTime - startTime) * 1000);
            avg += ((endTime - startTime) * 1000);
            all_times.push_back((endTime - startTime) * 1000);
            cout << endl;
        }else if(method == 3){
            double startTime = CycleTimer::currentSeconds();
            int steps = IDA(vec_input);
            if(steps != input_steps){
		cout << "steps " << steps << " not match." << endl;
                continue;
            }
            double endTime = CycleTimer::currentSeconds();
            cout << times << " times:" << endl;
            times++;
            cout << "\nIDA star steps: " << steps << endl;
            printf("time: [%.3f] ms\n", (endTime - startTime) * 1000);
            avg += ((endTime - startTime) * 1000);
            all_times.push_back((endTime - startTime) * 1000);
            cout << endl;
        }
    }
    cout << endl << "avg time: " << avg / test  << " ms" << endl;
    cout << "min time: " << *min_element(all_times.begin(), all_times.end()) << " ms" << endl;
    cout << "max time: " << *max_element(all_times.begin(), all_times.end()) << " ms" << endl;
    

    return 0;
}
