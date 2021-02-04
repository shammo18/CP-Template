

struct Node{
    ll h , w , id;
    Node() {}
    Node(ll a , ll b , ll c) : id(a) , h(b)  ,w(c); // Constructor

    bool operator < (const Node& a) const{
       return h * w > a.h * a.w;
       // if return true then pq will swap them otherwise not
       // here Node& a  is the 2nd node
       // here small area have higher priority than big area
    }
};


Node x(7 , 9 , 9); // declaring a Node

priority_queue<Node> pq;
