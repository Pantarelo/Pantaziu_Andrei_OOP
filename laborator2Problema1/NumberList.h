class NumberList
{
    int count;
    int *numbers = new int[1];
    public:
        void Init();
        bool Add(int x);
        
        void Sort();
        void Print();
};