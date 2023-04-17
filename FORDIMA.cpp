#include <iostream>

using namespace std;

//Cоздаём класс лист с шаблоном для разных типов данных
template <typename T>
class List{
public: 
    //Прототипы конструктора и деструктура
    List();
    ~List();
    
    //Прототип метода push_back
    //Позволяет добавить элемент в конец списка
    void push_back(T data);
    
    //Реализуем получение Size через гетр GetSize, так как это инкапсуляция.
    //Метод GetSize не выносим за пределы класса, так как он маленький.
    int GetSize() {
        return Size;
    }

    //Прототип метода pop_front
    //Позволяет удалить первый элемент списка
    void pop_front();
    
    //Прототип метода clear
    //Позволяет очистить список
    void clear();

    //Прототип метода push_front
    //Позволяет добавить элемент в начало списка.
    void push_front(T data);

    //Прототип метода insert
    //Позволяет вставить элемент в список.
    void insert(T value, int index);

    //Прототип метода removeAt
    //Позволяет удалить элемент по заданному индексу
    void remove(int index);
    
    //перегрузка оператора индексирования
    T& operator[](const int index);
private:
    //Создаём узел односвязного списка
    class Node{
    public:
        //Указатель pNext типа Node, который должен указывать на следующий элемент
        Node *pNext;
       
        //Данные, которые будут храниться в нашем узле списка
        T data;
        
        //Реализуем конструктор по умолчанию для класса Node и сразу же 
        //присваиваем T() и nullptr чтобы избежать мусора в памяти
        Node(T data = T(), Node* pNext =nullptr){
            
            //Присваиваем входящие данные соответствующим полям класса Node
            this->data = data;
            this->pNext = pNext;
        }
    };
    
    //Создаём указатель типа Node на начало списка
    Node *head;
    
    //Чтобы не считать каждый раз количество элементов списка, 
    //проходя по нему, создаём переменную, которая отвечает за размер нашего списка
    int Size;
};


template<typename T>
List<T>::List(){
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List(){
    clear();
}

template<typename T>
void List<T>::push_back(T data){
    
    //Если элементов в списке нет ( т.е. "голова" указывает вникуда), 
    //то мы создаём новый узел и присваем его адрес указателю (нашей "голове")
    if (head == nullptr){
        head = new Node(data);
    }
    
    //Если же элементы в списке есть, то мы создаём указатель типа Node, 
    //которому сразу же присваем значение головы
    else {
        Node *current = head;
        
        //Проходим по всему списку, пока не встретим элемент, 
        //который указывает вникуда, следовательно он последний
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        
        //присваем указателю Pnext указателя current адрес нового узла списка
        current->pNext = new Node(data);
    }
    
    //увеличиваем размер списка
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index){
    int counter = 0;
    
    //Создаём указатель current типа Node, который хранит адрес head
    Node *current = head;
    while(counter != index){
        
        //Присваиваем current адрес поля pNext
        current = current->pNext;
        counter++;
    }
    
    //Возвращаем данные current
    return current->data;
}

template<typename T>
void List<T>::pop_front(){
    
    //Cоздаём временный указатель на адрес "головы" cписка
    Node *temp = head;
    
    //присваиваем голове адрес на следующий элемент
    head = head->pNext;
    
    //удаляем temp, так как он хранит адрес бывшего первого элемента списка
    delete temp;
    
    //уменьшаем Size, так как размер списка уменьшается
    Size--;
}

template<typename T>
void List<T>::clear(){
    
    //Пока Size больше нуля, мы удаляем каждый элемент списка. 
    //Size изменяется в методе pop_front
    while(Size > 0){
        pop_front();
    }
}

template <typename T>
void List<T>::push_front(T data){
    //Мы создаём новый узел current и присваиваем туда входящие значения
    Node *current = new Node(data);
    
    //Создаём временный указатель temp, чтобы сохранить "голову"
    //Важно, что когда мы присваиваем head, то нам не надо присваивать
    //отдельно данные (например temp->data = head->data). 
    Node *temp = head;
    
    //Теперь мы нашей "голове" говорим, что она будет current
    head = current;
    
    //Ну а также мы "голове" говорим указывать на следующий элемент
    head->pNext = temp;
    
    //Так как мы сохранили current в head, нам больше не нужен current
    delete current;
    
    //Так как список увеличился на один элемент, увеличиваем его размер соответственно
    Size++;
}

template <typename T>
void List<T>::insert(T value, int index){
    if (index == 0){
        push_front(value);
    }
    else {
        int counter = 0;
        //Новый узел, который мы хатим вставить
        Node *newNode = new Node(value);

        //Указатель на "голову" списка
        Node *prev = head;
        
        //Ищем узел, предшествующий узлу с индексом index. 
        //В условии index-1, так как нам нужен именно указатель на предыдущий элемент.
        //Мы с самого начала инициализируем prev и говорим указывать на head.
        //Если бы проверка была до index, то в последней итерации цикла мы бы присвоили
        //prev указатель на элемент с индексом index, а не предыдущий.  
        while(counter < index - 1){
            prev = prev->pNext; 
            counter++;
        }
        
        //Присваиваем указателю нашего узла, который мы хотим вставить, указатель 
        //элемента, который находился перед элементом замены 
        newNode->pNext = prev->pNext; 

        //Указателю элемента, который находился перед элементом замены,
        //присваиваем значение узла, который надо вставить. 
        prev->pNext = newNode;
        
        //Увеличиваем размер списка
        Size++;
    }
}

template <typename T>
void List<T>::remove(int index){
    if (index == 0){
        pop_front();
    }
    else {
        int counter = 0;
        Node *prev = head;
        while(counter < index - 1){
            prev = prev->pNext;
            counter++;
        }
        Node *toDelete = prev->pNext;
        prev->pNext = toDelete->pNext;
        delete toDelete;  
        Size--;
    }
}

int main(){
    List<int> st;
    st.push_back(10);
    st.push_back(20);
    st.push_back(35);
    cout << st.GetSize() << endl;
    cout << st[0] << endl;
    st.pop_front();
    cout << st[0] << endl;
    st.clear();
    cout << st.GetSize() << endl;
    st.push_back(5);
    st.push_back(25);
    cout << "Method push_front: " << endl;
    st.push_front(30);
    cout << st[0] << " ";
    cout << st[1] << " ";
    cout << st[2] << " ";
    cout << endl;
    cout << endl;
    st.insert(10, 2);
    cout << st[2] << " -element st[2]"<< endl;
    cout << st[3] << " -element st[3]"<< endl;
    cout << st.GetSize();
    cout << endl;
    for (int i = 0; i < st.GetSize(); i++){
        cout << st[i] << " "; 
    }
    cout << endl;
    st.remove(2);
    for (int i = 0; i < st.GetSize(); i++){
        cout << st[i] << " "; 
    }
    return 0;
}