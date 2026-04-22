#ifndef DEQUE_H
#define DEQUE_H

#include<iostream>
using namespace std;

template <typename T>
class MyDeque {
private:
    int mLength=0;
    struct Node{
        T mData;
        struct Node * mPrev;
        struct Node * mNext;
    };

    struct Node * mFront;
    struct Node * mRear;

public:
    MyDeque();
    MyDeque(int sizeParm,T valueparm);
    ~MyDeque();
    bool isEmpty();
    void clear();
    void display();
    void pushFront(T vlaueParm);
    void pushBack(T vlaueParm);
    bool popFront();
    bool popRear();
    T firstElement();
    T lastElement();
    T getNthElement(int nthElementParm);
    void resize(T dataParm, int newSizeParm, int directionParm);
    int getSize();
    // Node* getNode(int indexParm);
    // T& operator[](int indexParm);
    // void removeAt(int indexParm);
    // void insertAt(int indexParm, T valParm);
    //Operator Overloading
    // template<typename T>
    Node* getNode(int indexParm) {
        if (indexParm < 0 || indexParm >= mLength) return nullptr;

        Node* sTemp = mFront;
        for (int i = 0; i < indexParm; i++) {
            sTemp = sTemp->mNext;
        }
        return sTemp;
    }
    // template<typename T>
    T& operator[](int indexParm) {
        return getNode(indexParm)->mData;
    }
    // template<typename T>
    void insertAt(int indexParm, T valParm) {
        if (indexParm < 0 || indexParm > mLength) return;
        Node* sNewnode = new Node{valParm, nullptr, nullptr};

        if (mLength == 0) {
            mFront = mRear = sNewnode;
        }
        else if (indexParm == 0) {
            sNewnode->mNext = mFront;
            mFront->mPrev = sNewnode;
            mFront = sNewnode;
        }
        else if (indexParm == mLength) {
            sNewnode->mPrev = mRear;
            mRear->mNext = sNewnode;
            mRear = sNewnode;
        }
        else {
            Node* sCurr = getNode(indexParm);
            sNewnode->mPrev = sCurr->mPrev;
            sNewnode->mNext = sCurr;

            sCurr->mPrev->mNext = sNewnode;
            sCurr->mPrev = sNewnode;
        }

        mLength++;
    }
    // template<typename T>
    void removeAt(int indexParm) {
        if (indexParm < 0 || indexParm >= mLength) return;

        Node* sTemp = getNode(indexParm);

        if (mLength == 1) {
            mFront = mRear = nullptr;
        }
        else if (indexParm == 0) {
            mFront = mFront->mNext;
            mFront->mPrev = nullptr;
        }
        else if (indexParm == mLength - 1) {
            mRear = mRear->mPrev;
            mRear->mNext = nullptr;
        }
        else {
            sTemp->mPrev->mNext = sTemp->mNext;
            sTemp->mNext->mPrev = sTemp->mPrev;
        }

        delete sTemp;
        mLength--;
    }


};
// To create an empty dequqe 
template<typename T>
MyDeque<T>::MyDeque():mFront(nullptr),mRear(nullptr){
}

// To create deque with size "n"  and Default values 
template<typename T>
MyDeque<T>::MyDeque(int sizeParm,T valueparm):mFront(nullptr),mRear(nullptr){
    for(int i = 0;i < sizeParm; i++){
        pushFront(valueparm);
    }
}

// Deconstructor
template<typename T>
MyDeque<T>::~MyDeque(){
    clear();
}
// To check if deque is EMPTY 
template<typename T>
bool MyDeque<T>::isEmpty(){
    return mFront==nullptr;
}
// To CLEAR the Deque
template<typename T>
void MyDeque<T>::clear(){
    while(mFront != nullptr){
        struct Node * sTemp = mFront;
        mFront = mFront ->mNext;
        delete sTemp;
    }
    mRear = nullptr;
    mLength = 0;
}

