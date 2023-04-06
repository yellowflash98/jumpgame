#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;


int jumpMove(int arr[], int low, int high, vector <int> &jumpPathVec , vector <int> &minJumpVec );

void solve(int arr[], int low, int high) {
    vector <int> pathVec;
    vector <int> moveVec;
    jumpMove(arr, low, high, pathVec, moveVec);
    if (moveVec.size() < 1)
        cout<< "There is no solution to the given game." <<   "\n"; 
    else {
        cout << "The solution is: {";
        for (int i=0; i< moveVec.size(); i++) {
         
            if (i == moveVec.size() - 1)
                cout<< moveVec[i]<< "}";
            else 
                cout<< moveVec[i]<< ", ";
        }
           
        cout<<"\n";
    

    }
    
}

int jumpMove(int arr[], int low, int high, vector <int> &jumpPathVec , vector <int> &minJumpVec ) { 
    string recurrVars;

    // Base case: when low and high are same 

    if (high == low) {
    
        //recurrVars = "recurrsionCounter = " + to_string(recurrsionCounter) + ", low = " + to_string(low) + 
        //             ", high = " + to_string(high) + " Reached the End of array";
        //recurrsionTreeVec.push_back(recurrVars);
        
        jumpPathVec.push_back (low);
        int curSize= jumpPathVec.size()-1;

        if (minJumpVec.size()>curSize || minJumpVec.size() == 0) {
            minJumpVec.clear();
            for (int i=0; i<=curSize; i++) {
                minJumpVec.push_back(jumpPathVec[i]);
                
            }
            
        }
        else {
            
        }
        //recurrVars = "Returning from recurrsionCounter = " + to_string(recurrsionCounter) ;
        //recurrsionTreeVec.push_back(recurrVars);
        //recurrsionCounter = recurrsionCounter - 1;
        return 0;
    }
   // When nothing is reachable from the given array location 
    if (arr[low] == 0) 
        return INT_MAX; 
 
// Traverse through all the points  
// reachable from arr[low]. Recursively  
// get the minimum number of jumps  
// needed to reach arr[high] from these 
// reachable points. 

    int min = INT_MAX; 

    int backward = low - arr[low];
    int forward = low + arr[low];

    //recurrVars = "recurrsionCounter = " + to_string(recurrsionCounter) + ",low = " + to_string(low) + 
    //             ", high = " + to_string(high) + ", backward = " + to_string(backward) +
    //             ", forward = " + to_string(forward);
    
    if (backward > 0 && (backward + arr[backward]) != low) {
        jumpPathVec.push_back(low);
        
        //recurrVars = recurrVars + ", direction = backward ";
        //recurrsionTreeVec.push_back(recurrVars);
        //recurrsionCounter = recurrsionCounter + 1;
        
        jumpMove(arr, backward, high, jumpPathVec, minJumpVec);
        jumpPathVec.pop_back ();
          
    }
    if (forward <= high) {
        jumpPathVec.push_back(low);
        //recurrVars = recurrVars + ", direction = forward ";
        //recurrsionTreeVec.push_back(recurrVars);
        //recurrsionCounter = recurrsionCounter + 1;        
        
        jumpMove(arr, forward, high, jumpPathVec, minJumpVec);
        jumpPathVec.pop_back ();
        
    }
    //recurrVars = "Returning from recurrsionCounter = " + to_string(recurrsionCounter) + ", min = " + to_string(min) ;
    //recurrsionTreeVec.push_back(recurrVars);
    //recurrsionCounter = recurrsionCounter - 1;
    return INT_MAX; 
}

int main(int argc, char** argv) {
    //int arr[] = { 1,3,4,7};
    //cout << argc << "\n";
    int arr[argc-1];
    
    /*
    for (int i = 0; i <= argc-1 ; i++){
        cout << "argv[" << i << "] = " << argv[i] << "\n";
    } 
    
    cout << "mmmmmmmm \n";
    */
    
    if (argc >= 2) {
        
        for (int i = 0; i <argc-1 ; i++){
            arr[i] = stoi(argv[i+1]);
        }
    
        //for (int i = 0; i <argc-1 ; i++){
        //    cout << "arr[" << i << "] =  " << arr[i] << "\n";
        //}
    }
    //int arr[] = { 1,2,4,1,1,1,7};
    //int n= (sizeof arr)/(sizeof (int));
    //cout<<"n="<<n<<"\n";
    
    solve(arr, 0, argc-2);
 
}
