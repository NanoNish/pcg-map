#include <bits/stdc++.h>
#define loop(i,a,n,step) for(auto i{a}; i<n; i+=step)
#define ll long long
using namespace std;


/*
based on where right now u decide if going up or down or fwd
room to room recalling of function
room sizes: 3x4 5x5 6x3 3x3 4x3
total board of 64x24
*/

const int MAX_X = 64;
const int MAX_Y = 24;

struct point{
    int x;
    int y;
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
    }

    room(int switch_case, point &curr_pos){
        switch(switch_case){
            case 0:
                length = 3;
                width = 3;
                break;
            case 1:
                length = 4;
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
                length = 6;
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
        curr_pos = end;
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
        for(int j{room_inp.start.y - room_inp.width/2}; j <= min(23, room_inp.start.y + room_inp.width/2); j++){
            grid[i][j] = 1;
        }
    }
}

void corridors(vector<vector<int>> &grid, point &curr_pos){
    int corr_length = 3 + rand()%4;
    for(int i{curr_pos.x}; i < min(MAX_X, corr_length + curr_pos.x); i++){
        grid[i][curr_pos.y] = 1;
    }
    curr_pos.x = corr_length + curr_pos.x;
}  

int main(){

    vector<int> tmp_vec(MAX_Y,0);
    vector<vector<int>> grid(MAX_X, tmp_vec);
    point curr_pos;
    curr_pos.x = 0;
    curr_pos.y = 5;
    vector<room> room_list;
    
    while(curr_pos.x < MAX_X && curr_pos.y < MAX_Y){
        int switch_case = rand()%5;
        room curr_room(switch_case, curr_pos);
    
        color_grid(grid, curr_room);
        corridors(grid, curr_pos);
    
        cout << curr_room.length << " " << curr_room.width << " " << curr_room.start.x << " " << curr_room.start.y << " " << curr_room.end.x << " " << curr_room.end.y << endl;
    
        room_list.push_back(curr_room); 
    }
    
    for(auto &i: grid){
        for(auto &j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    
    for(auto &i: grid){
        for(auto &j: i){
            if(j == 0) cout << "  ";
            else cout << "++";
        }
        cout << endl;
    }

    cout << endl;
}