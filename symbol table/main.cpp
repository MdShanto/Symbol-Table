#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<map>

using namespace std;

struct node{
    string symbol;
    string typeSymbol;
    node *next;
};


int n,i=0;
map <string,string> mp;
node* arr[500];

int hashcode(string sym)
{
   int c,s=0;
    for(i = 0; i < sym.length(); i++)
    {
        c=sym[i];
        s=s+c;
    }
    return s;

}


void insert(){
      int ascii,index;
      string sym,t_sym;
      cin>>sym>>t_sym;

       if(mp.count(sym)>0){
        cout << "\n" << sym << " already Exists!"<<endl;
        return;
    }

        mp.insert(pair <string,string> (sym,t_sym));

        ascii=hashcode(sym);
        index =ascii % n;
        node* ptr = new node();
        ptr->symbol=sym;
	    ptr->typeSymbol=t_sym;
	    ptr->next = NULL;

	    ptr->next=arr[index];
	    arr[index]=ptr;

     cout<<sym<<" "<<t_sym<<"  successfully inserted into the linked list."<<endl;

}

void display(){
    cout<<"elements are:"<<endl;

	for (i = 0; i < n; i++){
		if (arr[i]== NULL){
			cout<<i<<" "<<"-> has no elements"<<endl;
			continue;
			}
        else
         {
			cout<<i<<" "<<"-> ";
			node* temp = arr[i];
			while (temp != NULL){
				cout<<temp->symbol<<" "<<temp->typeSymbol<<" ";
				temp = temp->next;
			}
			cout<<endl;

		}
	}
}


int main(){
        cout<<"Enter Size of Array: ";
        cin >> n;

        for(i = 0; i < n; i++){
        arr[i] = NULL;
        }

	    int choice;
        while(1){
        cout<<"\nselect an option:"<<endl;
        cout<<"1-insert"<<endl;
        cout<<"2-display"<<endl;
        cout<<"3-exit"<<endl;

        cout<<"enter your choice:";
        cin>>choice;
        switch(choice){

        case 1:
            {
             cout<<"enter the element to be inserted into the linked list:";
             insert();
             break;
            }

		case 2:
		    {
			 display();
			 break;
			}

	    case 3:
		    {
			  break;
			}

		default:
		    {
		      cout<<"\nIncorrect choice.Please try again."<<endl;
			  break;
		    }

        }
    }

}
