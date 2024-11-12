#include<bits/stdc++.h>
using namespace std;

    int a[100];
    int top = -1;

    void push(int n){
        if(top >= 99){
            cout<<"overflow";
        }
        else{
            a[++top] = n;
            cout<<n<<endl;
        }
    }

    void pop() {
        if(top < 0){
            cout<<"Underflow"<<endl;
        }
        else{
            cout<<a[top--]<<endl;

        }
    }

    void display() {
        if(top<0) {
            cout<<"empty"<<endl;
        }
        else {
            cout<<"Elements:"<<endl;
            for(int i=0; i<=top; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }

    int main()
    {
       int cl, n;
       while(true){
        cout<<"\nMenu: \n";
        cout<<"1. Push \n";
        cout<<"2. Pop \n";
        cout<<"3. Display \n";
        cout<<"4. Exit \n";
        cout<<"Enter number:";
        cin>>cl;


        switch (cl){
        case 1:
            cout<<"Enter a number: ";
            cin>> n;
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout<<"Exit";
            return 0;
        }

       }

    }


