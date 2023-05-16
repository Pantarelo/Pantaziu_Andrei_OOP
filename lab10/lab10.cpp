#pragma once
class Compare{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator{
private:
	T** List;
    int sizeOfList;
    int currentIndex;
public:
	ArrayIterator(const T** list, int size, int index);
	ArrayIterator& operator++();
	ArrayIterator& operator--();
	bool operator= (ArrayIterator<T> &);
	bool operator!=(ArrayIterator<T> &);
    T* operator*();
};

template<class T>
ArrayIterator<T>::ArrayIterator(const T** list, int size, int index){
    List = list;
    sizeOfList = size;
    currentIndex = index;
}
template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator++(){
    if(currentIndex < sizeOfList)
        currentIndex++;
    else
        throw "Index out of range";
    List++;
    return *this;
}
template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator--(){
    if(currentIndex > 0)
        currentIndex--;
    else
        throw "Index out of range";
    List--;
    return *this;
}
template<class T>
bool ArrayIterator<T>::operator= (ArrayIterator<T> &other){
    List = other.List;
    sizeOfList = other.sizeOfList;
    if(currentIndex >= sizeOfList || currentIndex < 0)
        throw "Index out of range";
    currentIndex = other.currentIndex;
    return true;
}
template<class T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T> &other){
    return currentIndex != other.currentIndex;
}
template<class T>
T* ArrayIterator<T>::operator*(){
    return *List;
}

template<class T>
class Array{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	Array(); // Lista nu e alocata, Capacity si Size = 0
	~Array(); // destructor
	Array(int capacity); // Lista e alocata cu 'capacity' elemente
	Array(const Array<T> &otherArray); // constructor de copiere
	T& operator[] (int index); // arunca exceptie daca index este out of range
	const Array<T>& operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	bool operator=(const Array<T> &otherArray);
	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator
	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator
	int GetSize(); 
	int GetCapacity();
	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
};

template<class T>
T& Array<T>::operator[] (int index){
    if(index < 0 || index >= Size)
        throw "Index out of range";
    return *List[index];
}

template<class T>
const Array<T>& Array<T>::operator+=(const T &newElem){
    if(Size == Capacity){
        Capacity *= 2;
        T** newList = new T*[Capacity];
        for(int i = 0; i < Size; i++)
            newList[i] = List[i];
        delete[] List;
        List = newList;
    }
    List[Size] = new T(newElem);
    Size++;
    return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T &newElem){
    if(index < 0 || index > Size)
        throw "Index out of range";
    if(Size == Capacity){
        Capacity *= 2;
        T** newList = new T*[Capacity];
        for(int i = 0; i < Size; i++)
            newList[i] = List[i];
        delete[] List;
        List = newList;
    }
    for(int i = Size; i > index; i--)
        List[i] = List[i - 1];
    List[index] = new T(newElem);
    Size++;
    return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray){
    if(index < 0 || index > Size)
        throw "Index out of range";
    if(Size + otherArray.Size > Capacity){
        Capacity = Size + otherArray.Size;
        T** newList = new T*[Capacity];
        for(int i = 0; i < Size; i++)
            newList[i] = List[i];
        delete[] List;
        List = newList;
    }
    for(int i = Size + otherArray.Size - 1; i >= index + otherArray.Size; i--)
        List[i] = List[i - otherArray.Size];
    for(int i = index; i < index + otherArray.Size; i++)
        List[i] = new T(*otherArray.List[i - index]);
    Size += otherArray.Size;
    return *this;
}

template<class T>
const Array<T>& Array<T>::Delete(int index){
    if(index < 0 || index >= Size)
        throw "Index out of range";
    delete List[index];
    for(int i = index; i < Size - 1; i++)
        List[i] = List[i + 1];
    Size--;
    return *this;
}

template<class T>
bool Array<T>::operator=(const Array<T> &otherArray){
    if(this == &otherArray)
        return false;
    for(int i = 0; i < Size; i++)
        delete List[i];
    delete[] List;
    Capacity = otherArray.Capacity;
    Size = otherArray.Size;
    List = new T*[Capacity];
    for(int i = 0; i < Size; i++)
        List[i] = otherArray.List[i];
    return true;
}

template<class T>
void Array<T>::Sort(){
    for(int i = 0; i < Size - 1; i++)
        for(int j = i + 1; j < Size; j++)
            if(*List[i] > *List[j]){
                T* aux = List[i];
                List[i] = List[j];
                List[j] = aux;
            }
}
template<class T>
void Array<T>::Sort(int(*compare)(const T&, const T&)){
    for(int i = 0; i < Size - 1; i++)
        for(int j = i + 1; j < Size; j++)
            if(compare(*List[i], *List[j]) > 0){
                T* aux = List[i];
                List[i] = List[j];
                List[j] = aux;
            }
}

template<class T>
void Array<T>::Sort(Compare *comparator){
    for(int i = 0; i < Size - 1; i++)
        for(int j = i + 1; j < Size; j++)
            if(comparator->CompareElements(*List[i], *List[j]) > 0){
                T* aux = List[i];
                List[i] = List[j];
                List[j] = aux;
            }
}