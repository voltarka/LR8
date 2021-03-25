#include <iostream>
using namespace std;

struct ctzn {
    std::string fio; // snp
    char gender;
    int age;
};



template <typename T>

bool operator!=(T first, T second) {
    if(first.fio == second.fio) {
        if ((first.gender == second.gender) && (first.age == second.age));
    }
}

template <typename T>
struct Node
{
    T information;
    Node* next = nullptr;
    Node* previous = nullptr;
};

template <typename T>
struct Circle
{
    Node<T>* begin;
    Node<T>* end;
    unsigned int size;
};

template <typename T>
void constructor (Circle<T>& circle) {
    circle.begin = nullptr;
    circle.end = nullptr;
    circle.size = 0;
}

template <typename T>
void destructor (Circle<T>& circle) { // очистка памяти
    while (circle.size != 0) {
        Node<T>* node = circle.begin -> next;
        delete circle.begin;
        circle.begin = node;
        circle.size --;
    }
    std::cout << "Memory is cleared, job is done." << std::endl;
}

template <typename T>
unsigned int size (Circle<T>& circle) {
    int size = circle.size;
    return size;
}

template <typename T>
void push_begin (Circle<T>& circle, T information) {
    circle.size ++;
    auto element = new Node<T>;
    element->information = information; // создаем и инициализируем новый элемент (выделяем память)
    if (circle.begin == nullptr) { // если мы таким образом вставляем в список первый элемент, то нужно
        circle.begin = element;       // связать его с самим собой, так как у нас кольцевой список
        circle.end = element;
        element->next = element;
        element->previous = element;
    }
    else {
        element->next = circle.begin;
        circle.begin->previous = element; // перепривязываем первый элемент к новому (он предыдущий)
        element->previous = circle.end;
        circle.end->next = element; // перепривязываем последний элемент к новому (он следующий)
        circle.begin = element;
    }

}

template <typename T>
void push_end (Circle<T>& circle, T information) {
    circle.size ++;
    auto element = new Node<T>;
    element->information = information;
    if (circle.begin == nullptr) {
        circle.end = element;
        circle.begin = element;
        element->next = element;
        element->previous = element;
    }
    else {
        circle.end->next = element;
        element->previous = circle.end;
        circle.begin->previous = element;
        element->next = circle.begin;
        circle.end = element;
    }
}

template <typename T>
void push_index (Circle<T>& circle, T information, int index) {
    int count = 0;
    if (index == 0)
        push_begin(circle, information);
    else if (index == circle.size)
        push_end(circle, information);
    else {
        Node<T>* additional = circle.begin;
        while (count != index - 1)
        {
            additional = additional -> next;
            count ++;
        }
        auto element = new Node<T>;
        element->information = information;
        element->previous = additional;
        additional->next->previous = element;
        element->next = additional->next;
        additional->next = element;
    }
            circle.size++;
}

template <typename T>
void push_pointer (Circle<T>& circle, T information, Node<T>* pointer) {
    circle.size++;
    auto element = new Node<T>;
    element->information = information;
    element->previous = pointer;             // связываем элемент с тем, на который был передан указатель
    element->next = pointer->next;           // связываем элемент со следующим
    element->previous->next = element;       // связываем предыдущий элемент с добавленным
    element->next->previous = element;       // связываем следующий элемент с добавленным
}

template <typename T>
T pop_begin (Circle<T>& circle) {
    if (circle.size == 0) {
        cout << "Circle is empty" << endl;
        T exit;
        return exit;
    }
    circle.size --;
    Node<T>* used = circle.begin;
    T popped = circle.begin -> information;
    circle.begin->next->previous = circle.end;
    circle.end->next = circle.begin->next;
    circle.begin = circle.begin->next;
    delete used;
    return popped;
}

template <typename T>
T pop_end (Circle<T>& circle) {
    if (circle.size == 0) {
        cout << "Circle is empty" << endl;
        T exit;
        return exit;
    }
    circle.size --;
    Node<T>* used = circle.end;
    T popped = circle.end -> information;
    circle.end->previous->next = circle.begin;
    circle.begin->previous = circle.end->previous;
    circle.end = circle.end->previous;
    delete used;
    return popped;
}

template <typename T>
T pop_index (Circle<T>& circle, int index) {
    if (circle.size == 0) {
        cout << "Circle is empty" << endl;
        T exit;
        return exit;
    }
    if (index == 0)
        pop_begin (circle);
    else if (index == circle.size)
        pop_end (circle);
    else {
        unsigned int counter = 0;
        Node<T>* element = circle.begin;
        while (counter != index)
        {
            element = element->next;
            counter++;
        }
        element->previous->next = element->next;
        element->next->previous = element->previous;
        T used = element->information;
        circle.size--;
        delete element;
        return used;
    }
}

template <typename T>
T pop_pointer (Circle<T>& circle, Node<T>* pointer) {
    if (circle.size == 0) {
        cout << "Circle is empty" << endl;
        T exit;
        return exit;
    }
    circle.size --;
    Node<T>* element = circle.begin;
    while (element != pointer)
        element = element->next;
    element->next->previous = element->previous;
    element->previous->next = element->next;
    T used = element->information;
    delete element;
    return used;
}

