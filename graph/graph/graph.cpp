#pragma once
#include<fstream>
#include<iostream>
using namespace std;

void Graph::insert(int a, int b)   {
  map < int, set<int> > ::iterator x, y, z;
  x = data.find(a);
  y = data.find(b);

  /* used to get correct output when using undirected graph, a backup mapping */
  z = databack.find(a);
  if ( z == databack.end() )  {
    set<int> s;
    s.insert(b);
    pair< int, set<int> > temp (a,s);
    databack.insert(temp);
  } else if ( z!= databack.end() )  {
     z->second.insert(b);
  }

  if ( x == data.end() )  {
    /* a is not found */
    set<int> s;
    s.insert(b);
    pair< int, set<int> > temp (a,s);
    data.insert(temp);
    if ( graph_type == 0) {
    /* undirected graph */
        if ( y == data.end() )  {
        /* if b is not there */
          set<int> s;
          s.insert(a);
          pair<int, set<int> > temp (b,s);
          data.insert(temp);
        } else {
          y->second.insert(a);
        }
    }
  } else {
  /* if a is already found */
    x->second.insert(b);
    if ( graph_type == 0 )  {
      /* if undirected graph */
      if ( y == data.end() )  {
          set<int> s;
          s.insert(a);
          pair<int, set<int> > temp (b,s);
          data.insert(temp);
      } else {
          y->second.insert(a);
      }
    }
  }
}


void Graph::print() {
  map<int, set<int> >::iterator iter;
  for ( iter=data.begin(); iter!= data.end(); ++iter) {
    cout << iter->first;
    for ( set<int>::iterator i = iter->second.begin(); i!= iter->second.end(); ++i )  {
      cout<< " -> "<<*i;
    }
    cout<<";"<<endl;
  }
}

void Graph::print_dot(ostream& out) {
  map<int, set<int> >::iterator iter;
  if ( graph_type == 0 )  {
    out << "graph {";
    for ( iter=databack.begin(); iter!= databack.end(); ++iter) {
      for ( set<int>::iterator i = iter->second.begin(); i!= iter->second.end(); ++i )  {
      out<< iter->first<<"--"<<*i<< ";";
      }
    }
  out<<" }";
  } else {
    out << "digraph {";
    for ( iter=data.begin(); iter!= data.end(); ++iter) {
      for ( set<int>::iterator i = iter->second.begin(); i!= iter->second.end(); ++i )  {
       out<< iter->first<<"--"<<*i<< ";";
      }
    }
    out<<" }";
  }
}


void Graph::delete_vertex(int a)    {
    map<int, set<int> >::iterator x = data.find(a);
    if( x==data.end() ) {
        cout<<"\n Not found";
    }   else {
        map<int, set<int> >:: iterator x_new;
        for( x_new = data.begin(); x_new!= data.end(); x_new++) {
            x_new->second.erase(a);
        }
        data.erase(x);
    }
}

void Graph::delete_edge( int a, int b) {
    map<int, set<int> > :: iterator x,y;
    x = data.find(a);
    y = data.find(b);
    if( x!= data.end() && y != data.end() ) {
    /* a and b are present */
        x->second.erase(b);
        y->second.erase(a);
    } else {
        cout <<" edge not present ";
    }


}

void Graph::BFS_visit(int vertex, ostream& out) {
    map<int, int> distance;
    map<int, int> parent;
    map<int, string> color;
    map<int, set<int> > ::iterator itr;

    /* initializing values to maps */
    for ( itr = data.begin(); itr!= data.end(); itr++ ) {
        parent.insert(pair<int, int> ( itr->first, 0) );
        color.insert( pair< int, string> ( itr->first, "white") );
        distance.insert( pair< int, int> ( itr->first, 0 ) );
    }
    out << " graph { ";
    queue<int> q;// used in BFS
    q.push( vertex );
    color[vertex] = "grey";
    distance[vertex] = 0;
    parent[vertex] = 0;

    int u;
    while( !q.empty())  {

        u = q.front();

        set<int> adj_nodes = data[u];   //inserting adjacent list to the queue. first the vertex is pushed, then its adjacency list

        for ( set<int>::iterator itr = adj_nodes.begin(); itr != adj_nodes.end(); itr ++ )  {
            if ( color[*itr] == "white" )    {
                    color[*itr] = "grey";
                    parent[*itr] = u;
                    distance[*itr] = distance[u] +1;  //Distance from the ndde u
                    q.push(*itr);
                    out<< u<< "--"<<(*itr) << ";";  //printing to the output file
            }
        }
        q.pop();
        color[u] = "black";
    }
    out<< " }";
    out.flush();
}
