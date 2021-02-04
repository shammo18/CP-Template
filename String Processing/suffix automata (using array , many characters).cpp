//array implementation of Suffix Automata

struct state
{
    int len,link;
    map<char,int>next;
};

///Note that size of st array is 2*MAXLEN
const int MAXLEN = 100005;
state st[MAXLEN*2];
int sz,last;

void sa_init(int l)
{
    sz=last=0;
    st[0].len=0;
    st[0].link=-1;
    ++sz;
    l=2*l; ///there can be at most 2*l state node in the sa machine.
    for(int i=0;i<l;i++)
        st[i].next.clear();

}

void sa_extend(char c)
{
    int cur=sz++;
    st[cur].len=st[last].len+1;
    int p;
    for(p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c]=cur;
    if(p==-1)
        st[cur].link=0;
    else
    {
        int q=st[p].next[c];
        if(st[p].len+1==st[q].len)
            st[cur].link=q;
        else
        {
            int clone=sz++;
            st[clone].len=st[p].len+1;
            st[clone].next=st[q].next;
            st[clone].link=st[q].link;
            for( ; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c]=clone;
            st[q].link=st[cur].link=clone;
        }
    }
    last=cur;
}

void print_sa(int idx, string str)
{
    if(st[idx].next.empty())
    {
        cout<<str<<endl;
        return;
    }
    for(char ch='a'; ch<='z'; ch++)
    {
        if(st[idx].next.count(ch))
            print_sa(st[idx].next[ch],str+ch);
    }
}


int main(){
       //IOS;

        string s = "abcbc";
        sa_init(s.size());
        for(int i = 0;i < s.size();i++) sa_extend(s[i]);
        print_sa(0 , "");
        for(int i = 0;i < 8;i++) cout << st[i].link <<" ";



return 0;
}
