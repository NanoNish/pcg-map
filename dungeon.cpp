#include <bits/stdc++.h>
#define loop(i,a,n,step) for(auto i{a}; i<n; i+=step)
#define ll long long
using namespace std;

const int MAX_X = 64;
const int MAX_Y = 48;
const int MIN_Y = -1;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 generator (seed);

struct point{
    int x;
    int y;
    int dir{0};
    //Direction is 1 if facing +x, 2 if +y, 3 if -y, 0 if no dir
};

class room{
    public:

    int length{0}, width{0};
    point start, end;

    room(int length_inp,int width_inp, point &curr_pos){
        length = length_inp;
        width = width_inp;
        start = curr_pos;
        end.x = start.x + length;
        end.y = start.y;
        curr_pos = end;
        curr_pos.dir = 1;
    }

    room(int switch_case, point &curr_pos){
        switch(switch_case){
            case 0:
                length = 3;
                width = 3;
                break;
            case 1:
                length = 5;
                width = 3;
                break;
            case 2:
                length = 3;
                width = 5;
                break;
            case 3:
                length = 5;
                width = 5;
                break;
            case 4:
                length = 7;
                width = 3;
                break;
            default:
                length = 3;
                width = 3;
                break;
        }
        start = curr_pos;
        end.x = start.x + length;
        end.y = start.y;

        int dir_decider = generator()%3 + 1;
        switch(dir_decider){
            case 3:
                curr_pos.dir = 3;
                curr_pos.x = (start.x + end.x)/2;
                curr_pos.y = start.y - (width+2)/2;
                break;
            case 2:
                curr_pos.dir = 2;
                curr_pos.x = (start.x + end.x)/2;
                curr_pos.y = start.y + (width+2)/2;
                break;
            case 1:
                curr_pos = end;
                curr_pos.dir = 1;
                break;
            default:
                curr_pos = end;
                curr_pos.dir = 1;
                break;
        }
    }

    room(){
        length = 0;
        width = 0;
        start.x = end.x = 0;
        start.y = end.y = 0;
    }
};

void color_grid(vector<vector<int>> &grid, room room_inp){
    for(int i{room_inp.start.x}; i < min(MAX_X, room_inp.end.x); i++){
        for(int j{room_inp.start.y - room_inp.width/2}; j <= min(MAX_Y-1, room_inp.start.y + room_inp.width/2); j++){
            grid[i][j] = 1;
        }
    }
}

void corridors(vector<vector<int>> &grid, point &curr_pos){
    int corr_width = 2 + generator()%3;
    if(curr_pos.x < MAX_X){
        if(curr_pos.dir == 2){
            for(int i{curr_pos.y}; i < min(MAX_Y, corr_width + curr_pos.y); i++){
                grid[curr_pos.x][i] = 1;
            }
            curr_pos.y = corr_width + curr_pos.y;
        }

        if(curr_pos.dir == 3){
            for(int i{curr_pos.y}; i > max(MIN_Y, curr_pos.y - corr_width); i--){
                grid[curr_pos.x][i] = 1;
            }
            curr_pos.y = curr_pos.y - corr_width;
        }
    }
    curr_pos.dir = 1;
    
    int corr_length = 3 + generator()%4;
    if(curr_pos.y < MAX_Y && curr_pos.y > MIN_Y){    
        for(int i{curr_pos.x}; i < min(MAX_X, corr_length + curr_pos.x); i++){
            grid[i][curr_pos.y] = 1;
        }
        curr_pos.x = corr_length + curr_pos.x;
    }
}  

int main(){

    vector<int> tmp_vec(MAX_Y,0);
    vector<vector<int>> grid(MAX_X, tmp_vec);
    point curr_pos;
    curr_pos.x = 0;
    curr_pos.y = 12;
    curr_pos.dir = 1;
    vector<room> room_list;
    
    while(curr_pos.x < MAX_X && curr_pos.y < MAX_Y && curr_pos.y > MIN_Y){
        int switch_case = generator()%5;
        room curr_room(switch_case, curr_pos);
    
        color_grid(grid, curr_room);
        corridors(grid, curr_pos);
    
        room_list.push_back(curr_room); 
    }
    
    for(auto &i: grid){
        for(auto &j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
    
    for(auto &i: grid){
        for(auto &j: i){
            if(j == 0) cout << "  ";
            else cout << "++";
        }
        cout << endl;
    }
}