
using namespace std;

template <class type>
size_t Max_Heap<type>::size() const {
    return heap_size;
}

template <class type>
Max_Heap<type>::Max_Heap( typename vector<type>::iterator v_begin, typename vector<type>::iterator v_end ){
/*Constructor to create a heap */
// checking for empty
assert( (v_end - v_begin) > 0);
// To find the size of the vector

size_t size_v = v_end - v_begin;
// To start pushing back to the vector

for(typename vector<type>::iterator itr = v_begin ; itr!= v_end ; itr++ ) {
    data.push_back(*itr);
}

heap_size = size_v;

make_heap();
}

/*@function to create a heap given a vector */
template <class type>
Max_Heap<type>::Max_Heap(vector<type> v) {

    assert(v.size() > 0 );
    data.push_back(0);
    size_t size_v = v.end() - v.begin();
    for( typename vector<type>::iterator itr = v.begin() ; itr!= v.end() ; itr++ ) {
        data.push_back(*itr);
    }
    heap_size =size_v;
    make_heap();
}

/* @function to create a heap */
template <class type>
void Max_Heap<type>::make_heap()    {
    //check for empty
    if ( data.size()<= 1 ) return;
    else {
        for ( size_t i = (data.size()/2); i >= 1; i-- ) {
            heapify_down(i);
        }
    }
}

/*@Function to heapify down*/
template <class type>
void Max_Heap<type>::heapify_down(size_t index) {
    assert(index<= heap_size );
    /* keep the first element as the largest */
    size_t largest = index;
    size_t left = (index << 1);
    size_t right = ( index << 1) + 1;

    /* check for any other element greater than largest */

    if ( (left<=heap_size) && (data[left]> data[largest] ) ) {
        largest = left;
    }

    if ( (right<=heap_size) && (data[right]> data[largest] ) )  {
        largest = right;
    }

    //check if change occured
    if( largest!= index)    {
        swap(data[index], data[largest]);
        heapify_down(largest);
    }

}

/*Function heapify up */
template <class type>
void Max_Heap<type>::heapify_up(size_t index) {
    assert( index<heap_size);
    size_t parent = index/2;
    // check
    if ( data[index] > data[parent] ) {
        swap(data[index], data[parent]);
        heapify_up(parent);
    }
    return;

}

/*@Function to push into heap*/
template <class type>
void Max_Heap<type>::push_heap(type value) {
    data.push_back(value);
    heap_size++;
    heapify_up(heap_size);
    return;
}


/*@Function to pop from heap*/
template <class type>
void Max_Heap<type>::pop_heap() {
    assert(!empty());
    if(heap_size == 1)  {
    /*only one element*/
    heap_size=0;
    data.clear();
    }
    else {
        /* to remove the first elemet
        * we have only pop_back */
        data[1]= data[heap_size];
        --heap_size;
        data.pop_back();
        heapify_down(heap_size);
    }
}



/*@Function to pop without delete*/
template <class type>
void Max_Heap<type>::pop_heap_without_delete() {
    assert(!empty());
    if(heap_size == 1)  {
    /*only one element*/
    heap_size=0;
    data.clear();
    }
    else {
        /* to remove the first elemet
        * we have only pop_back */
        data[1]= data[heap_size];
        --heap_size;
        heapify_down(heap_size);
    }
}

/*@Function level order */
template <class type>
void Max_Heap<type>::levelorder_traversal (ostream& out) const {
    for( size_t i = 1; i<data.size(); i++) {
        out<< data[i]<< " ";
    }
    out<<endl;
}

/*@Funciton to print the tree */
template <class type>
void Max_Heap<type>::print_tree(ostream& out ) const {
    out<< endl;
    size_t h = height();
    type front = spaces.begin();
    type back = spaces.end();
    vector<size_t> spaces;
    spaces.push_back(0);
    for(size_t i =0; i<=h;i++)   {
        spaces.push_back( (spaces[i]+ 1) * 2);
    }
    reverse(spaces.begin(), spaces.end());
    for( size_t i = 0; i<spaces.size(); i++)    {
        out<< spaces[i]<< " ";
    }
    out<<endl;

    size_t counter = 1;
    for ( size_t i=0; i<= h;i++)    {
        for ( size_t k =0; k< pow(2.0, i*1.0); k++) {
            if ( counter > heap_size) break;
            for ( size_t j =0; j< spaces[i]; j++) out<<' ';
            out << setw(3) << data[counter++];

            for(size_t j=0; j< spaces[i]+1; j++) out<< ' ';
        }
        out<< endl;
        if( counter > heap_size ) break;
        /* arrows*/
        size_t count_1 = spaces[i], count_2= 0, count_3 =1;
        for( size_t j =0; j< spaces[i]/2; j++)  {
            for ( size_t k =0; k< pow(2.0, i*1.0);k++) {
                for(size_t l= 0; l< count_1- count_3;l++) out<< ' ';

                out<< "/";

                for(size_t l =0; l< 3+count_2; l++) out << ' ';
                out << "\\";

                for(size_t l =0; l< count_1-count_3; l++) out << ' ';
                out<< " ";

                }
                out<<endl;
                count_2 += 2;
                count_3 ++;
        }
    }
    out<<endl;
}

