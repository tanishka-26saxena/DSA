//map mai key aur values ke according data store hota ...har key ke liye kuch value mapped hota h
//same key ke liye different values nhi hoti
//mapping 2 type ki ho skti hai ordered map and unordered map
//is datastructure ki time complexity bahut kam hoti h 
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    //creation
    unordered_map<string,int> a;

    //insertion : 1 method 
    pair<string , int> p = make_pair("tanishka" , 1);
    a.insert(p);

    //insertion : 2 method 
    pair<string , int> p2("saxena" , 2);
    a.insert(p2);

    //insertion : 3 method 
    a["chowdhry"] = 3;
    //what will happen?
    a["chowdhry"] = 4;      //chowdhry key ke corresponding jo value padhi hogi wo update ho jayegi

    //searching
    cout<< a["saxena"]<<endl;
    cout<<a.at("chowdhry")<<endl;

    //diff in both kind of searching
    //cout<<a.at("unknown")<<endl; //this will thrown an error
    cout<<a["unknown"]<<endl;    //while this will create a new key and will initialize it with 0

    //size
    cout<< a.size()<<endl;

    //to check if particular key is present or not
    cout<<a.count("bro")<<endl;
    cout<<a.count("tanishka")<<endl;

    //erase
    a.erase("chowdhry");
    cout<<a.size()<<endl;

    //iterating through map : 1 method
    for(auto i:a){
        cout<< i.first <<" "<<i.second<<endl;
    }

    //iterating through map : 2 method
    unordered_map<string, int> :: iterator it = a.begin();

    while(it != a.end()){
        cout<< it->first <<" "<<it->second<<endl;
        it++;
    }

}

//THEORY**********************
//HASHCODES:------->
//hashcodes are the codes made of some input and are converted to store them in some datastructure
//this is dont with the help of compressing

//COLLISSIONS:------>
//for the same key two different values want to be filled ...this causes collissions

//COLLISSION HANDLING:------>
//this can be done in two ways:
//1. OPEN HASHING:---- both the different values are stored for the same key. in arrays this can be implemented using linked lists.
                    //in that particular key the head of the linked lists will be stored pointing to the nodes containing the different values for that key
                    //tjis is also called seperate chaining

//2. OPEN ADDRESSING:---- if we already have a value for the particualar key and another value wants to be stored with the same key then to avoid that we store it into 
                            //next empty index...this can be done by algos like linear probing or quadratic probing

//COMPLEXITY ANALYSIS:------->
//complexity of hash code is O(1)
//insertion,deletion and searching is in O(1) time complexity
//implementation with linked list is i O(n) complexity and with BST is in O(log n) complexity and with arrays in O(1) complexity


// suppose you have 'n' number of entries and 'b' number of boxes , then 
//number of entries in a box will be (n/b)....this is also known as load factor
//we always ensure that the load factor < 0.7...for uniform distribution and less collission


