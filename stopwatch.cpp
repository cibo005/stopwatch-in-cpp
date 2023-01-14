#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#define KB_ENTER 10
#define KB_SPACE 32
#define KB_BACKSPACE 8
#define KB_ESC 27

using namespace std;

class Stopwatch
{
    int milli;
    int sec;
    int min;
    bool state;
    
    public:
        Stopwatch()
        {
            milli=0;
            sec=0;
            min=0;
            state=false;
        }
        void start()
        {
        state = true;
        
        while(state)    
            while(min < 60)
            {
                while(sec < 60)
                    {
                    while(milli < 100)
                        {
                            //printf("%d:%d,%d",min,sec,milli++);
                            cout<<"\r"<<setw(2)<<setfill('0')<<min<<":"<<setw(2)<<setfill('0')<<sec<<","<<setw(2)<<setfill('0')<<milli++<<flush;
                            this_thread::sleep_for(chrono::milliseconds(10)); 
                        }
                    milli=0;
                    
                    sec++;
                            
                    }
                 
                sec=0;
                
                min++;
                            
            }    
        }
        
        void stop()
        {
            state=false;
        }
        void reset()
        {
            milli=0;
            sec=0;
            min=0;
            state=false;
            
            cout<<"\r"<<setw(2)<<setfill('0')<<min<<":"<<setw(2)<<setfill('0')<<sec<<","<<setw(2)<<setfill('0')<<milli++<<flush;
        }
};

int main()
{
    Stopwatch st;
    char kb;
    
    cout<<"Press enter to start counting, space to stop it and backspace to reset it."<<endl;
    
    do
        {
        cin>>kb;
        
        switch(kb)
            {
            case KB_ENTER: st.start(); break;
            case KB_SPACE: st.stop(); break;
            case KB_BACKSPACE: st.reset(); break;
            }
        } 
    while (kb != KB_ESC);
    return 0;
}