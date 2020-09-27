#include <iostream>

using namespace std;
int main()
{
    int *q = new int;                                   /// new int pointer
    if(!q)                                              /// if null
        cout<<"no memory allocated";
    else                                                /// if allocated
    {
        cin>>*q;										/// reads the value
        if(*q>0)
        {
            int *v = new int[4];                        /// new array of 4 ints
            for(int i=0; i<sizeof(v); i++)              /// set each element: v[i] = *(v+i)
                *(v+i) = i+1;
            for(int i=0; i<4; i++)
                cout<<v[i]<<" ";
            delete[] v;                                 /// deallocate memory
        }
        else
        {
            int **a = new int*[2];                      ///new "row" array
            for(int i=0; i<2; i++)
                *(a+i) = new int[2];                    /// for each "row", add a "column" array
            for(int i=0; i<4; i++)
                *(*(a+i/2)+i%2) = i;                    /// set each element: a[i][j] = *(*(a+i/r)+i%c)
            for(int i=0; i<4; i++)
                cout<<*(*(a+i/2)+i%2)<<(i%2==0 ? " " : "\n");
            for(int i=0; i<2; i++)
                delete[] *(a+i);                        /// deallocate each "column" array
            delete[] a;                                 /// deallocate the "row" array
        }
    }
    return 0;
}
