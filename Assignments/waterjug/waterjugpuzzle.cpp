/*******************************************************************************
 * Name        : waterjugpuzzle.cpp
 * Author      : Jerry Chen, Jerry Cheng
 * Date        : 10/1/19
 * Description : Solving water jug puzzles.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <utility>


using namespace std;

// Struct to represent state of water in the jugs.
struct State {    int a, b, c;    vector<string> directions;    
State(int _a, int _b, int _c) : a(_a), b(_b), c(_c) { }    

// String representation of state in tuple form.   
string to_string() {        
    ostringstream oss;        
    oss << "(" << a << ", " << b << ", " << c << ")";        
    return oss.str();    
    }
};

void solve(int ga, int gb, int gc, int ca, int cb, int cc, stack<pair<vector<int>, string>> & s){
    //initialize a queue to store the states into
    bool t = false;
    queue<vector<int>> q;
    //State start(0, 0, cc);
    vector<int> start{0, 0, cc};
    map<vector<int>, pair<vector<int>, string>> m;
    q.push(start);
    m[start] = make_pair(start,"");

    while(!q.empty()){//runs through every possibility of state transitions in a bfs order(queue)
    //without repeating previous states(map)
        vector<int> curr = q.front();
        int a = curr[0];
        int b = curr[1];
        int c = curr[2];
        q.pop();
        //check if we are at the goal state
        if(a == ga && b == gb && c == gc){
            t = true;
            break;
        }
        //go through the 6 transitions and check which one is available
        if(a < ca && c > 0){//pour from C to A
            vector<int> x{min(a + c, ca), b, c - min(ca - a, c)};
            if(m.find(x) == m.end()){//if the state was not repeated
                q.push(x);
                auto s = std::to_string(min(ca-a, c));
                if(min(ca-a, c) > 1){
                    m[x] = make_pair(curr, "Pour " + s + " gallons from C to A. ");
                }
                else{
                    m[x] = make_pair(curr, "Pour " + s + " gallon from C to A. ");
                }
            }
        }
        if(a < ca && b > 0){//pour from B to A
            vector<int> x{min(a + b, ca), b - min(ca - a, b), c};
            if(m.find(x) == m.end()){
                q.push(x);
                auto s = std::to_string(min(ca-a, b));
                if(min(ca-a, b) > 1){
                    m[x] = make_pair(curr, "Pour " + s + " gallons from B to A. ");
                }
                else{
                    m[x] = make_pair(curr, "Pour " + s + " gallon from B to A. ");
                }
            }
        }
        if(b < cb && c > 0){//pour from C to B
            vector<int> x{a, min(b + c, cb), c - min(cb - b, c)};
            if(m.find(x) == m.end()){
                q.push(x);
                auto s = std::to_string(min(cb-b, c));
                if(min(cb-b, c) > 1){
                    m[x] = make_pair(curr, "Pour " + s + " gallons from C to B. ");
                }
                else{
                    m[x] = make_pair(curr, "Pour " + s + " gallon from C to B. ");
                }
            }
        }
        if(b < cb && a > 0){//pour from A to B
            vector<int> x{a - min(cb - b, a), min(b + a, cb), c};
            if(m.find(x) == m.end()){
                q.push(x);
                auto s = std::to_string(min(cb-b, a));
                if(min(cb-b, a) > 1){
                    m[x] = make_pair(curr, "Pour " + s + " gallons from A to B. ");
                }
                else{
                    m[x] = make_pair(curr, "Pour " + s + " gallon from A to B. ");
                }
            }
        }
        if(c < cc && b > 0){//pour from B to C
            vector<int> x{a, b - min(cc - c, b), min(c + b, cc)};
            if(m.find(x) == m.end()){
                q.push(x);
                auto s = std::to_string(min(cc-c, b));
                if(min(cc-c, b) > 1){
                    m[x] = make_pair(curr, "Pour " + s + " gallons from B to C. ");
                }
                else{
                    m[x] = make_pair(curr, "Pour " + s + " gallon from B to C. ");
                }
            }
        }
        if(c < cc && a > 0){//pour from A to C
            vector<int> x{a - min(cc - c, a), b, min(c + a, cc)};
            if(m.find(x) == m.end()){
                q.push(x);
                auto s = std::to_string(min(cc-c, a));
                if(min(cc-c, a) > 1){
                    m[x] = make_pair(curr, "Pour " + s + " gallons from A to C. ");
                }
                else{
                    m[x] = make_pair(curr, "Pour " + s + " gallon from A to C. ");
                }
            }
        }
    }
    if(!t){
        return;
    }
    //place goal state at the bottom of stack
    vector<int> goal{ga, gb, gc};
    pair<vector<int>, string> i(goal, m[goal].second);
    s.push(i);
    //work backwards and keep adding the parent state into the stack until we get to start
    while(m[s.top().first].first != start){
        s.push(make_pair(m[s.top().first].first, m[m[s.top().first].first].second));
    }
     
    
}
bool isnumber(const string &s){
    //check if the input is a number
    bool x = true;
    for(unsigned int i = 0; i < s.length(); i++){
        if(!(isdigit(s[i]))){
            x = false;
        }
    }
    return x;
}

int main(int argc, char * const argv[]) {    
    vector<vector<string>> arr{{}, {"capacity", "A"}, {"capacity", "B"}, {"capacity", "C"}, {"goal", "A"}, {"goal", "B"}, {"goal", "C"}};
    vector<vector<string>> carr{{}, {"Capacity", "A"}, {"Capacity", "B"}, {"Capacity", "C"}, {"Goal", "A"}, {"Goal", "B"}, {"Goal", "C"}};
    if(argc != 7){
        cerr << "Usage: " << argv[0] << " <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
        return 1;
    }
    
    for(int i = 1; i <= 6; i++){
        if((isnumber(argv[i]) == false) || (((atoi(argv[i]) <= 0)) && (i <= 3))){
            cerr << "Error: Invalid " << arr[i][0] << " '" << argv[i] << "'" << " for jug " << arr[i][1] << "." << endl;
            return 1;
        }
        
        if((i >= 4) && (atoi(argv[i]) > atoi(argv[i-3])) && (atoi(argv[i]) > 0)){
            cerr << "Error: " << carr[i][0] << " cannot exceed capacity of jug " << arr[i][1] << "." << endl;
            return 1;
        }
        if((i <= 3) && (atoi(argv[i+3]) < 0)){
            cerr << "Error: Invalid " << arr[i+3][0] << " '" << argv[i+3] << "'" << " for jug " << arr[i+3][1] << "." << endl;
            return 1;
        }
    }
    if(atoi(argv[3]) != (atoi(argv[4]) + atoi(argv[5]) + atoi(argv[6]))){
            cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
            return 1;
    }

    stack<pair<vector<int>, string>> s;
    vector<int> start{0, 0, atoi(argv[3])};
    solve(atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), s);
    if(s.empty()){
        cerr << "No solution." << endl;
    }
    else{
        vector<int> g{atoi(argv[4]), atoi(argv[4]), atoi(argv[6])};
        State z(0, 0, start[2]);
        if(s.top().first == g){
            cout << "Initial state. " << z.to_string() << endl;
        }
        else{
            cout << "Initial state. " << z.to_string() << endl;
            while(!s.empty()){
                State z(s.top().first[0], s.top().first[1], s.top().first[2]);
                cout << s.top().second << z.to_string() << endl;
                s.pop();
            }
        }
    }
}