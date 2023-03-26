#include<iostream>
#include<unordered_map>
#include<map>
#include<list>


using namespace std;

template <typename T>
class graph{
    //direction = 0 undirected
    //direction = 1 directed

    public:
        unordered_map<T ,list<T>> adj;

        void addEdge(T u, T v, bool direction){
            adj[u].push_back(v);

            if(direction==0)
                adj[v].push_back(u);

        }


        void printadjlist(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }

};

int main()
{
    int n;
    cout<<"Enter the no of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the no of edges"<<endl;
    cin>>m;

    graph <int>g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }


    g.printadjlist();
    
    return 0;
}