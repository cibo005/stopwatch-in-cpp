#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#define KB_s 115
#define KB_t 116
#define KB_r 114
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
        
        void run()
        {
        while(true)
            while(min < 60 && state)
            {
                while(sec < 60 && state)
                    {
                    while(milli < 100 && state)
                        {
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
        void start()
        {
            state = true;
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
    
    cout<<"Press s to start counting, t to stop it and r to reset it. Esc to exit."<<endl;

    char kb;
    
    Stopwatch st;
    
    thread w(&Stopwatch::run, ref(st));    

    do
        {

        cin>>kb;
        
        switch(kb)
            {
            case KB_s: st.start(); break;
            case KB_t: st.stop(); break;
            case KB_r: st.reset(); break;
            }
        } 
    while (kb != KB_ESC);
    
    return 0;
}
