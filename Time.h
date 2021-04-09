class Time {
    private:
        int h, m, s;
        void normalize();

    public:
        int getTotalSeconds();
        void set_time(int hh=0, int mm=0, int ss=0);
        void display();
        void add_min(int mm);
        Time operator+(Time a);
        Time operator-(Time a);
        void operator+=(Time a);
        void operator-=(Time a);
        void operator++();
        void operator--();
};

Time createTimeFromSeconds(int seconds) {
    Time t;
    t.set_time(seconds / 3600, (seconds / 60) % 60, seconds % 60);
    return t;
}

int Time::getTotalSeconds()
{
    return h*3600 + m*60 + s;
}

void Time::set_time(int hh, int mm, int ss) {
    int seconds = hh*3600 + mm*60 + ss;
    h = seconds / 3600;
    m = (seconds / 60) % 60;
    s = seconds % 60;
}

void Time::display() {
    cout<<setfill('0')<<setw(2)<<h<<":";
    cout<<setfill('0')<<setw(2)<<m<<":";
    cout<<setfill('0')<<setw(2)<<s<<endl;
}

Time Time::operator+(Time a) {
    return createTimeFromSeconds(getTotalSeconds()+a.getTotalSeconds());
}
Time Time::operator-(Time a) {
    return createTimeFromSeconds(getTotalSeconds()-a.getTotalSeconds());
}
void Time::operator+=(Time a) {
    Time t = createTimeFromSeconds(getTotalSeconds()+a.getTotalSeconds());
    set_time(t.h, t.m, t.s);
}
void Time::operator-=(Time a) {
    Time t = createTimeFromSeconds(getTotalSeconds()-a.getTotalSeconds());
    set_time(t.h, t.m, t.s);
}
void Time::operator++() {
    Time t = createTimeFromSeconds(getTotalSeconds()+1);
    set_time(t.h, t.m, t.s);
}
void Time::operator--() {
    Time t = createTimeFromSeconds(getTotalSeconds()-1);
    set_time(t.h, t.m, t.s);
}

void Time::add_min(int mm) {
    Time t = createTimeFromSeconds(getTotalSeconds()+(60*mm));
    set_time(t.h, t.m, t.s);
}


void getTime(Time &t)
{
    int hh, mm, ss;
    cout<<"\n  Hour  : "; cin>>hh;
    cout<<"  Minute: "; cin>>mm;
    cout<<"  Second: "; cin>>ss;
    t.set_time(hh, mm, ss);
};