template <typename T>
T value_from_index(Circle<T>& circle, int index) {
    int count = 0;
    Node<T>* element = circle.begin;
    while (count != index)
    {
        element = element->next;
        count++;
    }
    T information = element->information;
    return information;
}

template <typename T>
int find(Circle<T>& circle, T value) {
    int index = 0;
    Node<T>* element = circle.begin;
     while (element -> information != value) {
        index++;
        element = element -> next;
         if (index == circle.size)
             return -1;
    }
    return index;
}

template <typename T>
void print (Circle<T>& circle) {
    Node<T>* element = circle.begin;

    do
    {
        std::cout << element->information << ' ' ;
        element = element->next;
    } while (element != circle.begin);
    std::cout << std::endl;
}

std::ostream& operator << (std::ostream& output,const ctzn& citizen) {
    output << "Full name: " << citizen.fio << "\nGender: " << citizen.gender << "\nAge: "<< citizen.age <<std::endl << std::endl;
    return output;
}
int main() {
    Circle<int> circle;
    constructor (circle);
    for (int i = 0; i < 10; i++) {
        push_begin (circle, i);
    }

    std::cout << "Elements are: ";
    print (circle);
    std::cout << "Size of circle is: " << size (circle) << std::endl;

    std::cout << "Circle with pushed element 4 on the fifth place: ";
    push_index(circle, 4, 5);
    print(circle);

    Node<int>* node = circle.end->next;
    std::cout << "Circle with pushed element 3 using pointer at the first element: ";
    push_pointer(circle,3,node);
    print(circle);
    std::cout << "Size of circle is: " << size (circle) << std::endl;

    std::cout << endl;
    cout << "Popped element from the beginning is: " << pop_begin(circle) << endl;
    print(circle);
    cout << endl;

    cout << "Popped  element from the end is: "<< pop_end(circle) << endl;
    print(circle);
    cout << endl;

    std::cout << "Popped element from index 7: " << pop_index(circle, 7) << endl;
    print(circle);
    cout << endl;

    Node<int>* pointer = circle.begin->previous;
    std::cout << "Popped element using pointer at the last element: " << pop_pointer(circle,pointer) << endl;
    print(circle);
    cout << endl;

    std::cout << "Value from index 2: ";
    std::cout << value_from_index(circle,2);
    std::cout << std::endl;


    int k = find(circle, 9);
    if (k == -1) {
        cout << "There is no element that u've chosen"<< endl;
    }
    std::cout << "Index when we meet 6 at the first time: ";
    std::cout << find(circle, 6);
    std::cout << std::endl;

    destructor(circle);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Now let's do the same but with the structure Citizen"<< std::endl;

    ctzn ctzn1 = {"Voloshchenko Ivan Sergeevich",'m', 18};
    ctzn ctzn2 = {"Shapovalov Alexey Dmitrievich",'f', 24};
    ctzn ctzn3 = { "Kashapov Albert Ildarovich",'m', 19};
    ctzn ctzn4 = {"Milchenko Ivan Dmitrievich", 'm', 18};
    ctzn ctzn5 = {"Kolesnik Daniil Daniilovich",'m', 20};
    ctzn ctzn6 = {"Nikiforov Zakhar Alexeevich",'m',18};
    ctzn ctzn7 = {"Khartulyari Gog Dmitrievich",'m', 18};

    Circle<ctzn> circle1;
    constructor (circle1);

    push_begin(circle1, ctzn1);
    push_begin(circle1, ctzn2);
    push_begin(circle1, ctzn7);
    std::cout << "Circle of citizens: ";
    std::cout << std::endl;
    print(circle1);

    push_end(circle1, ctzn2);
    std::cout << "Circle with pushed person to the end: " << std::endl;
    print(circle1);

    push_index(circle1, ctzn3,2);
    std::cout << "Circle with pushed person to index 2: " << std::endl;
    print(circle1);

    Node<ctzn>* people = circle1.end->next->next;
    std::cout << "Circle with pushed person number 4 using pointer at the second element: " << std::endl;
    push_pointer(circle1,ctzn4,people);
    print(circle1);

    std::cout << "Size of circle: " << size(circle1) << std::endl;

    pop_begin(circle1);
    std::cout << "Popped person from the beginning: " << std::endl;
    print(circle1);
    cout << endl;

    std::cout << "Popped person from the end"<< pop_end(circle1) <<std::endl;
    print(circle1);
    cout << endl;

    std::cout << "Popped person with index 2:" <<pop_index(circle1, 2) << std::endl;
    print(circle1);
    cout << endl;

    Node<ctzn>* person = circle1.begin->previous;
    std::cout << "Popped person using pointer at the last element: "<<pop_pointer(circle1,person) << std::endl;
    print(circle1);
    cout << endl;

    std::cout << "Person from index 1" << std::endl;
    std::cout << value_from_index(circle1, 1);

    push_begin(circle1, ctzn1);
    push_begin(circle1, ctzn3);
    push_begin(circle1, ctzn7);
    push_begin(circle1, ctzn5);
    push_begin(circle1, ctzn6);
    push_begin(circle1, ctzn7);
    std::cout << "At what position can we meet Voloshchenko Ivan: "<< std::endl;
    int a = find (circle1, ctzn7);
    if (a == -1)
        cout << "There is no person that u've chosen" << endl;
    std::cout << find (circle1, ctzn1);
    return 0;
}
