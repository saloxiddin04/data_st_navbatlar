//
//  main.cpp
//  navbatlar
//
//  Created by Saloxiddin Sayfuddinov on 24/09/24.
//

#include <iostream>

using namespace std;

#define MAXSIZE 10

class Queue {
private:
    int items[MAXSIZE];
    int front, rear;
    
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return rear == MAXSIZE - 1;
    }
    
    void enqueue(int value) {
        if (isFull()) {
            cout<<"Array is full \n"<<endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            items[rear] = value;
            cout<<value<<" muvofaqqiyatli qo'shildi \n";
        }
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout<<"Array bo'sh \n";
        } else {
            cout<<items[front]<<" muvofaqqiyatli o'chirildi \n";
            front++;
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
    }
    
    void peek() {
        if (isEmpty()) {
            cout<<"Array bo'sh \n";
        } else {
            cout<<"Front: "<<items[front]<<endl;
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Array bo'sh" << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = rear; i >= front; i--) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
    
    void dequeueByIndex(int index) {
            if (isEmpty()) {
                cout << "Array bo'sh \n";
            } else if (index < front || index > rear) {
                cout << "Noto'g'ri index \n";
            } else {
                cout << items[index] << " muvofaqqiyatli o'chirildi \n";
                for (int i = index; i < rear; i++) {
                    items[i] = items[i + 1];
                }
                rear--;
                if (front > rear) {
                    front = -1;
                    rear = -1;
                }
            }
        }

};

using namespace std;

int main() {
    int a;
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    cout<<"index kiriting: "; cin>>a;
    
    q.dequeueByIndex(a);
    
    q.peek();
    
    q.display();
    return 0;
}
