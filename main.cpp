#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class graph {
public:

    int vertices ,edges;

    graph(int v,int e){
        this->vertices = v;
        this->edges = e;
    }

    map< string , vector<pair <string , int> > > graph_list ;

    void add_neighbour(string source, string destination , int distance){
        graph_list[source].push_back({destination,distance});
        graph_list[destination].push_back({source,distance});
    }

    void print_graph(){

        for(auto element_list : graph_list ){
            string node = element_list.first;
            cout<<node<<" -> ";
            for( auto neighbours : graph_list[node] )
                cout <<" (" << neighbours.first<<" - "<<neighbours.second << ") , ";
            cout<<endl;
        }
    }


    void find_shortest_path(){

        cout << " Enter source and destination \n";
        string source , destination;
        cin >> source >> destination;

        priority_queue< pair<int,string> , vector<pair<int,string>> , greater<pair<int,string>> > queue_;
        queue_.push({0, source});

        map<string , bool>visited;
        map<string , int > distance;
        for(auto elements : graph_list ){
            distance[elements.first] = INT_MAX;
        }
        distance[source] = 0 ;
        while(!queue_.empty()){

            auto node_pair = queue_.top();
            queue_.pop();
            string current_node = node_pair.second;
            int node_dist = node_pair.first;

            for(auto neighbour_pair: graph_list[ current_node ]){

                string neighbour = neighbour_pair.first;
                int neighbour_dist = neighbour_pair.second;

                if(!visited[neighbour] && (distance[neighbour] > node_dist + neighbour_dist) ){
                    distance[neighbour] =  node_dist + neighbour_dist;
                    queue_.push({ node_dist + neighbour_dist , neighbour});
                }
            }
        }

        cout<<" Final distances for all nodes from source " << source <<" is :\n" ;
        for(auto element : distance){
            cout<<element.first<<" - "<<element.second<<endl;
        }cout<<endl;

    }


};



int main(){

    graph graph_1(10,15);


     /*
    for(int i = 0 ; i< graph_1.edges ; i++){
        string city1,city2;
        int dist;
        cin>>city1>>city2>>dist;
    }
    */

    graph_1.add_neighbour("Aligarh","Kanpur",15);
    graph_1.add_neighbour("Aligarh","Bareilly",10);
    graph_1.add_neighbour("Aligarh","Prayagraj",5);

    graph_1.add_neighbour("Sector 58","Kanpur",18);

    graph_1.add_neighbour("Sector 58","Goa",2);
    graph_1.add_neighbour("Sector 58","Meerut",16);

    graph_1.add_neighbour("Meerut","Sector 69",20);
    graph_1.add_neighbour("Bareilly","Goa",30);

    graph_1.add_neighbour("Sector 69","Goa",19);
    graph_1.add_neighbour("Jhansi","Sector 69",5);
    graph_1.add_neighbour("Jhansi","Goa",62);

    graph_1.add_neighbour("Prayagraj","Jhansi",31);

    graph_1.add_neighbour("Jhansi","Agra",9);
    graph_1.add_neighbour("Agra","Prayagraj",6);
    graph_1.add_neighbour("Prayagraj","Goa",14);

    graph_1.print_graph();

    graph_1.find_shortest_path();



    return 0;
}