// To DISPLAY the elements in the Deque
template<typename T>
void MyDeque<T>::display(){
    if(isEmpty()){
        cout<<"Deque is Empty\n"<<endl;
    }
    struct Node * sTemp = mFront;
    while(sTemp != nullptr){
        cout<<"["<< sTemp -> mData <<"]";
        sTemp = sTemp -> mNext;

    }
    cout<<endl;
}

//To ADD element in FRONT
template<typename T>
void MyDeque<T>::pushFront(T vlaueParm){
    struct Node * sNewnode = new Node;
    sNewnode -> mData = vlaueParm;
    sNewnode ->mPrev = nullptr;
    sNewnode ->mNext = mFront;        
    if(isEmpty()){
        mFront = mRear = sNewnode;
    }
    else{
        mFront -> mPrev = sNewnode;
        mFront = sNewnode;
    }
    mLength++;
    
}
// To ADD element from REAR
template<typename T>
void MyDeque<T>::pushBack(T valueParm){
    struct Node * sNewnode = new Node;
    sNewnode -> mData = valueParm;
    sNewnode -> mNext = nullptr;
    if(isEmpty()){
        mFront = mRear = sNewnode;
    }
    else{
        mRear -> mNext = sNewnode;
        mRear = sNewnode;
    }
    mLength++;
    cout<<"Added to queue Successfully\n";
}

//To Remove Element from Front 
template<typename T>
bool MyDeque<T>::popFront(){
    if(isEmpty()){
        cout<<"Deque is Empty\n"<<endl;
        return false;
    }
    else{
        struct Node * sTemp = mFront;
        if(mFront ->mNext == nullptr){
            mFront =nullptr;
            mRear = nullptr;
        }
        else{
            mFront = mFront ->mNext;
            mFront -> mPrev = nullptr;
        }

        delete sTemp;
    }
    mLength--;
    return true;
}
//To Remove Element from Rear 
template<typename T>
bool MyDeque<T>::popRear(){
    if(isEmpty()){
        cout<<"Deque is Empty\n"<<endl;
        return false;
    }
    struct Node * sTemp = mRear;
    if(mRear -> mPrev == nullptr){
        mFront = nullptr;
        mRear = nullptr;
    }
    else{
        mRear = mRear ->mPrev;
        mRear->mNext = nullptr;
    }

    delete sTemp;
    mLength--;
    return true;
}
// To get the Front Element
template<typename T>
T MyDeque<T>::firstElement(){
    if(isEmpty()){
        cout<<"Deque is Empty\n"<<endl;
        return T{};
    }
    return mFront->mData;

}
// To get the Last Element 
template<typename T>
T MyDeque<T>::lastElement(){
    if(isEmpty()){
        cout<<"Deque is Empty\n"<<endl;
        return T{};
    }
    return mRear->mData;
}
// To get nth element 
template<typename T>
T MyDeque<T>::getNthElement(int nthElementParm){
    struct Node *sTemp = mFront;
    for (int i = 0; i<nthElementParm ;i++){
        sTemp = sTemp ->mNext;
    }
    return sTemp->mData;
}
// Resize the Deque in direction
template<typename T>
void MyDeque<T>::resize(T dataParm, int newSizeParm, int directionParm){
    if (newSizeParm > mLength){
        int sDiff = newSizeParm - mLength;
        if (directionParm == 1){
            for (int i = 0; i < sDiff; i++){
                pushBack(dataParm);
            }
        }
        else if (directionParm == -1){
            for (int i = 0; i < sDiff; i++){
                pushFront(dataParm);
            }
        }
        else{
            cout<<"Please select direction 1 or -1"<<endl;
            return;
        }
    }
    else if (mLength > newSizeParm){
        int sDiff = mLength - newSizeParm;
        if (directionParm == 1){
            for (int i = 0; i < sDiff; i++){
                popRear();
            }
        }
        else if (directionParm == -1){
            for (int i = 0; i < sDiff; i++){
                popFront();
            }
        }
        else{
            cout<<"Please select direction 1 or -1"<<endl;
            return;
        }
    }
}
// Get the size of deque
template<typename T>
int MyDeque<T>::getSize(){
    return mLength ;
}

#endif
