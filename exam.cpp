#include<bits/stdc++.h>
using namespace std;

struct node
{
    int  val;
    string dates;
    string data;
    int nn;
    string nodeid;
    struct node *refnd;
    struct node *childnd;
    struct node *genesisnd;
    string hashh;
};
void print(struct node t[],int tt)
{
 cout<<"your data is been shown";
    for(int i=0;i<tt;i++)
    {

         cout<<t[i].val<<t[i].dates<<t[i].data<<t[i].nn<<t[i].nodeid<<endl;;
    }
}
int findgenesis(struct node arr[],int tt)
{   int maxx=INT_MIN;
    int pos=-1;
    cout<<"finding genesis node";
    for(int i=0;i<tt;i++)
    {
        if(arr[i].val>maxx)
        {
            maxx=arr[i].val;
            pos=i;
        }
    }
    return(pos);
}

void setchild(struct node t[],int tt,int j)
{
     int maxx=t[j].val;
    int pos=-1;
    cout<<"finding child set node\n";
    for(int i=0;i<tt;i++)
    {
        if(t[i].val<maxx)
        {
            cout<<"recod number "<<i<<" is a child of given node\n";
        }
    }

}
void encryptrec(struct node t[],int tt)
{
    ;
    cout<<"performing encryption of nodes\n..\n..\n";
    for(int i=0;i<tt;i++)
    {
       t[i].hashh=t[i].data+t[i].dates;
       t[i].data+=t[i].hashh;
       t[i].dates+=t[i].hashh;


    }

}
void decryptrec(struct node t[],int tt)
{
    ;
    cout<<"performing decryption of nodes\n..\n..\n";
    for(int i=0;i<tt;i++)
    {

       t[i].data=t[i].hashh;
       t[i].dates=t[i].hashh;
    }

}
int main()
{   int tt,tr,n,i,j,k,l;
    cin>>tt;//t is total no of owners record;
    tr=tt;
    struct node t[tt];
     string abc;
    i=0;
    while(tt--)
    {
    int x;
        //t[i]=(struct node*)malloc(sizeof(struct node));
        cout<<"enter value of val-integer or float type\n";
        cin>>x;
        t[i].val=x;
         cout<<"enter value of timestamp-string type\n";
        cin>>abc;
        //cin.flush();
        //cin.ignore();
        t[i].dates=abc;
        abc="";
         cout<<"enter value of data-string type\n";
        cin>>abc;
        //cin.ignore();
        t[i].data=abc;
         cout<<"enter value of node number-integer type\n";
        cin>>x;
        t[i].nn=x;
        abc="";
        cout<<"enter value of node-id-stringtype\n";
        cin>>abc;
        cin.ignore();
        t[i].nodeid=abc;
        t[i].childnd=NULL;
        t[i].refnd=NULL;
        t[i].genesisnd=NULL;
        t[i].hashh="\0";
        i++;

    }
   print(t,tr);
   j=findgenesis(t,tr);
   cout<<"geneis node record number is\n"<<j<<"and value at this recod is max"<<t[j].val;
   cout<<"enter record number of node whose set of child you wnna know\n";
   cin>>j;
   setchild(t,tr,j);
}
