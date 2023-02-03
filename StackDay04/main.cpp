
#include <iostream>

using namespace std;


class Stack
{
private:
    int*arr;
    int tos;
    int Size;
    static int counter;

public:
    Stack()
    {
        counter++;
        /// cout<<"cons"<<endl;
        tos=0;
        Size=5;
        arr=new int[Size];
    }
    Stack(  int _sizeofarr)
    {
        counter++;
        /// cout<<"cons"<<endl;
        tos=0;
        Size=_sizeofarr;
        arr = new int[Size];

    }

    ~Stack()
    {
        counter--;
        /// cout<<"deconstractor"<<endl;

        for(int i=0; i<Size; i++)
        {
            arr[i]=-1;
        }
        delete [] arr;
    }

    void push(int _value)
    {
        if(!isfull())
        {
            arr[tos]=_value;
            tos++;


        }
        else
        {
            cout<<"fully"<<endl;
        }
    }

    int pop()
    {
        if(isempty())
        {
            int res;
            tos--;
            res = arr[tos];
            return res;
        }
        else
        {

            return -222222222222222;
        }
    }


/// to make its easy to read code
    int isfull()
    {
        return tos==Size;
    };
    int isempty()
    {
        return tos ==0;
    };


/// to make printme access all private memebers we uses friend function
    friend void printme(Stack para);

//----------------------------------------------------------------------
    Stack( const Stack&old)    ///this is copy stack
    {
        this->tos=old.tos;
        this->Size = old.Size;
        this->arr = new int[Size];
        for(int i=0; i<tos; i++)
        {
            arr[i] = old.arr[i];
        }

    }


/// s1=s2
    Stack& operator =(const Stack& right)
    {

        delete[] this->arr;
        this->tos=right.tos;
        this->Size=right.Size;
        arr=new int[Size];
        for(int i=0; i<tos; i++)
        {
            this->arr[i]=right.arr[i];
        }

        return *this;
    }

/// reverse stack
    Stack ReverseStack()
    {
        Stack retval(Size);
        for(int i = tos-1 ; i>=0 ; i--)
        {
            retval.push(arr[i]);
        }

        return retval;
    }


    Stack operator + (const Stack& right)
    {
        Stack retval(this->Size+right.Size);
        retval.tos=this->tos+right.tos;

        for(int i=0; i<this->tos; i++)
        {
            retval.arr[i]=this->arr[i];
        }
        for(int i=0; i<right.tos; i++)
        {
            retval.arr[tos+i]=right.arr[i];
        }

        return retval;
    }


};

void printme(Stack para)
{
    for(int i=0; i<para.tos ; i++)
    {
        cout<<para.arr[i]<<endl;
    }
};

/// to initiate static counter

int Stack::counter=0;

int main()
{

    Stack s1(4),s2(3),s3,s4;
    s1.push(5);
    s1.push(6);
    s1.push(10);
    s1.push(11);
    s1.printme();
    cout<<"============="<<endl;


    cout<<"s2"<<endl;
    s2.push(8);
    s2.push(9);
    printme(s2);
    cout<<"============="<<endl;


    cout<<"s2=s1"<<endl;
    s2=s1;
    printme(s2);
    cout<<"============="<<endl;


    cout<<"reverse of s1"<<endl;

    s3 = s1.ReverseStack();

    printme(s3);
    cout<<"============="<<endl;

    s4=s1+s2;
    printme(s4);

    return 0;
}
