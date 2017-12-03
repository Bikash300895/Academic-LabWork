#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("input.txt");

    int n;
    in>>n;

    int f;
    in>>f;

    int arr[n];
    int ram[f];

    for(int i=0; i<f; i++){
        ram[i] = -1;
    }

    for(int i=0; i<n; i++){
        in>>arr[i];
    }

    int totalPageFault = 0;
    for(int i=0; i<n; i++){
        // check if it is in ram
        bool found = false;
        for(int j=0; j<f; j++){
            if(ram[j] == arr[i])
                found = true;
        }

        if(found){
            for(int k=0; k<f; k++){
                cout<<ram[k]<<" ";
            }
            cout<<endl;
            continue;
        }

        // if not found there is a page fault
        totalPageFault += 1;

        // find the distance of f elements in ram
        int distance[f];
        for(int j=0; j<f; j++){
            distance[j] = INT_MAX;
            for(int k = i+1; k<n; k++){
                if(arr[k] == ram[j]){
                    distance[j] = k - i;
                    break;
                }
            }
        }

        // find the minimal of distance[]
        int max_index = 0;
        int max_value = INT_MIN;
        for(int j=0; j<f; j++){
            if(distance[j] > max_value){
                max_index = j;
                max_value = distance[j];
            }
        }

        // replace the max value
        ram[max_index] = arr[i];

        // print the ram
        for(int k=0; k<f; k++){
                cout<<ram[k]<<" ";
            }
        cout<<endl;

    }

    cout<<endl<<"Total page fault: "<<totalPageFault<<endl;;

}

