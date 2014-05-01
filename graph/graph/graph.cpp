#pragma once

void Graph::insert(int a, int b)    {
    map<int , set <int> > :: iterator x, y;
    x = data.find(a);
    y = data.find(b);

    if ( x == data.end() )  {
        //not found a
        set<int> s;
        s.insert(b);
        pair<int, set<int> > temp(a,s);
        data.insert(temp);

        if ( graph_type == 0 )  {
            /* it is an undirected graph , now b to a is also needed */
            if ( y == data.end() )  {
                set<int> s;
                s.insert(a);
                pair<int, set<int> > temp(b,s);
                data.insert(temp);
            } else {
                //b is already there.
                y->second.insert(a);
            }

        }
    } else {
    // if a is already present
        x->second.insert(b);
        if ( graph_type == 0 )  {
            if ( y == data.end() ) {
                // vertex b is not present
                if ( y == data.end() )  {
                set<int> s;
                s.insert(a);
                pair<int, set<int> > temp(b,s);
                data.insert(temp);

            } else {
                y->second.insert(a);
            }
        }

    }
}
}

void Graph::print() {
    map<int, set<int> > :: iterator i = data.begin();
    for( i = data.begin(); i!= data.end(); i++) {
        cout<<i->first<< " : ";
        for( set<int>::iterator j= i->second.begin(); j!=i->second.end(); j++)
            cout<< *j<< " , ";
        cout<<endl;
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
