#include <iostream>
#include <string>
using namespace std;

struct ctzn{
    std::string sn; // surname name
    char gender;
    int age;
    int operator = (int zero)
    {
        zero = 0;
        sn = "";
        age = 0;
        gender = 0;
        return zero;
    }
    bool operator ==(const ctzn& a) {
        return ((sn == a.sn) && (gender == a.gender) && (age == a.age));
    }
};

template <typename T, int size>

struct Line
{
    T array[size];
    int act_size = 0;
};

template <typename T, int size>

void constructor (Line<T,size>& line) {
    line.act_size = 0;
    for (auto i = 0; i < size; i++)
        line.array[i] = 0;
}

template <typename T, int size>

void destructor(Line<T,size>& line) {
    for (int i = 0; i < size; i++) {
        line.array[i] = 0;
    }
    cout << "Job is finished, memory is cleared." << endl;
}

template <typename T, int size>

int length (Line<T,size>& line) {
    cout << "Size of array is: ";
    return line.act_size;
}

template <typename T, int size>

void push_end (Line<T,size>& line, T element) {
    line.act_size++;
    if (line.act_size < size) {
        line.array[line.act_size - 1] = element;
    }
    else {
        cout << "Array is full" << endl;
        line.act_size--;
    }
}

template <typename T, int size>

void push_index (Line<T,size>& line, T element, int index) {
    line.act_size++;
    if (line.act_size < size) {
        for (auto i = line.act_size - 1; i >= index; i--) {
            line.array[i+1] = line.array[i];
        }
        line.array[index] = element;
    }
    else {
        cout << "Array is full" << endl;
        line.act_size--;
    }
}

template <typename T, int size>

T pop_begin (Line<T,size>& line) {
    T element = line.array[0];
    for (int i = 1; i < line.act_size; i++)
        line.array[i - 1] = line.array[i];
    line.act_size--;
    line.array[line.act_size] = 0;
    return element;
}

template <typename T, int size>

T pop_end (Line<T,size>& line) {
    T element = line.array[line.act_size - 1];
    line.act_size--;
    return element;
}

template <typename T, int size>

T pop_index (Line<T,size>& line, int index) {
    T element = line.array[index - 1];
    for (int i = index + 1; i < line.act_size; i++)
        line.array[i - 1] = line.array[i];
    line.act_size--;
    line.array[line.act_size] = 0;
}

template <typename T, int size>

T value_from_index (Line<T,size>& line, int index) {
    return line.array[index];
}

template <typename T, int size>

int find (Line<T,size>& line, T information) {
    for (int i = 0; i< line.act_size; i++) {
        if (line.array[i] == information)
            return i;
    }
}

template <typename T, int size>

void print (Line<T,size>& line) {
    cout << "The array is: ";
    if (line.act_size == 0 )
        cout << "There are no elements";
    else {
        for (auto i = 0; i < line.act_size; i++) {
            cout << line.array[i] << ' ';
        }
    }
}

ostream& operator << (ostream& output,const ctzn& citizen) {
    output << "Full name: " << citizen.sn << "\nGender: " << citizen.gender << "\nAge: "<< citizen.age <<std::endl << std::endl;
    return output;
}

int main() {
    Line<int, 10> line;
    constructor(line);

    push_end(line, 1);
    push_end(line, 2);
    push_end(line, 3);
    push_end(line, 4);
    push_end(line, 5);
    print(line);
    cout << endl;

    cout << length(line) << endl;

    push_index(line, 8,3);
    cout << "Array with pushed 8 to index 3: \n";
    print(line);
    cout << endl;

    cout << "Popped element from the beginning is: " << pop_begin(line);
    cout << endl;

    cout<< "Popped element from the end is: " << pop_end(line);
    cout << endl;

    print(line);
    cout << endl;

    push_end(line,7);
    push_end(line, 9);
    cout << "We'll add some numbers to make array look better: ";
    print(line);
    cout << endl;

    pop_index(line,3);
    cout << "Array with popped element from index 3: ";
    print(line);
    cout << endl;

    cout << "Value from index 4 is: " << value_from_index(line,4);
    cout << endl;

    cout << "Index of number 3 is: " << find(line, 3) << endl;

    destructor(line);
    cout << endl << endl;

    cout << "Now lets do the same but with people!" << endl;
    ctzn ctzn1 = {"Voloshchenko Ivan ", 'm', 18};
    ctzn ctzn2 = {"Shapovalov Alexey ",'f', 24};
    ctzn ctzn3 = {"Kashapov Albert ", 'm', 19};
    ctzn ctzn4 = {"Milchenko Ivan ", 'm', 18};
    ctzn ctzn5 = {"Kolesnik Daniil ", 'm', 20};
    ctzn ctzn6 = {"Nikiforov Zakhar ", 'm',18};
    ctzn ctzn7 = {"Khartulyari Gog ", 'm', 18};

    Line<ctzn,10> line1;
    constructor(line1);

    push_end(line1, ctzn1);
    push_end(line1, ctzn2);
    push_end(line1, ctzn3);
    print(line1);
    cout << endl;

    push_index(line1, ctzn4,2);
    cout << "Array with person pushed to index 2: " << endl;
    print (line1);
    cout<< endl;

    cout << "Popped person from the beginning: " << pop_begin(line1) << endl;
    cout << "Popped person from the end: " << pop_end(line1) << endl;

    push_end(line1,ctzn6);
    push_end(line1, ctzn7);
    cout << "We'll add some people to make array look better: ";
    print(line1);
    cout << endl;

    pop_index(line1,3);
    cout << "Array with popped person from index 3: ";
    print(line);
    cout << endl;

    cout << "Person from index 1: " << value_from_index(line1, 1) << endl;

    cout << "Index of person number 7 is: " << find(line1, ctzn7) << endl;

    return 0;
}
